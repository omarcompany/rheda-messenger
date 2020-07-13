#include "test_model_provider.h"
#include "message.h"
#include "messagemodel.h"
#include "databaseengine.h"

#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

TestModelProvider::TestModelProvider()
{
    m_modelProvider = new ModelProvider(this);
    m_isCompleted = false;

    User user("12345678", "user");
    DatabaseEngine::instance()->open(user);

    QList<Message> testMessageList;
    testMessageList.append(Message("Ivan",    "3621897462", "2013-02-05T19:23:12+00:00", "Andryukha, we have a corpse."));
    testMessageList.append(Message("Nikolay", "2897430847", "2012-03-25T17:26:34+00:00", "Possibly a crime!"));
    testMessageList.append(Message("Michail", "5465484984", "2011-04-15T13:25:45+00:00", "On the horses!"));

    connect(DatabaseEngine::instance(), &DatabaseEngine::dataChanged, [this]() {
        m_isCompleted = true;
        emit isCompletedChanged();
    });
    DatabaseEngine::instance()->refreshTable(testMessageList);
}

void TestModelProvider::clear()
{
    m_modelProvider->messageList()->clear();
}

void TestModelProvider::qmlEngineAvailable(QQmlEngine *engine)
{
    qmlRegisterType<MessageModel>("elevons.team", 1, 0, "MessageModel");
    engine->rootContext()->setContextProperty("modelProvider", m_modelProvider);
    engine->rootContext()->setContextProperty("TestModelProvider", this);
}

bool TestModelProvider::isCompleted() const
{
    return m_isCompleted;
}

QUICK_TEST_MAIN_WITH_SETUP(tst_model_provider, TestModelProvider)
