#ifndef USER_H
#define USER_H

#include <QString>

struct User {
    User() = default;
    User(QString userId, QString userName) : id(userId), name(userName) {}

    bool isValid() const {
        if (id.isEmpty() || name.isEmpty())
            return false;
        return true;
    }

    QString id;
    QString name;
};

#endif // USER_H
