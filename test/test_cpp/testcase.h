#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>

#include <databaseengine.h>

class TestCase : public QObject
{
    Q_OBJECT
public:
    TestCase();
    ~TestCase();

private slots:
    void checkDatabase_test();
    void databaseEngine_refreshTable_test();
    void serializer_test();
    void serializer_deserializerToUser_test();
    void test_uuid_manager();
    void deserializeUserList_test();
};

#endif // TESTCASE_H
