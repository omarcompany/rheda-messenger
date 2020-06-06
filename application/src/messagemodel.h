#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractListModel>
#include <message.h>

class MessageModel: public QAbstractListModel
{
    Q_OBJECT
public:
    MessageModel(QObject *parent = nullptr);

    void addMessage(QList<Message> messageList);

private:
    enum Roles {
        Id,
        Name,
        TextRole,
        Timestamp
    };

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Message> m_messageList;
};

#endif // MESSAGEMODEL_H
