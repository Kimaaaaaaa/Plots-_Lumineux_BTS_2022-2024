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
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic_Couleur "beb5483e-36e1-4688-b7f5-ea07361b26ab"
#define UUID_CHARACTERISTIC_TEMPSDEREACTION "8cd233ac-a2ca-450e-a7a2-ea07361b26aa"

class ComBLE : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)

public:
    explicit ComBLE(QObject *parent = nullptr);
    void scanServices(QLowEnergyController *controller);

    bool isScanning() const;

    void writeCharacteristic(QLowEnergyController *controller, const QBluetoothUuid &serviceUuid, const QLowEnergyCharacteristic &characteristicUuid, const QByteArray &data);
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
    void plotAppuye(QByteArray newValue);

public slots:
    void startScanning();
    void stopScanning();
    void deviceDetecte(const QBluetoothDeviceInfo &info);
    void terminerScanDevice();

    void serviceStateChanged(QLowEnergyService::ServiceState newState);
    void onCharacteristicValueChanged(const QLowEnergyCharacteristic characteristic, QByteArray newValue);

    //void lireValeurCharacteristicBattery(QLowEnergyService* service);


    QList<QByteArray> recupererValeurCharacteristic(QLowEnergyService *service);
private:
    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    QList<QLowEnergyService*> listeDeService;
    bool m_scanning;

};

#endif // COMBLE_H
