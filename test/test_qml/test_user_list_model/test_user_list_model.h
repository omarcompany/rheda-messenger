#ifndef TESTUSERLISTMODEL_H
#define TESTUSERLISTMODEL_H

#include "contactmodel.h"

#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

class TestUserListModel : public QObject
{
    Q_OBJECT
public:
    TestUserListModel();

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);

private:
    ContactModel m_userListModel;
    QList<User> m_testUserListModel;
};

#endif // TESTUSERLISTMODEL_H
