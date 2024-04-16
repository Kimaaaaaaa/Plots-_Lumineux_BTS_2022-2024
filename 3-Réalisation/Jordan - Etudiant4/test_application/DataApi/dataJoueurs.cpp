#include "dataJoueurs.h"
#include <QNetworkReply>
#include <QDebug>
#include <QQmlContext>

DataJoueurs::DataJoueurs(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}




void DataJoueurs::getJoueurs()
{
    connect(manager, &QNetworkAccessManager::finished,
            this, &DataJoueurs::lireDataGetJoueurs);
    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurJoueurs.php"));
    manager->get(request);
}



void DataJoueurs::lireDataGetJoueurs(QNetworkReply *reply)
{
    QString dataJson(reply->readAll());
    qDebug() << "Data Json Date : " << dataJson;
}














void DataJoueurs::connexionJoueur(const QString &identifiant, const QString &password)
{
    QByteArray postData;
    postData.append("identifiant=" + QUrl::toPercentEncoding(identifiant));
    postData.append("&password=" + QUrl::toPercentEncoding(password));


    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeursConnexion.php"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    connect(manager, &QNetworkAccessManager::finished, this, &DataJoueurs::lireDataConnexionJoueur);
    manager->post(request, postData);
}

void DataJoueurs::lireDataConnexionJoueur(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Réponse du serveur:" << responseData;


        QJsonParseError jsonError;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData, &jsonError);

        if (jsonResponse.isObject()) {
            QJsonObject jsonObject = jsonResponse.object();
            if (jsonObject.contains("statut")) {
                int statut = jsonObject["statut"].toInt();
                if (statut == 1) {

                    if (jsonObject.contains("joueur")) {
                        if (jsonObject["joueur"].isObject()) {
                            emit connexionReussie(jsonObject["joueur"].toObject());
                            qDebug() << "Connexion réussie.";

                        } else {
                            emit connexionEchouee();
                            qDebug() << "Identifiants incorrects.";
                        }
                    } else {
                        emit connexionEchouee();
                        qDebug() << "Identifiants incorrects.";
                    }
                    return;
                }
            }
        }

    }
}


void DataJoueurs::identifiantExiste(const QString &identifiant)
{
    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurVerificationIdentifiant.php?identifiant=" + identifiant));
    connect(manager, &QNetworkAccessManager::finished, this, &DataJoueurs::lireDataIdentifiantExiste);
    manager->get(request);
}

void DataJoueurs::lireDataIdentifiantExiste(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);

        if (jsonResponse.isObject()) {
            QJsonObject jsonObject = jsonResponse.object();
            if (jsonObject.contains("identifiantExiste")) {
                bool existe = jsonObject["identifiantExiste"].toBool();
                emit identifiantVerificationTerminee(existe);
            }
        }
    }
}




















void DataJoueurs::createJoueur(const QString &identifiant, const QString &password, const QString &email)
{
    QByteArray postData;
    postData.append("identifiant=" + QUrl::toPercentEncoding(identifiant));
    postData.append("&password=" + QUrl::toPercentEncoding(password));
    postData.append("&email=" + QUrl::toPercentEncoding(email));

    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurInscription.php"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    connect(manager, &QNetworkAccessManager::finished, this, &DataJoueurs::lireDataCreateJoueur);

    manager->post(request, postData);
}

void DataJoueurs::lireDataCreateJoueur(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Réponse du serveur :" << responseData;


        QJsonParseError jsonError;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData, &jsonError);

        if (jsonResponse.isObject()) {
            QJsonObject jsonObject = jsonResponse.object();
            if (jsonObject.contains("statut")) {
                int statut = jsonObject["statut"].toInt();
                if (statut == 1) {

                    if (jsonObject.contains("joueur") && jsonObject["joueur"].isObject()) {
                        emit creationJoueurReussie();
                        qDebug() << "Joueur créé avec succès.";
                    } else {
                        emit creationJoueurEchouee();
                        qDebug() << "Erreur lors de la création du joueur.";
                    }
                    return;
                }
            }
        }
    }
}




void DataJoueurs::getJoueur(const QString &id)
{
    connect(manager, &QNetworkAccessManager::finished,
            this, &DataJoueurs::lireDataGetJoueur);
    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurJoueurs.php?id=" + id));
    manager->get(request); // récupérer le joueur spécifié par identifiant
}

void DataJoueurs::lireDataGetJoueur(QNetworkReply *reply)
{
    QString dataJson(reply->readAll());
    qDebug() << "Data Json Joueur : " << dataJson;
}
