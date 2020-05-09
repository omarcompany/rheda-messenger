#include "uuidmanager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QDir>

static const QString FILE_PATH = QDir::homePath() + "/UUID.txt";

UUIDManager::UUIDManager(QObject *parent)
    : QObject{parent}
{

}

bool UUIDManager::exists()
{
    return QFile::exists(FILE_PATH);
}

void UUIDManager::create(const QString &id)
{
    QByteArray textStream = id.toUtf8();

    QFile uuidFile(FILE_PATH);
    if (uuidFile.open(QIODevice::WriteOnly)) {
        uuidFile.write(textStream);
        uuidFile.close();
    }
}

void UUIDManager::clear()
{
    QFile::remove(FILE_PATH);
}
