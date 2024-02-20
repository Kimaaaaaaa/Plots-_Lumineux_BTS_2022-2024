#include <QCoreApplication>
#include <bluetoothcom.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BluetoothCom bluetoothCom;

    QObject::connect(&bluetoothCom, &BluetoothCom::deviceDiscovered, [&](const QBluetoothDeviceInfo &deviceInfo){
        qDebug() << "Périphérique découvert:" << deviceInfo.name() << "-" << deviceInfo.address().toString();
    });


     // Démarrage du scan des périphériques Bluetooth
     bluetoothCom.startScan();

    return a.exec();
}
