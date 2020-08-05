#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "messenger.h"
#include "uuidmanager.h"
#include "messagemodel.h"
#include "modelprovider.h"

template <typename T>
static QObject *singleton_factory(QQmlEngine *, QJSEngine *)
{
    return new T;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterSingletonType<Messenger>("elevons.team", 1, 0, "Messenger", singleton_factory<Messenger>);
    qmlRegisterSingletonType<ModelProvider>("elevons.team", 1, 0, "ModelProvider", singleton_factory<ModelProvider>);
    qmlRegisterType<MessageModel>("elevons.team", 1, 0, "MessageModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
