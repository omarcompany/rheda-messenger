#include "test_message_model.h"

#include "message.h"

TestMessageModel::TestMessageModel()
{
    QList<Message> testMessageList;
    testMessageList.append(Message("Ivan",    "3621897462", "2013-02-05T19:23:12+00:00", "Andryukha, we have a corpse."));
    testMessageList.append(Message("Nikolay", "2897430847", "2012-03-25T17:26:34+00:00", "Possibly a crime!"));
    testMessageList.append(Message("Michail", "5465484984", "2011-04-15T13:25:45+00:00", "On the horses!"));

    m_messageModel.addMessage(testMessageList);
}

void TestMessageModel::qmlEngineAvailable(QQmlEngine *engine)
{
    engine->rootContext()->setContextProperty("messageModel", &m_messageModel);
}

QUICK_TEST_MAIN_WITH_SETUP(tst_message_model, TestMessageModel)
