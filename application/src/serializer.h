#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QObject>

struct Message;
struct User;

class Serializer : public QObject
{
public:
    Serializer() = delete;

    static QList<Message> deserializeToMessageList(const QByteArray &jsonData);
    static User deserializeToUser(const QByteArray &jsonData);
    static QList<User> deserializeToUserList(const QByteArray &jsonData);
};

#endif // SERIALIZER_H
