#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "messenger.h"

static QObject *messenger_api_factory(QQmlEngine *, QJSEngine *)
{
    return Messenger::instance();
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<Messenger>("elevons.team", 1, 0, "Messenger", messenger_api_factory);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
