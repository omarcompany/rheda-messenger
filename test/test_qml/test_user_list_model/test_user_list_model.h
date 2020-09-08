#ifndef TESTUSERLISTMODEL_H
#define TESTUSERLISTMODEL_H

#include "userlistmodel.h"

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
    UserListModel m_userListModel;
    QList<User> m_testUserListModel;
};

#endif // TESTUSERLISTMODEL_H
