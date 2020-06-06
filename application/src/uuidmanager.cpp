#include "uuidmanager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QStandardPaths>
#include <QFile>
#include <QDir>


static const QString CONFIG_PATH = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/rheda-messenger/";
static const QString FILE_PATH = CONFIG_PATH + "user.conf";

UuidManager::UuidManager(QObject *parent)
    : QObject{parent}
{

}

bool UuidManager::exists()
{
    if (QFile::exists(FILE_PATH)) {
        QFile uuidFile(FILE_PATH);
        if (uuidFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QString id = uuidFile.readAll();
            return !id.isEmpty();
        }
    }
    return false;
}

void UuidManager::create(const QString &id)
{
    QByteArray textStream = id.toUtf8();

    QDir dir;
    dir.mkpath(CONFIG_PATH);

    QFile uuidFile(FILE_PATH);
    if (uuidFile.open(QIODevice::WriteOnly)) {
        uuidFile.write(textStream);
        uuidFile.close();
    }
}

void UuidManager::clear()
{
    QFile::remove(FILE_PATH);
}

QString UuidManager::getId()
{
    QFile uuidFile(FILE_PATH);
    QString id;
    if (!uuidFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString();
    }

    id = uuidFile.readAll();
    uuidFile.close();

    return id;
}
