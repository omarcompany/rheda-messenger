#include "testcase.h"

#include <QtTest>
#include <QDebug>
#include <QDir>
#include <QVector>

#include "user.h"
#include "serializer.h"
#include "message.h"
#include "uuidmanager.h"
#include "messagemodel.h"

static const QString TEST_MESSAGE_FILE_PATH = QString(PRO_FILE_PWD) + "/test_messages.json";
static const QString TEST_USER_FILE_PATH = QString(PRO_FILE_PWD) + "/test_user.json";
static const QString TEST_USER_LIST_FILE = QString(PRO_FILE_PWD) + "/test_user_list.json";

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
    for (auto user : userList) {
        DatabaseEngine::instance()->open(user);
        QString databaseLocation = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) +
                "/Database/" + user.id + ".db";
        if (user.isValid()) {
            if (QFile::exists(databaseLocation)) {
                QCOMPARE(user.name, DatabaseEngine::instance()->getUser().name);
                DatabaseEngine::instance()->close();
                DatabaseEngine::instance()->open(user);
                QCOMPARE(user.name, DatabaseEngine::instance()->getUser().name);
                DatabaseEngine::instance()->close();
                DatabaseEngine::instance()->open(user.id);
                QCOMPARE(user.name, DatabaseEngine::instance()->getUser().name);
                DatabaseEngine::instance()->close();
                QVERIFY(QFile::remove(databaseLocation));
            } else {
                QFAIL("File does not exist");
            }
        } else {
            QVERIFY(!QFile::exists(databaseLocation));
        }
    }
}

void TestCase::databaseEngine_refreshTable_test()
{
    User user("12345678", "user");
    if (DatabaseEngine::instance()->open(user)) {
        Message firstMessage( "ivan", "1234", "2020-06-10", "Hello!"),
                secondMessage("", "5678", "2020-06-11", "Bye!"),
                thirdMessage( "",     "7946", "2020-06-13", "");
        QCOMPARE(firstMessage.isValid(), true);
        QCOMPARE(secondMessage.isValid(), true);
        QCOMPARE(thirdMessage.isValid(), false);
        QList<Message> messageList;
        messageList << firstMessage;
        DatabaseEngine::instance()->refreshTable(messageList);
        QCOMPARE(DatabaseEngine::instance()->getMessageList()[0].authorId, firstMessage.authorId);
        QCOMPARE(DatabaseEngine::instance()->getMessageList()[0].timestamp, firstMessage.timestamp);
        messageList << secondMessage;
        DatabaseEngine::instance()->refreshTable(messageList);
        QCOMPARE(DatabaseEngine::instance()->getMessageList()[0].authorId, firstMessage.authorId);
        QCOMPARE(DatabaseEngine::instance()->getMessageList()[0].timestamp, firstMessage.timestamp);
        QCOMPARE(DatabaseEngine::instance()->getMessageList()[1].authorId, secondMessage.authorId);
        QCOMPARE(DatabaseEngine::instance()->getMessageList()[1].timestamp, secondMessage.timestamp);
        DatabaseEngine::instance()->close();
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

void TestCase::deserializeUserList_test()
{
    QFile testFile(TEST_MESSAGE_FILE_PATH);

    if (testFile.open(QIODevice::ReadOnly)) {
        QList<User> testUserList;
        testUserList.append(User("8723536", "Andrukha"));
        testUserList.append(User("8721364", "Dukalis"));
        testUserList.append(User("1278540", "Joposranchik"));

        QByteArray test_jsonData = testFile.readAll();
        QList<User> userList = Serializer::deserializeToUserList(test_jsonData);

        int iter = 0;
        for (auto user : userList) {
            QCOMPARE(user.id, testUserList[iter].id);
            QCOMPARE(user.name,testUserList[iter].name);

            iter++;
        }
    } else {
        QFAIL("Error reading file!");
    }
}

void TestCase::getUserList_test()
{
    User user("12345678", "user");
    if (DatabaseEngine::instance()->open(user)) {
        User andrukha("8723536", "Andrukha");
        User dukalis("8721364", "Dukalis");
        User joposranchik("1278540", "Joposranchik");

        QList<User> temp_userList;
        temp_userList.append(andrukha);
        temp_userList.append(dukalis);
        temp_userList.append(joposranchik);

        DatabaseEngine::instance()->refreshTable(temp_userList);

        QList<User> test_userList = DatabaseEngine::instance()->getUserList();

        for(int i = 0; i < test_userList.length(); i++) {
            QCOMPARE(test_userList[i].id,   temp_userList[i].id);
            QCOMPARE(test_userList[i].name, temp_userList[i].name);
        }
    }
}

QTEST_APPLESS_MAIN(TestCase)
