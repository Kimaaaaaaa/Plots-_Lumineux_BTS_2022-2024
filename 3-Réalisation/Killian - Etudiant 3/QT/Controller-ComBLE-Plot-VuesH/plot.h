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

     void ecrireCouleurCharacteristic(const QString &couleur);


     bool getAllume() const;
     void setAllume(bool newAllume);

signals:
    void tempsRecu(Plot*);
    void nomChanged();
    void nvBatterieChanged();
    void selectedChanged();
    void idChanged();
    void selectedPlotsChanged(const int id);




public slots:
    void standBy();
    void writeTimeout();







private:
    QString couleur;
    short int nvBatterie;
    QString m_nom;
    bool selected;
    bool allume;
    QLowEnergyController* controllerBle;
    static int s_nextId;
    int m_id;


};

#endif // PLOT_H
