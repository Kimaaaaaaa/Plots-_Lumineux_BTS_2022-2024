#ifndef DATARESULTATS_H
#define DATARESULTATS_H

#include <QObject>
#include <QNetworkAccessManager>
#include "entites/resultat.h"

class DataResultats : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QJsonObject statistiques READ getStatistiques NOTIFY statistiquesChanger)

public:


    DataResultats(QObject *parent=nullptr);

    void getStatistiques();

    void getUnepartie(const QString &id);

    void createPartie(const QString &date, const int tempsReactionJ1, const int tempsReactionJ2, const int joueur1_id, const int joueur2_id);

    void createConfig(const QString couleurPlot, int nbJoueur, int nbPlots, int tempsPourAppuyer, int nbPlotsAppuyes);


signals:

    void creationPartieReussie();
    void creationPartieEchouee();

    void creationConfigReussie();
    void creationConfigEchouee();

    void statistiquesChanger();

private slots:

    void lireDataGetStatistiques(QNetworkReply *reply);

    void lireDataGetPartie(QNetworkReply *reply);

    void lireDataCreatePartie(QNetworkReply *reply);

    void lireDataCreateConfig(QNetworkReply *reply);


private:
    QNetworkAccessManager *manager;





};

#endif // DATARESULTATS_H

