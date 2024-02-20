// bluetoothcom.h
#ifndef BLUETOOTHCOM_H
#define BLUETOOTHCOM_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QBluetoothLocalDevice>

class BluetoothCom : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothCom(QObject *parent = nullptr); // Constructeur de la classe
    ~BluetoothCom(); // Destructeur de la classe

signals:
    void deviceDiscovered(const QBluetoothDeviceInfo &deviceInfo); // Signal émis lorsqu'un périphérique est découvert
    void pairingFinished(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing); // Signal émis lorsque l'appareillage est terminé

public slots:
    void startScan(); // Slot pour démarrer le scan des périphériques
    void stopScan(); // Slot pour arrêter le scan des périphériques
    void pairDevice(const QBluetoothDeviceInfo &device); // Slot pour appairer un périphérique

private slots:
    void deviceDiscoveredHandler(const QBluetoothDeviceInfo &device); // Slot appelé lorsqu'un périphérique est découvert
    void pairingFinishedHandler(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing); // Slot appelé lorsque l'appareillage est terminé

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent; // Agent de découverte des périphériques Bluetooth
    QBluetoothLocalDevice *localDevice; // Périphérique Bluetooth local pour gérer l'appareillage
};

#endif // BLUETOOTHCOM_H
