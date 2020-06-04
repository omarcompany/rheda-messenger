#include "testcase.h"
#include "databaseengine.h"
#include "user.h"

#include <QtTest>

static const int CHECK_TIME = 30;

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
             << "After 30 seconds user Ivan data will be showed on screen";
    qDebug() << "Please, check database" << filePath;
    QTest::qSleep(1000 * CHECK_TIME);

    qDebug() << db1.getUser().name;

    qDebug() << "After 15 seconds user Ivan will be removed!";
    qDebug() << "Please, check debug!";
    QTest::qSleep(500 * CHECK_TIME);

    db1.closeDatabase();
    QFile::remove(filePath);

    qDebug() << "Please, check debug! User have been removed.";
    qDebug() << "End of DatabaseEngine class's methods test";
}
QTEST_APPLESS_MAIN(TestCase)
