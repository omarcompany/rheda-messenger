#ifndef TESTCASE_H
#define TESTCASE_H

#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

class TestCase : public QObject
{
    Q_OBJECT
public:
    TestCase();

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);

private:
    QVariant m_message;
};

#endif // TESTCASE_H
