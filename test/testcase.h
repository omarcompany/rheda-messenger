#ifndef TESTCASE_H
#define TESTCASE_H

#include <QObject>

class TestCase : public QObject
{
    Q_OBJECT
public:
    TestCase();
    ~TestCase();
};

#endif // TESTCASE_H
