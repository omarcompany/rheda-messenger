#include "testcase.h"

TestCase::TestCase() : m_message("Do it!")
{

}

void TestCase::qmlEngineAvailable(QQmlEngine *engine)
{
    engine->rootContext()->setContextProperty("message", m_message);
}

QUICK_TEST_MAIN_WITH_SETUP(tst_case_qml, TestCase)
