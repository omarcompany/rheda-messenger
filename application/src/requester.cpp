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
static const QString API_VERSION{"/api/"};

Requester::Requester(QObject *parent)
    : QObject{parent}
    , m_manager{new QNetworkAccessManager(this)}
{}

QString Requester::apiToString(Requester::ApiType api)
{
    switch (api) {
    case SIGN_UP:
        return API_VERSION + "signup";
    case SEND_MESSAGE:
        return API_VERSION + "message";
    case REQUEST_MESSAGE_LIST:
        return API_VERSION + "messageList";
    }
}
Requester::ApiType Requester::urlToApi(const QUrl &url)
{
    QString apiUrl = url.toString();
    apiUrl.replace(RHEDA_DOMAIN + API_VERSION, "");

    if (apiUrl == "signup")
        return Requester::SIGN_UP;
    if (apiUrl == "message")
        return Requester::SEND_MESSAGE;
    if (apiUrl == "messageList")
        return Requester::REQUEST_MESSAGE_LIST;
    /*
     * Another api types
     */
}

QNetworkRequest Requester::createRequest(const Requester::ApiType &api)
{
    QNetworkRequest request;
    QString url = RHEDA_DOMAIN + apiToString(api);
    request.setUrl(QUrl(url));
    request.setRawHeader("Content-Type","application/json");

    return request;
}

void Requester::sendRequest(const Requester::RequestType type, const Requester::ApiType api, const QVariantMap &jsonData)
{
    switch (type) {
    case POST: {
        QNetworkRequest request = createRequest(api);
        QJsonObject obj = QJsonObject::fromVariantMap(jsonData);
        QJsonDocument doc(obj);
        QByteArray postDataByteArray = doc.toJson();

        QNetworkReply *reply;
        reply = m_manager->post(request, postDataByteArray);
        connect(reply, &QNetworkReply::finished, [=](){
            if (reply->error() == QNetworkReply::NoError)
                emit replied(urlToApi(reply->url()), reply->readAll());
            else
                emit error(reply->error());
        });
        break;
    }
    default:
        return;
    }
}

