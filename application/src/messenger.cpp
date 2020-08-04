#include "messenger.h"

#include <QVariantMap>
#include <QNetworkReply>
#include <QDebug>

#include "uuidmanager.h"
#include "serializer.h"
#include "message.h"
#include "databaseengine.h"

Messenger::Messenger()
    : m_requester{new Requester(this)}
{
    connect(m_requester, &Requester::replied, this, &Messenger::handleResponse);
    connect(m_requester, &Requester::error, this, [this](int code) {
        emit error(fromErrorCode(code));
    });

    QString id = UuidManager::getId();
    if (DatabaseEngine::instance()->open(id))
        setUserId(id);
}

void Messenger::signUp(const QString &name)
{
    QVariantMap jsonData;
    jsonData["name"] = name;

    m_requester->sendRequest(Requester::POST, Requester::SIGN_UP, jsonData);
}

void Messenger::signOut()
{
    UuidManager::clear();
    setUserId(UuidManager::getId());
}

QString Messenger::userId() const
{
    return m_userId;
}

void Messenger::setUserId(QString userId)
{
    if (m_userId == userId)
        return;

    m_userId = userId;
    emit userIdChanged(m_userId);
}

void Messenger::sendMessage(const QString &recipientId, const QString &text)
{
    QVariantMap jsonData;
    jsonData["text"]      = text;
    jsonData["sender"]    = userId();
    jsonData["recipient"] = recipientId;

    m_requester->sendRequest(Requester::POST, Requester::SEND_MESSAGE, jsonData);
}

void Messenger::requestMessageList(const QString &recipientId) const
{
    QVariantMap jsonData;
    jsonData["sender"] = UuidManager::getId();
    jsonData["recipient"] = recipientId;

    m_requester->sendRequest(Requester::GET, Requester::REQUEST_MESSAGE_LIST, jsonData);
}

void Messenger::handleResponse(Requester::ApiType api, const QByteArray &data)
{
    switch (api) {
    case Requester::SIGN_UP:
        handleSignupResponse(data);
        break;
    case Requester::SEND_MESSAGE:
        qDebug() << "Response from server: message saved ";
        break;
    case Requester::REQUEST_MESSAGE_LIST:
        handleRequestMessageListResponse(data);
        break;
    }
}

void Messenger::handleSignupResponse(const QByteArray &data)
{
    User user = Serializer::deserializeToUser(data);
    if (user.isValid()) {
        UuidManager::create(user.id);
        DatabaseEngine::instance()->open(user);
        setUserId(user.id);
    }
}

void Messenger::handleRequestMessageListResponse(const QByteArray &data)
{
    QList<Message> messageList = Serializer::deserializeToMessageList(data);
    DatabaseEngine::instance()->refreshTable(messageList);
}

Messenger::MessengerError Messenger::fromErrorCode(int code)
{
    switch (code) {
    case 0:
        return MessengerError::NoNetworkConnect;
    case 404:
        return MessengerError::NotFound;
    case 503:
        return MessengerError::ServerNotAvailable;
    default:
        return MessengerError::OtherError;
    }
}
