#include <QCoreApplication>
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include "monmoduleqml.h"
#include <QDebug>

MonModuleQML::MonModuleQML(QObject *parent) : QObject(parent)
{

}

void MonModuleQML::ajouterJoueurCpp(const QString &password, const QString &email, const QString &identifiant)
{
    // Connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("plots_lumineux");
    db.setUserName("root");
    db.setPassword("");

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);

    query.prepare("INSERT INTO joueurs (password, email, identifiant) VALUES (?, ?, ?)");
    query.addBindValue(password);
    query.addBindValue(email);
    query.addBindValue(identifiant);

    if (query.exec()) {
        qDebug() << "Joueur ajouté avec succès.";
    } else {
        qDebug() << "Erreur lors de l'ajout du joueur:" << query.lastError().text();
    }

    db.close();
    qDebug() << "Ajout du joueur :" << identifiant << "Email :" << email << "Mot de passe :" << password;
}




void MonModuleQML::recupererDonneesJoueurs(const QString &password, const QString &identifiant)
 {
    // Connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("plots_lumineux");
    db.setUserName("root");
    db.setPassword("");

    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);

    query.prepare("SELECT password ,identifiant FROM joueurs");
    query.addBindValue(password);
    query.addBindValue(identifiant);

    if (query.exec()) {
        qDebug() << "Joueur ajouté avec succès.";
    } else {
        qDebug() << "Erreur lors de l'ajout du joueur:" << query.lastError().text();
    }

    db.close();
    qDebug() << "Joueur :" << identifiant << "Mot de passe :" << password;
}






