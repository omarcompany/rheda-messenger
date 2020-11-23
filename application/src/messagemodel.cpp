#include "messagemodel.h"
#include "databaseengine.h"

MessageModel::MessageModel(QObject *parent) : QAbstractListModel(parent)
{
    connectDatabase();
}

void MessageModel::addMessage(QList<Message> messageList)
{
    beginResetModel();
    for (auto message : messageList) {
        m_messageList.append(message);
    }
    emit countChanged();
    endResetModel();
}

void MessageModel::clear()
{
    beginResetModel();
    m_messageList.clear();
    emit countChanged();
    endResetModel();
}

int MessageModel::count() const
{
    return m_messageList.count();
}

int MessageModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_messageList.count();
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Id:
        return m_messageList[index.row()].authorId;
    case Name:
        return m_messageList[index.row()].authorName;
    case TextRole:
        return m_messageList[index.row()].text;
    case Timestamp:
        return (m_messageList[index.row()].timestamp.toLocalTime()).toString();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> MessageModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Id] =         "id";
    roles[Name] =       "name";
    roles[TextRole] =   "text";
    roles[Timestamp ] = "timestamp";

    return roles;
}

void MessageModel::connectDatabase()
{
    addMessage(DatabaseEngine::instance()->getMessageList());
    connect(DatabaseEngine::instance(), &DatabaseEngine::dataChanged, [this]() {
        clear();
        addMessage(DatabaseEngine::instance()->getMessageList());
    });
}
