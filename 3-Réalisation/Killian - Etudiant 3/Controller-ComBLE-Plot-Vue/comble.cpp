#include "comble.h"
#include <QDebug>

ComBLE::ComBLE(QObject *parent) : QObject(parent)
{
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &ComBLE::deviceDetecte);

}

bool ComBLE::isScanning() const
{
    return m_scanning;
}

void ComBLE::startScanning()
{
    qDebug() << "Scanning for devices...";
    m_deviceDiscoveryAgent->start();
}

void ComBLE::stopScanning()
{
    qDebug() << "Scanning stopped.";
    m_deviceDiscoveryAgent->stop();
}

void ComBLE::deviceDetecte(const QBluetoothDeviceInfo &info)
{
    if(info.name().contains("Plot"))
    {
        qDebug() << "Device trouvé !";
        qDebug() << "Nom du périphérique:" << info.name();
        emit deviceDiscovered(info);
    }


}


