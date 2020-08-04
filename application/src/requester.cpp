#include "requester.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include "uuidmanager.h"
#include "serializer.h"

static const QString RHEDA_DOMAIN{"https://rheda.herokuapp.com"};

Requester::Requester(QObject *parent)
    : QObject{parent}
    , m_manager{new QNetworkAccessManager(this)}
{}

QString Requester::getApi(Requester::ApiType api)
{
    switch (api) {
    case SIGN_UP:
        return "/api/signup";
    case SEND_MESSAGE:
        return "/api/message";
    case REQUEST_MESSAGE_LIST:
        return "/api/messageList";
    }
}

QNetworkRequest Requester::createRequest(const Requester::ApiType &api)
{
    QNetworkRequest request;
    QString url = RHEDA_DOMAIN + getApi(api);
    request.setUrl(QUrl(url));
    request.setRawHeader("Content-Type","application/json");

    return request;
}

void Requester::sendRequest(const Requester::RequestType type, const Requester::ApiType api, const QVariantMap &jsonData)
{
    QNetworkRequest request = createRequest(api);
    QNetworkReply *reply;
    switch (type) {
    case POST: {
        QJsonObject obj = QJsonObject::fromVariantMap(jsonData);
        QJsonDocument doc(obj);
        QByteArray postDataByteArray = doc.toJson();
        reply = m_manager->post(request, postDataByteArray);
        break;
    }
    case GET: {
        QUrlQuery params;
        for (auto itr = jsonData.begin(); itr != jsonData.end(); ++itr)
            params.addQueryItem(itr.key(), itr->toString());
        auto url = request.url();
        url.setQuery(params);
        request.setUrl(url);
        reply = m_manager->get(request);
        break;
    }
    default:
        return;
    }
    emit replied(reply);
}
