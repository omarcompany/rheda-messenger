#include "contactmodel.h"
#include "databaseengine.h"

ContactModel::ContactModel(QObject *parent) : QAbstractListModel(parent)
{
    connectDatabase();
}

void ContactModel::setUserList(const QList<User> &userList)
{
    beginResetModel();
    m_userList = userList;
    emit countChanged();
    endResetModel();
}

int ContactModel::count() const
{
    return m_userList.count();
}

int ContactModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_userList.count();
}

QVariant ContactModel::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> ContactModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Id]   = "id";
    roles[Name] = "name";

    return roles;
}

void ContactModel::connectDatabase()
{
    setUserList(DatabaseEngine::instance()->getUserList());
    connect(DatabaseEngine::instance(), &DatabaseEngine::dataChanged, [this]() {
        setUserList(DatabaseEngine::instance()->getUserList());
    });
}


