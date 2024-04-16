/*Controller.h*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <plot.h>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QQmlListProperty>
#include <comble.h>
#include <partie.h>
#include <QRandomGenerator>

class Controller: public QObject
{
    Q_OBJECT


    Q_PROPERTY(QQmlListProperty<Plot> listePlots READ getListePlots NOTIFY listePlotsChanged)
    Q_PROPERTY(QQmlListProperty<Plot> listePlotsSelected READ getListePlotsSelected NOTIFY listePlotsSelectedChanged)
    Q_PROPERTY(QString nomDernierPlotTrouve READ getNomDernierPlotTrouve NOTIFY nomDernierPlotTrouveChanged)

               //Ce que l'on veux                //comment on l'a               //signal




public:
    Controller();


    Q_INVOKABLE void addSelectedPlots(const int);
    Q_INVOKABLE void removeSelectedPlots(const int);
    Q_INVOKABLE void allumerPlotAleatoire();
    Q_INVOKABLE int getIndexByIdSelectedPlot(int index);
    Q_INVOKABLE void changerCouleurPlot(QString couleur, int id);
    Q_INVOKABLE void lancerPartieJ1(int tempsPourAppuyer = 5, int nbCoup = 10, QString couleurJ1 = "red");


    //Q_INVOKABLE int lancerPartie(int temps);
    QQmlListProperty<Plot> getListePlots();
    QQmlListProperty<Plot> getListePlotsSelected();
    ComBLE* com() const;
    QString getNomDernierPlotTrouve();
    int getLastPlotId();
    void addPlotTest();
    void writeDataToDevice(QLowEnergyService *service, const QLowEnergyCharacteristic &characteristic, const QByteArray &data);
    const QList<Plot*> getListeSelectedPlot();
    bool getIsLaunched(bool);
    void tempsDepasse();


    /*QLowEnergyController* getControllerBLE();
    void setControllerBLE(QLowEnergyController * controllerBLE);
    */








public slots:
    void startScanning();
    void addPlot(const QBluetoothDeviceInfo &deviceInfo);
    //void startTimer();
    void nextIteration();
    void eteindreToutLesPlots();
    void plotToucheHandler(int idPlot);






    void afficherPlots();


    void handlePartieLaunchedChanged(bool isLaunched);
signals:
    void listePlotsChanged();
    void comChanged();
    void nomDernierPlotTrouveChanged();
    void listePlotsSelectedChanged();
    void statutScanEnCours();
    void statutScanTermine();
    void batteryValueChanged(const QByteArray &batteryValue);
    void plotAllumeChanged(int idPlotAllume, QVariant colorVariant);
    void plotAllumed(int tempsPourAppuyer);
    void startNextIteration();
    void partieLaunchedChanged(bool);
    void plotTouche(int idPlot);







private:
    QList<Plot*> listePlots;
    QList<Plot*> listePlotsSelected;
    ComBLE * m_com;
    int m_selectedPlotsCount = 0;
    QLowEnergyController *controllerBLE;
    QTimer* m_timer;
    Partie* partie;
    int indexCourant;
    QMetaObject::Connection m_timerConnection;


};

#endif // CONTROLLER_H
