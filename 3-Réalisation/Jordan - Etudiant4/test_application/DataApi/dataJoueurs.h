#ifndef DATAJOUEURS_H
#define DATAJOUEURS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "entites/joueur.h"

class DataJoueurs : public QObject
{
    Q_OBJECT

public:

    DataJoueurs(QObject *parent=nullptr);
    void createJoueur(const QString &identifiant, const QString &password, const QString &email);
    void connexionJoueur(const QString &identifiant, const QString &password);
    void getJoueurs();
    void getJoueur(const QString &id);
    void identifiantExiste(const QString &identifiant);

signals:
    void connexionReussie(QJsonObject jsonJoueur);
    void connexionEchouee();
    void creationJoueurReussie();
    void creationJoueurEchouee();
    void identifiantVerificationTerminee(bool);


private slots:
    void lireDataGetJoueurs(QNetworkReply *reply);

    void lireDataCreateJoueur(QNetworkReply *reply);

    void lireDataGetJoueur(QNetworkReply *reply);

    void lireDataConnexionJoueur(QNetworkReply *reply);

    void lireDataIdentifiantExiste(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;





};

#endif // DATAJOUEURS_H

