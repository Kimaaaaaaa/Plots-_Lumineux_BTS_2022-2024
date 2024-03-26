/*Plot.h*/
#ifndef PLOT_H
#define PLOT_H

#include <QObject>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QLowEnergyCharacteristic>
#include <QDebug>
#include <QBluetoothUuid>

class ComBLE;


class Plot : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int nvBatterie READ getNvBatterie NOTIFY nvBatterieChanged)
    Q_PROPERTY(QString nom READ getNom NOTIFY nomChanged)
    Q_PROPERTY(bool selected READ getSelected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(int idPlot READ getId WRITE setId)

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

signals:
    void tempsRecu(Plot*);
    void nomChanged();
    void nvBatterieChanged();
    void selectedChanged();


public slots:
    void standBy();




private:
    QString couleur;
    short int nvBatterie;
    QString m_nom;
    bool selected;
    QLowEnergyController* controllerBle;


    int m_id;
};

#endif // PLOT_H
