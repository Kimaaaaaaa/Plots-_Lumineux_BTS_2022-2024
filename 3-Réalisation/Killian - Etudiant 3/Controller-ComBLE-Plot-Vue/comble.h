#ifndef COMBLE_H
#define COMBLE_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QList>

class ComBLE : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)

public:
    explicit ComBLE(QObject *parent = nullptr);

    bool isScanning() const;

signals:
    void deviceDiscovered(const QBluetoothDeviceInfo &deviceInfo);
    void scanningChanged();

public slots:
    void startScanning();
    void stopScanning();
    void deviceDetecte(const QBluetoothDeviceInfo &info);

private:
    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    bool m_scanning;

};

#endif // COMBLE_H
