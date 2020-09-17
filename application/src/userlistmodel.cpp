#include "userlistmodel.h"
#include "databaseengine.h"

UserListModel::UserListModel(QObject *parent) : QAbstractListModel(parent)
{
    connectDatabase();
}

void UserListModel::setUserlist(const QList<User> &userList)
{
    beginResetModel();
    m_userList = userList;
    emit countChanged();
    endResetModel();
}

int UserListModel::count() const
{
    return m_userList.count();
}

int UserListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_userList.count();
}

QVariant UserListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Id:
        return m_userList[index.row()].id;
    case Name:
        return m_userList[index.row()].name;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> UserListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Id]   = "id";
    roles[Name] = "name";

    return roles;
}

void UserListModel::connectDatabase()
{
    setUserlist(DatabaseEngine::instance()->getUserList());
    connect(DatabaseEngine::instance(), &DatabaseEngine::dataChanged, [this]() {
        setUserlist(DatabaseEngine::instance()->getUserList());
    });
}


