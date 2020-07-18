#ifndef TESTMESSAGEMODEL_H
#define TESTMESSAGEMODEL_H
#include "messagemodel.h"

#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

class TestMessageModel : public QObject
{
    Q_OBJECT
public:
    TestMessageModel();
    Q_INVOKABLE void clear();

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);

private:
    MessageModel m_messageModel;
    MessageModel m_cleanMessageModel;
    QList<Message> m_testMessageList;
};

#endif // TESTMESSAGEMODEL_H
