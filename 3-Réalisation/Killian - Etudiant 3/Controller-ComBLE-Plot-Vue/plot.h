#ifndef PLOT_H
#define PLOT_H

#include <QObject>

class Plot : public QObject
{
   Q_OBJECT

    Q_PROPERTY(int nvBatterie READ getNvBatterie NOTIFY nvBatterieChanged)

public:
    Plot();
    void lireBatterie(Plot*);
    bool activerPlot(Plot*, QString couleur);
    bool desactiverPlot(Plot*);
    int getNvBatterie();

signals:
    void tempsRecu(Plot*);
    void nvBatterieChanged();

public slots:
    void standBy();


private:
    QString couleur;
    short int nvBatterie;
    short int id;
    QVector<Plot*> listePlot;

};

#endif // PLOT_H
