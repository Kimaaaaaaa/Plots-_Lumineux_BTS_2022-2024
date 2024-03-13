#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <comble.h>
#include <controller.h>
#include <QQmlContext>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);



    Controller controller;


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("controller", &controller);
    qmlRegisterType<Plot>("entitePlot", 1, 0, "Plot");


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
