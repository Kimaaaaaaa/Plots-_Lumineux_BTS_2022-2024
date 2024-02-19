#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <bluetoothcom.h>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    BluetoothCom bluetoothCom;

     // Connexion du signal deviceDiscovered de BluetoothCom à un slot pour afficher les informations du périphérique découvert
     QObject::connect(&bluetoothCom, &BluetoothCom::deviceDiscovered, [&](const QBluetoothDeviceInfo &deviceInfo){
         qDebug() << "Device discovered:" << deviceInfo.name() << "-" << deviceInfo.address().toString();
     });

     // Démarrage du scan des périphériques Bluetooth
     bluetoothCom.startScan();

    return app.exec();
}
