#include "messenger.h"

#include <QVariantMap>
#include <QNetworkReply>
#include <QDebug>

#include "uuidmanager.h"
#include "serializer.h"

Messenger::Messenger()
    : m_requester{new Requester(this)}
{
    connect(m_requester, &Requester::replied, this, &Messenger::handleResponse);
}

void Messenger::signUp(const QString &name)
{
    QVariantMap jsonData;
    jsonData["name"] = name;

    m_requester->sendRequest(Requester::POST, Requester::SIGN_UP, jsonData);
}

void Messenger::handleResponse(QNetworkReply *reply, Requester::ApiType api)
{
    connect(reply, &QNetworkReply::finished, [=](){
        switch (api) {
        case Requester::SIGN_UP:
            handleSignupResponse(reply);
            break;
        }
        reply->deleteLater();
    });
}

void Messenger::handleSignupResponse(QNetworkReply *reply)
{
    QString id = Serializer::getId(reply->readAll());
    if (!id.isEmpty()) {
        UUIDManager::create(Serializer::getId(reply->readAll()));
        emit signUpComplete();
    }
}
