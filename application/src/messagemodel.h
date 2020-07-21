#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractListModel>
#include <message.h>

class MessageModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    MessageModel(QObject *parent = nullptr);

    void addMessage(QList<Message> messageList);
    void clear();
    int count() const;

signals:
    void countChanged();

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

    QList<Message> m_messageList;

    void connectDatabase();
};

#endif // MESSAGEMODEL_H
