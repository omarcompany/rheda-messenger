#include "serializer.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

Serializer::Serializer(QObject *parent)
    : QObject{parent}
{

}

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
