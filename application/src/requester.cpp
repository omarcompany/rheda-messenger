#include "requester.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

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

void Requester::sendRequest(const Requester::RequestType type, const Requester::ApiType &api, const QVariantMap &jsonData)
{
    switch (type) {
    case POST:
        QNetworkRequest request = createRequest(api);
        QJsonObject obj = QJsonObject::fromVariantMap(jsonData);
        QJsonDocument doc(obj);
        QByteArray postDataByteArray = doc.toJson();

        QNetworkReply *reply;
        reply = m_manager->post(request, postDataByteArray);
        emit replied(reply, api);
    }
}
