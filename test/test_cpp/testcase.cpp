#include "testcase.h"
#include "databaseengine.h"
#include "user.h"

#include <QtTest>
#include <QDebug>
#include <QDir>
#include <QVector>

#include "serializer.h"
#include "message.h"
#include "uuidmanager.h"

static const QString TEST_MESSAGE_FILE_PATH = QString(PRO_FILE_PWD) + "/test_messages.json";
static const QString TEST_USER_FILE_PATH = QString(PRO_FILE_PWD) + "/test_user.json";

TestCase::TestCase()
{
    qDebug() << "TestCase()";
}

TestCase::~TestCase()
{

}

void TestCase::checkDatabase_test()
{
    User ivan("1234", "ivan"), emptyUser, dima, vlad;
    dima.id = "5678";
    vlad.name = "vlad";
    QCOMPARE(ivan.isValid(), true);
    QCOMPARE(emptyUser.isValid(), false);
    QCOMPARE(dima.isValid(), false);
    QCOMPARE(vlad.isValid(), false);
    QList<User> userList;
    userList << ivan << emptyUser << dima << vlad;
    DatabaseEngine database;
    for (auto user : userList) {
        database.openDatabase(user);
        QString databaseLocation = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) +
                "/Database/" + user.id + ".db";
        if (user.isValid()) {
            if (QFile::exists(databaseLocation)) {
                QCOMPARE(user.name, database.getUser().name);
                database.closeDatabase();
                database.openDatabase(user);
                QCOMPARE(user.name, database.getUser().name);
                database.closeDatabase();
                QVERIFY(QFile::remove(databaseLocation));
            } else {
                QFAIL("File does not exist");
            }
        } else {
            QVERIFY(!QFile::exists(databaseLocation));
        }
    }
}

void TestCase::databaseEngine_updateMessageList_test()
{
    User user("12345678", "user");
    DatabaseEngine database;
    if (database.openDatabase(user)) {
        Message firstMessage( "ivan", "1234", "2020-06-10", "Hello!"),
                secondMessage("vova", "5678", "2020-06-11", "Bye!"),
                thirdMessage( "",     "7946", "2020-06-13", "Goodbye!");
        QCOMPARE(firstMessage.isValid(), true);
        QCOMPARE(secondMessage.isValid(), true);
        QCOMPARE(thirdMessage.isValid(), false);
        QList<Message> messageList;
        messageList << firstMessage;
        database.refreshTable(messageList);
        messageList << secondMessage;
        database.refreshTable(messageList);
        database.closeDatabase();
        QVERIFY(QFile::remove(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) +
                              "/Database/" + user.id + ".db"));
    } else {
        QFAIL("The database is not open");
    }
}

void TestCase::serializer_test()
{
    QFile testFile(TEST_MESSAGE_FILE_PATH);

    if (testFile.open(QIODevice::ReadOnly)) {
        QList<Message> testMessageList;
        testMessageList.append(Message("Ivan",    "3621897462", "2013-02-05T19:23:12+00:00", "Andryukha, we have a corpse."));
        testMessageList.append(Message("Nikolay", "2897430847", "2012-03-25T17:26:34+00:00", "Possibly a crime!"));
        testMessageList.append(Message("Michail", "5465484984", "2011-04-15T13:25:45+00:00", "On the horses!"));

        QByteArray test_jsonData = testFile.readAll();
        QList<Message> messageList = Serializer::deserializeToMessageList(test_jsonData);

        int iter = 0;
        for (auto message : messageList) {
            QCOMPARE(message.authorName, testMessageList[iter].authorName);
            QCOMPARE(message.authorId,   testMessageList[iter].authorId);
            QCOMPARE(message.timestamp,  testMessageList[iter].timestamp);
            QCOMPARE(message.text,       testMessageList[iter].text);

            iter++;
        }
    } else {
        QFAIL("Error reading file!");
    }
}

void TestCase::serializer_deserializerToUser_test()
{
    QFile testFile(TEST_USER_FILE_PATH);
    if (testFile.open(QIODevice::ReadOnly)) {
        User testUser("1234", "ivan");
        QByteArray test_jsonData = testFile.readAll();
        User user = Serializer::deserializeToUser(test_jsonData);
        QCOMPARE(user.id, testUser.id);
        QCOMPARE(user.name, testUser.name);
    } else {
        QFAIL("Error reading file!");
    }
}


void TestCase::test_uuid_manager()
{
    UuidManager uuid;

    QString id = "ef2c325c-d12a-4edc-9b0b-dea0dff7b489";

    QCOMPARE(UuidManager::getId(), QString());

    UuidManager::create(id);
    QCOMPARE(UuidManager::getId(), id);
    QCOMPARE(uuid.exists(), true);
    uuid.clear();

    QCOMPARE(uuid.exists(), false);
    UuidManager::create(QString());
    QCOMPARE(UuidManager::getId(), QString());
    QCOMPARE(uuid.exists(), false);
    uuid.clear();
}

QTEST_APPLESS_MAIN(TestCase)
