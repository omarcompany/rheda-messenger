﻿#include "messenger.h"

#include <QVariantMap>
#include <QNetworkReply>
#include <QDebug>

#include "uuidmanager.h"
#include "serializer.h"

static const QString RHEDA_DOMAIN{"https://rheda.herokuapp.com"};
static const QString API_VERSION{"/api/"};

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

void Messenger::handleResponse(QNetworkReply *reply)
{
    connect(reply, &QNetworkReply::finished, [=](){
        if (reply->error() == QNetworkReply::NoError) {
            switch (getApiType(reply->url())) {
            case Requester::SIGN_UP:
                handleSignupResponse(reply);
                break;
            }
        } else {
            handleError(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
        }
        reply->deleteLater();
    });
}

void Messenger::handleSignupResponse(QNetworkReply *reply)
{
    QString id = Serializer::getId(reply->readAll());
    if (!id.isEmpty()) {
        UUIDManager::create(id);
        emit signUpComplete();
    }
}

Requester::ApiType Messenger::getApiType(const QUrl &url)
{
    QString apiUrl = url.toString();
    apiUrl.replace(RHEDA_DOMAIN + API_VERSION, "");

    if (apiUrl == "signup")
        return Requester::SIGN_UP;
    /*
     * Another api types
     */

}

void Messenger::handleError(int code)
{
    switch (code) {
    case 0:
        emit error(MessengerError::NoNetWorkConnect);
        break;
    case 404:
        emit error(MessengerError::NotFound);
        break;
    case 503:
        emit error(MessengerError::ServerNotAvailable);
        break;
    }
}
