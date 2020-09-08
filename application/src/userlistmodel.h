#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include "user.h"

class UserListModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    UserListModel(QObject *parent = nullptr);

    void setUserlist(const QList<User> &userList);
    int count() const;

signals:
    void countChanged();

private:
    enum Roles {
        Id,
        Name,
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void connectDatabase();

private:
    QList<User> m_userList;
};

#endif // USERLISTMODEL_H
