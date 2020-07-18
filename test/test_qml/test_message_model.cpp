#include "test_message_model.h"
#include "message.h"

TestMessageModel::TestMessageModel()
{
    m_testMessageList.append(Message("Ivan",    "3621897462", "2013-02-05T19:23:12+00:00", "Andryukha, we have a corpse."));
    m_testMessageList.append(Message("Nikolay", "2897430847", "2012-03-25T17:26:34+00:00", "Possibly a crime!"));
    m_testMessageList.append(Message("Michail", "5465484984", "2011-04-15T13:25:45+00:00", "On the horses!"));

    m_messageModel.addMessage(m_testMessageList);
}

void TestMessageModel::clear()
{
    m_messageModel.clear();
}

void TestMessageModel::qmlEngineAvailable(QQmlEngine *engine)
{
    engine->rootContext()->setContextProperty("messageModel", &m_messageModel);
    engine->rootContext()->setContextProperty("TestMessage", this);
}

QUICK_TEST_MAIN_WITH_SETUP(tst_message_model, TestMessageModel)
