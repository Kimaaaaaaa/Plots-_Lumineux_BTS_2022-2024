#ifndef PLOT_H
#define PLOT_H

#include <QObject>

class Plot : public QObject
{
   Q_OBJECT

    Q_PROPERTY(int nvBatterie READ getNvBatterie NOTIFY nvBatterieChanged)
    Q_PROPERTY(QString nom READ getNom NOTIFY nomChanged )



public:
    Plot();
    void lireBatterie(Plot*);
    bool activerPlot(Plot*, QString couleur);
    bool desactiverPlot(Plot*);
    int getNvBatterie();
    QString getNom();

    QString nom() const;
    void setNom(const QString &nom);

    int getId() const;


signals:
    void tempsRecu(Plot*);
    void nvBatterieChanged();
    void nomChanged();

public slots:
    void standBy();


private:
    QString couleur;
    short int nvBatterie;
    QVector<Plot*> listePlot;
    QString m_nom;
    static int s_nextId; // Variable statique pour le prochain identifiant
    int m_id;

};

#endif // PLOT_H
