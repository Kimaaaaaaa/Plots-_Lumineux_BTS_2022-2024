#include "resultat.h"
#include <QQmlEngine>
#include "DataApi/dataResultats.h"


Resultat::Resultat(QObject *parent) : QObject(parent)
{

}


Resultat::Resultat(QJsonObject dataJson, QObject *parent) : QObject(parent){

    //a partir du jsonobject, affecter la valeurs aux attributs

    date = QDate::fromString(dataJson["date"].toString(), "aaaa-mm-jj");
    idPartie = dataJson["idPartie"].toInt();
    tempsReactionJ1 = dataJson["tempsReactionJ1"].toInt();
    tempsReactionJ2 = dataJson["tempsReactionJ2"].toInt();
    identifiant = dataJson["identifiant"].toString();




}


QString Resultat::toString(){



    QString result = "";
    result += "Date : " + date.toString("aaaa-mm-jj") + "\n";
    result += "idPartie : " + QString::number(idPartie) + "\n";
    result += "Temps de réaction Joueur 1 : " + QString::number(tempsReactionJ1) + "\n";
    result += "Temps de réaction Joueur 2 : " + QString::number(tempsReactionJ2) + "\n";
    result += "Identifiant : " + identifiant+ "\n";

    return result;

}








