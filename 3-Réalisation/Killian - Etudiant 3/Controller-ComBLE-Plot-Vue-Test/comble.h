/*ComBLE.h*/

#ifndef COMBLE_H
#define COMBLE_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QList>
#include <QLowEnergyCharacteristic>
#include <QLowEnergyService>
#include <QLowEnergyController>
#include <controller.h>

#define SERVICE_UUID_BATTERIE "0000180F-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_UUID_BATTERIE  "0000180F-0000-1000-8000-00805F9B34FB"

class ComBLE : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)

public:
    explicit ComBLE(QObject *parent = nullptr);
    void scanServices(QLowEnergyController *controller);

    bool isScanning() const;

signals:
    void deviceDiscovered(const QBluetoothDeviceInfo &deviceInfo);
    void scanningChanged();
    void deviceScanFinished();
    void deviceScannerCleared();
    void characteristicValueChanged(const QLowEnergyCharacteristic &characteristic, const QByteArray &value);
    void characteristicValuesReady(const QList<QByteArray> &values);
    void serviceDetecte(QLowEnergyService* service);
    void batterieLue(QLowEnergyService* service,  QByteArray newValue);
    void valeurLue(QLowEnergyService* &service, const QByteArray &value);


public slots:
    void startScanning();
    void stopScanning();
    void deviceDetecte(const QBluetoothDeviceInfo &info);
    void terminerScanDevice();

    void serviceStateChanged(QLowEnergyService::ServiceState newState);

    //void lireValeurCharacteristicBattery(QLowEnergyService* service);


    QList<QByteArray> recupererValeurCharacteristic(QLowEnergyService *service);
private:
    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    QList<QLowEnergyService*> listeDeService;
    bool m_scanning;

};

#endif // COMBLE_H
