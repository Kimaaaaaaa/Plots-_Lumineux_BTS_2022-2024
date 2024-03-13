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
    QString getNom();

    QString nom() const;
    void setNom(const QString &nom);


signals:
    void tempsRecu(Plot*);
    void nvBatterieChanged();
    void nomChanged();

public slots:
    void standBy();


private:
    QString couleur;
    short int nvBatterie;
    short int id;
    QVector<Plot*> listePlot;
    QString m_nom;

};

#endif // PLOT_H
