#include "testcase.h"
#include <QtTest>
#include <QDebug>

TestCase::TestCase()
{
    qDebug() << "TestCase()";
}

TestCase::~TestCase()
{

}
QTEST_APPLESS_MAIN(TestCase)
