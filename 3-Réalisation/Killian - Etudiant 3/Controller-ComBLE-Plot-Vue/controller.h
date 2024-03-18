#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <plot.h>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QQmlListProperty>
#include <comble.h>

class Controller: public QObject
{
    Q_OBJECT


    Q_PROPERTY(QQmlListProperty<Plot> listePlots READ getListePlots NOTIFY listePlotsChanged)
    Q_PROPERTY(QString nomDernierPlotTrouve READ getNomDernierPlotTrouve NOTIFY nomDernierPlotTrouveChanged)
               //Ce que l'on veux                //comment on l'a               //signal



public:
    Controller();
    Q_INVOKABLE void couplerPlot(int index);
    Q_INVOKABLE int getIdPlot();
    QQmlListProperty<Plot> getListePlots();
    ComBLE* com() const;
    void setCom(ComBLE* com) { m_com = com; emit comChanged(); }
    QString getNomDernierPlotTrouve();






public slots:
    void startScanning();
    void addPlot(const QBluetoothDeviceInfo &deviceInfo);

    void afficherPlots();
signals:
    void listePlotsChanged();
    void comChanged();
    void nomDernierPlotTrouveChanged();

    void statutScanEnCours();
    void statutScanTermine();

private:
    QList<Plot*> listePlots;
    ComBLE * m_com;

};

#endif // CONTROLLER_H
