#include "dataResultats.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QQmlContext>

DataResultats::DataResultats(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}


void DataResultats::getStatistiques()
{
    connect(manager, &QNetworkAccessManager::finished,
            this, &DataResultats::lireDataGetStatistiques);
    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurStatistiques.php"));
    manager->get(request);

}

void DataResultats::lireDataGetStatistiques(QNetworkReply *reply)
{
    QString dataJson(reply->readAll());
    qDebug() << "Data Json Statistiques : " << dataJson;
}



void DataResultats::createPartie(const QString &date, int tempsReactionJ1, int tempsReactionJ2, int joueur1_id, int joueur2_id)
{
    QByteArray postData;
    postData.append("date=" + QUrl::toPercentEncoding(date));
    postData.append("&tempsReactionJ1=" + QByteArray::number(tempsReactionJ1));
    postData.append("&tempsReactionJ2=" + QByteArray::number(tempsReactionJ2));
    postData.append("&joueur1_id=" + QByteArray::number(joueur1_id));
    postData.append("&joueur2_id=" + QByteArray::number(joueur2_id));

    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurCreatePartie.php"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    connect(manager, &QNetworkAccessManager::finished, this, &DataResultats::lireDataCreatePartie);

    manager->post(request, postData);
}

void DataResultats::lireDataCreatePartie(QNetworkReply *reply)
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

                    if (jsonObject.contains("partie") && jsonObject["partie"].isObject()) {
                        emit creationPartieReussie();
                        qDebug() << "Partie créée avec succès.";
                    } else {
                        emit creationPartieEchouee();
                        qDebug() << "Erreur lors de la création de la partie.";
                    }
                    return;
                }
            }
        }
    }
}




 void  DataResultats:: createConfig(const QString couleurPlot, int nbJoueur, int nbPlots, int tempsPourAppuyer, int nbPlotsAppuyes)
 {

     QByteArray postData;
     postData.append("couleurPlot=" + QUrl::toPercentEncoding(couleurPlot));
     postData.append("&nbJoueur=" + QByteArray::number(nbJoueur));
     postData.append("&nbPlots=" + QByteArray::number(nbPlots));
     postData.append("&tempsPourAppuyer=" + QByteArray::number(tempsPourAppuyer));
     postData.append("&nbPlotsAppuyes=" + QByteArray::number(nbPlotsAppuyes));

     QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurCreateConfig.php"));
     request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
     connect(manager, &QNetworkAccessManager::finished, this, &DataResultats::lireDataCreateConfig);

     manager->post(request, postData);

 }


 void DataResultats::lireDataCreateConfig(QNetworkReply *reply)
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

                     if (jsonObject.contains("configpartie") && jsonObject["configpartie"].isObject()) {
                         emit creationConfigReussie();
                         qDebug() << "Config créé avec succès.";
                     } else {
                         emit creationConfigEchouee();
                         qDebug() << "Erreur lors de la création de la config.";
                     }
                     return;
                 }
             }
         }
     }
 }











void DataResultats::getUnepartie(const QString &identifiant)
{
    connect(manager, &QNetworkAccessManager::finished,
            this, &DataResultats::lireDataGetPartie); // Correction: Connecter au bon slot
    QNetworkRequest request(QUrl("http://localhost:8080/testApi/routeurPartie.php?id=" + identifiant));
    manager->get(request);
}

void DataResultats::lireDataGetPartie(QNetworkReply *reply)
{
    QString dataJson(reply->readAll());
    qDebug() << "Data Json Joueur : " << dataJson;
}






// Dans dataResultats.cpp
#include "dataResultats.h"

// Assurez-vous d'inclure la classe de résultat si nécessaire





