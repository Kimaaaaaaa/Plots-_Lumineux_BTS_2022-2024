/*Plot.h*/
#ifndef PLOT_H
#define PLOT_H

#include <QObject>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QLowEnergyCharacteristic>
#include <QDebug>
#include <QBluetoothUuid>
#include <QLowEnergyCharacteristic>
#include <QLowEnergyService>
#include <QLowEnergyController>
#include <QTimer>

#define SERVICE_BATTERY_UUID "0000180f-0000-1000-8000-00805f9b34fb"
#define CHARACTERISTIC_BATTERY_UUID "0000180f-0000-1000-8000-00805f9b34fb"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_CHARACTERISTIC_COULEUR "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"
#define UUID_CHARACTERISTIC_TEMPSDEREACTION "8cd233ac-a2ca-450e-a7a2-ea07361b26aa"
#define UUID_CHARACTERISTIC_ID "8cd233ac-a2ca-450e-a7a2-xp94574c14ee"

class ComBLE;


class Plot : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int nvBatterie READ getNvBatterie NOTIFY nvBatterieChanged)
    Q_PROPERTY(QString nom READ getNom NOTIFY nomChanged)
    Q_PROPERTY(bool selected READ getSelected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(int id READ getId NOTIFY idChanged)


public:
    Plot();

    bool activerPlot(Plot*, QString couleur);
    bool desactiverPlot(Plot*);
    void setNvBatterie(int nv);
    int getNvBatterie() const;
    QString getNom() const;

    bool getSelected();
    void setSelected(bool selected);

    QString nom() const;
    void setNom(const QString &nom);
    void setId(int id);

    int getId() const;

    int getNvBatterie();
    QString getNom();
    QLowEnergyController *getControllerBle() const;
    void setControllerBle(QLowEnergyController *newController);
    //void allumerPlot(QString couleur);
    void deconnecterPlot();

     void ecrireCouleurCharacteristic(const QString &couleur);
    void ecrireIDCharacteristic(const QString &id);

     bool getAllume() const;
     void setAllume(bool newAllume);



signals:
    void tempsRecu(Plot*);
    void nomChanged();
    void nvBatterieChanged();
    void selectedChanged();
    void idChanged();
    void selectedPlotsChanged(const int id);
    void characteristicReactiontimeValueChanged(QByteArray reactionTime);




public slots:
    void standBy();
    void writeTimeout();
    void handleCharacteristicChange();






private:
    QString couleur;
    short int nvBatterie;
    QString m_nom;
    bool selected;
    bool allume;
    QLowEnergyController* controllerBle;
    static int s_nextId;
    int m_id;
     QLowEnergyService *servicePlot;


};

#endif // PLOT_H
