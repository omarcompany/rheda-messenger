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

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);

private:
    MessageModel m_messageModel;
};

#endif // TESTMESSAGEMODEL_H
