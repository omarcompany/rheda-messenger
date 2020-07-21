#ifndef TESTMESSAGEMODEL_H
#define TESTMESSAGEMODEL_H
#include "modelprovider.h"

class QQmlEngine;
class ModelProvider;
class TestModelProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isCompleted READ isCompleted NOTIFY isCompletedChanged)
public:
    TestModelProvider();
    Q_INVOKABLE void clear();

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);

signals:
    void isCompletedChanged();

private:
    ModelProvider *m_modelProvider;
    bool m_isCompleted;

    bool isCompleted() const;
};

#endif // TESTMESSAGEMODEL_H
