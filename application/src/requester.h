#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>

class QJSValue;
class QNetworkAccessManager;
class QNetworkReply;
class QNetworkRequest;

class Requester : public QObject
{
    Q_OBJECT
public:

    enum ApiType {
        SIGN_UP,
        /*Add here new API*/
    };

    enum RequestType {
        GET,
        POST,
        PUT,
        DELETE
    };

    explicit Requester(QObject *parent = nullptr);

    QString getApi(Requester::ApiType api);
    QNetworkRequest createRequest(const Requester::ApiType &api);
    void sendRequest(const Requester::RequestType type, const Requester::ApiType &api, const QVariantMap &jsonData);

signals:
    void replied(QNetworkReply *reply, const ApiType &api);

private:
    QNetworkAccessManager *m_manager;
    QString m_url;
};

#endif // REQUEST_H
