#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "DataApi/dataJoueurs.h"
#include "DataApi/dataResultats.h"
#include <QQmlListProperty>

class Controller : public QObject
{
    Q_OBJECT


public:


    explicit Controller(DataJoueurs* dataJoueurs, DataResultats* dataResultats, QObject *parent = nullptr);
    Q_INVOKABLE void createJoueur(const QString &identifiant, const QString &password, const QString &email);
    Q_INVOKABLE void connexionJoueur(const QString &identifiant, const QString &password);
    Q_INVOKABLE void createConfig(const QString couleurPlot, const int nbJoueur, int nbPlots, const int tempsPourAppuyer, const int nbPlotsAppuyes);
    void identifiantExiste(const QString &identifiant);

    QJsonObject getStatistiques();

    void getUnepartie(const QString &identifiant);

    Q_INVOKABLE bool testerJoueurConnecte();


signals:
    void creationJoueurReussie();
    void creationJoueurEchoue();
    void connexionJoueurReussie();
    void connexionJoueurEchoue();
    void statistiquesChanger();

    void creationConfigReussie();
    void creationConfigEchouee();

public slots:
    void lireCreateJoueurReussie();
    void lireCreateJoueurEchoue();
    void lireCreateConfigReussie();
    void lireCreateConfigEchouee();
    void lireConnexionJoueurReussie(QJsonObject jsonJoueur);
    void lireConnexionJoueurEchoue();
    void lireStatistiques();

private:
    DataJoueurs* dataJoueurs;
    Joueur* joueurConnecte;
    DataResultats* dataResultats;
};

#endif // CONTROLLER_H
