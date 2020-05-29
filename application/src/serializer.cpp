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

QString Serializer::getId(const QByteArray &jsonData)
{
    QJsonDocument jsonDoc;
    QJsonParseError parseError;

    jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    QString id = jsonObj["id"].toString();
    return id;
}

QList<Message> Serializer::deserializeToMessageList(const QByteArray &jsonData)
{
    QJsonArray jsonArray = QJsonDocument::fromJson(jsonData).object().value("messages").toArray();

    QList<Message> messageList;
    for (auto jsonMessage : jsonArray) {
        Message message;

        message.authorName = jsonMessage.toObject().value("authorName").toString();
        message.authorId   = jsonMessage.toObject().value("authorId").toString();
        message.text       = jsonMessage.toObject().value("text").toString();

        QString dateTime   = jsonMessage.toObject().value("timestamp").toString();
        message.timestamp  = QDateTime::fromString(dateTime, Qt::ISODate);

        messageList.append(message);
    }

    return messageList;
}
