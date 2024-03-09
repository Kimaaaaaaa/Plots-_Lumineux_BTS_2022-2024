#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <monnaie.h>
#include <QDebug>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    /*test du constructeur / getters (FONCTIONNEL)*/

    monnaie monnaieEuro;
    qInfo ()  << "Monnaie Euro :";
    qDebug() << "Valeur : " << monnaieEuro.getValeur();
    qDebug() << "Taux   : " << monnaieEuro.getTauxEuro();

    monnaie monnaieFranc(nullptr,6.55957, 100);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("monnaie1", &monnaieEuro);
    engine.rootContext()->setContextProperty("monnaie2", &monnaieFranc);

    const QUrl url(u"qrc:/EuroIntoFranc/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);






    return app.exec();
}
