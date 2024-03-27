/*Controller.h*/
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
    Q_PROPERTY(QQmlListProperty<Plot> listePlotsSelected READ getListePlotsSelected NOTIFY listePlotsSelectedChanged)
    Q_PROPERTY(QString nomDernierPlotTrouve READ getNomDernierPlotTrouve NOTIFY nomDernierPlotTrouveChanged)

               //Ce que l'on veux                //comment on l'a               //signal




public:
    Controller();

    Q_INVOKABLE void couplerPlot(int index);
    Q_INVOKABLE void addSelectedPlots(const int);
    Q_INVOKABLE void removeSelectedPlots(const int);
    Q_INVOKABLE void allumerPlotAleatoire();
    QQmlListProperty<Plot> getListePlots();
    QQmlListProperty<Plot> getListePlotsSelected();
    ComBLE* com() const;
    QString getNomDernierPlotTrouve();
    int getLastPlotId();
    void addPlotTest();








public slots:
    void startScanning();
    void addPlot(const QBluetoothDeviceInfo &deviceInfo);





    void afficherPlots();
signals:
    void listePlotsChanged();
    void comChanged();
    void nomDernierPlotTrouveChanged();
    void listePlotsSelectedChanged();
    void statutScanEnCours();
    void statutScanTermine();
    void batteryValueChanged(const QByteArray &batteryValue);







private:
    QList<Plot*> listePlots;
    QList<Plot*> listePlotsSelected;
    ComBLE * m_com;
    int m_selectedPlotsCount = 0;


};

#endif // CONTROLLER_H
