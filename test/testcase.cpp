#include "testcase.h"
#include "databaseengine.h"
#include "user.h"

#include <QtTest>
#include <QDebug>
#include <QDir>

#include "serializer.h"
#include "message.h"

static const QString TEST_MESSAGE_FILE_PATH = QString(PRO_FILE_PWD) + "/test_messages.json";
static const int CHECK_TIME = 2;

TestCase::TestCase()
{
    qDebug() << "TestCase()";
}

TestCase::~TestCase()
{

}

void TestCase::checkDatabase_test()
{
    qDebug() << "Starting test of DatabaseEngine class's methods";
    qDebug() << "Add new user Ivan";

    User ivan("1234", "ivan");
    DatabaseEngine db1;
    db1.openDatabase(ivan);
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) +
            "/Database/" + ivan.id + ".db";

    qDebug() << "Users Ivan have been registered. "
             << QString("After %1 seconds user Ivan data will be showed on screen").arg(CHECK_TIME);
    qDebug() << "Please, check database" << filePath;
    QTest::qSleep(1000 * CHECK_TIME);

    qDebug() << db1.getUser().name;

    qDebug() << QString("After %1 seconds user Ivan will be removed!").arg(CHECK_TIME / 2);
    qDebug() << "Please, check debug!";
    QTest::qSleep(500 * CHECK_TIME);

    db1.closeDatabase();
    QFile::remove(filePath);

    qDebug() << "Please, check debug! User have been removed.";
    qDebug() << "End of DatabaseEngine class's methods test";
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

QTEST_APPLESS_MAIN(TestCase)
