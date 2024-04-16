#include "controller.h"
#include <QObject>



Controller::Controller(DataJoueurs*  dataJoueurs,  DataResultats*  dataResultats, QObject *parent) : QObject(parent)
{
    this->dataJoueurs = dataJoueurs;
    this->dataResultats = dataResultats;
    this->joueurConnecte = nullptr;
}



void Controller::createJoueur(const QString &identifiant, const QString &password, const QString &email)
{
    dataJoueurs->createJoueur(identifiant, password,email);

    connect(dataJoueurs, &DataJoueurs::creationJoueurReussie, this, &Controller::lireCreateJoueurReussie);
}

void Controller::lireCreateJoueurReussie()
{
    emit creationJoueurReussie();
}

void Controller::lireCreateJoueurEchoue()
{
    emit creationJoueurEchoue();
}

void Controller ::connexionJoueur(const QString &identifiant, const QString &password)
{



    dataJoueurs->connexionJoueur(identifiant, password);

    connect(dataJoueurs, &DataJoueurs::connexionReussie, this, &Controller::lireConnexionJoueurReussie);


}

void Controller::lireConnexionJoueurReussie(QJsonObject jsonJoueur)
{
    joueurConnecte = new Joueur(jsonJoueur["identifiant"].toString(),jsonJoueur["id"].toInt(),jsonJoueur["email"].toString(),jsonJoueur["password"].toString());

    emit connexionJoueurReussie();
}

void Controller::lireConnexionJoueurEchoue()
{
    emit connexionJoueurEchoue();
}

bool Controller::testerJoueurConnecte()
{
    return joueurConnecte!=nullptr;
}

/*void Controller::identifiantExiste(const QString &identifiant)
{


}*/

QJsonObject Controller::getStatistiques()
{
    QJsonObject statistiques;
    qDebug() << "Liste stats : ";
    return statistiques;
}






/*void Controller::getStatistiques()
{

    dataResultats->getStatistiques();

    connect(dataResultats, &DataResultats::statistiquesChanger, this, &Controller::lireStatistiques);


}*/



void Controller::lireStatistiques()
{

 emit statistiquesChanger();

}


void Controller::getUnepartie(const QString &identifiant)
{
    dataResultats->getUnepartie(identifiant);

    connect(dataResultats, &DataResultats::statistiquesChanger, this, &Controller::lireStatistiques);


}



void Controller::createConfig(const QString couleurPlot, int nbJoueur, int nbPlots, int tempsPourAppuyer, int nbPlotsAppuyes)
{
    dataResultats->createConfig(couleurPlot,nbJoueur,nbPlots,tempsPourAppuyer,nbPlotsAppuyes);

    connect(dataResultats, &DataResultats::creationConfigReussie, this, &Controller::lireCreateConfigReussie);
}

void Controller::lireCreateConfigReussie()
{
    emit creationConfigReussie();
}

void Controller::lireCreateConfigEchouee()
{
    emit creationConfigEchouee();
}









