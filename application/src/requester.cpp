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

static const QString RHEDA_DOMAIN{"http://142.93.49.33:8000"};
//static const QString RHEDA_DOMAIN{"https://rheda.herokuapp.com"};

Requester::Requester(QObject *parent)
    : QObject{parent}
    , m_manager{new QNetworkAccessManager(this)}
{}

QString Requester::apiUrlToString(Requester::ApiUrl api)
{
    switch (api) {
    case SIGN_UP:
        return "/api/signup";
    case SEND_MESSAGE:
        return "/api/message";
    case REQUEST_MESSAGE_LIST:
        return "/api/messageList";
    case REQUEST_USER_LIST:
        return  "/api/accountList";
    }
}

Requester::ApiUrl Requester::stringToApiUrl(const QString &apiUrl)
{
    if (apiUrl == "signup")
        return Requester::SIGN_UP;
    if (apiUrl == "message")
        return Requester::SEND_MESSAGE;
    if (apiUrl == "messageList")
        return Requester::REQUEST_MESSAGE_LIST;
    if (apiUrl == "accountList")
        return Requester::REQUEST_USER_LIST;
    /*
     * Another api types
     */
}

QNetworkRequest Requester::createRequest(const Requester::ApiUrl &api)
{
    QNetworkRequest request;
    QString url = RHEDA_DOMAIN + apiUrlToString(api);
    request.setUrl(QUrl(url));
    request.setRawHeader("Content-Type", "application/json");

    return request;
}

void Requester::sendRequest(const Requester::RequestType type, const Requester::ApiUrl api, const QVariantMap &jsonData)
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
