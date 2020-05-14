#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "messenger.h"
#include "uuidmanager.h"

template <typename T>
static QObject *messenger_api_factory(QQmlEngine *, QJSEngine *)
{
    return new T;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<Messenger>("elevons.team", 1, 0, "Messenger", messenger_api_factory<Messenger>);
    qmlRegisterSingletonType<UUIDManager>("elevons.team", 1, 0, "UUIDManager", messenger_api_factory<UUIDManager>);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
