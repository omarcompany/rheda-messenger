#include "serializer.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>
#include <QList>
#include <QSharedPointer>
#include <QDateTime>

#include "message.h"
#include "user.h"

QList<Message> Serializer::deserializeToMessageList(const QByteArray &jsonData)
{
    QJsonArray jsonArray = QJsonDocument::fromJson(jsonData).array();

    QList<Message> messageList;
    for (const auto &jsonMessage : jsonArray) {
        Message message;

        message.authorId   = jsonMessage.toObject().value("sender").toString();
        message.text       = jsonMessage.toObject().value("text").toString();

        QString dateTime   = jsonMessage.toObject().value("created_at").toString();
        message.timestamp  = QDateTime::fromString(dateTime, Qt::ISODate);

        messageList.append(message);
    }

    return messageList;
}

User Serializer::deserializeToUser(const QByteArray &jsonData)
{
    QJsonObject jsonObj = QJsonDocument::fromJson(jsonData).object();
    User user;
    user.id = jsonObj["id"].toString();
    user.name = jsonObj["name"].toString();
    return user;
}

QList<User> Serializer::deserializeToUserList(const QByteArray &jsonData)
{
    QJsonArray jsonArray = QJsonDocument::fromJson(jsonData).array();

    QList<User> userList;
    for (const auto &jsonUser : jsonArray) {
        User user;

        user.id   = jsonUser.toObject().value("id").toString();
        user.name = jsonUser.toObject().value("name").toString();

        userList.append(user);
    }

    return userList;
}
