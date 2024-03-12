#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <plot.h>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QQmlListProperty>

class Controller: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<Plot> listePlots READ getListePlots NOTIFY listePlotsChanged)

public:
    Controller();

    QQmlListProperty<Plot> getListePlots();


public slots:


signals:
    void listePlotsChanged();

private:
    QList<Plot*> listePlots;

};

#endif // CONTROLLER_H
