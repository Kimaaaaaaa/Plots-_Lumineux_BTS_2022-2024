// bluetoothcom.cpp
#include "bluetoothcom.h"

BluetoothCom::BluetoothCom(QObject *parent) : QObject(parent)
{
    // Initialisation de l'agent de découverte Bluetooth
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    // Connexion du signal deviceDiscovered de l'agent de découverte au slot deviceDiscoveredHandler de cette classe
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothCom::deviceDiscoveredHandler);

    // Création du périphérique Bluetooth local
    localDevice = new QBluetoothLocalDevice(this);

    // Connexion du signal pairingFinished du périphérique local au slot pairingFinishedHandler de cette classe
    connect(localDevice, &QBluetoothLocalDevice::pairingFinished,
            this, &BluetoothCom::pairingFinishedHandler);
}

BluetoothCom::~BluetoothCom()
{
    delete discoveryAgent; // Libération de la mémoire de l'agent de découverte
    delete localDevice; // Libération de la mémoire du périphérique Bluetooth local
}

void BluetoothCom::startScan()
{
    discoveryAgent->start(); // Début du scan des périphériques Bluetooth
}

void BluetoothCom::stopScan()
{
    discoveryAgent->stop(); // Arrêt du scan des périphériques Bluetooth
}

void BluetoothCom::pairDevice(const QBluetoothDeviceInfo &device)
{
    // Demande d'appareillage pour le périphérique spécifié
    localDevice->requestPairing(device.address(), QBluetoothLocalDevice::Paired);
}

void BluetoothCom::deviceDiscoveredHandler(const QBluetoothDeviceInfo &device)
{
    emit deviceDiscovered(device); // Émission du signal deviceDiscovered avec les informations du périphérique découvert
}

void BluetoothCom::pairingFinishedHandler(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    emit pairingFinished(address, pairing); // Émission du signal pairingFinished avec les informations sur l'appareillage terminé
}
