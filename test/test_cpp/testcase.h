#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>

class TestCase : public QObject
{
    Q_OBJECT
public:
    TestCase();
    ~TestCase();

private slots:
    void checkDatabase_test();
    void serializer_test();
    void serializer_deserializerToUser_test();
};

#endif // TESTCASE_H
