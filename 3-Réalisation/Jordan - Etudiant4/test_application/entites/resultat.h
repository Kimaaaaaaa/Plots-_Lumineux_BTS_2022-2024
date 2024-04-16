#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QObject>
#include <QDate>
#include <QJsonObject>
#include "joueur.h"
#include "DataApi/dataResultats.h"

class Resultat : public QObject
{
    Q_OBJECT
public:
    Resultat(QObject *parent = nullptr);
    Resultat(QJsonObject dataJson, QObject *parent = nullptr);

    QString toString();

signals:

private:
    int idPartie;
    QDate date;
    int tempsReactionJ1;
    int tempsReactionJ2;

    Joueur* joueur1;
    Joueur* joueur2;

    QString identifiant;


};

#endif // STATISTIQUES_H
