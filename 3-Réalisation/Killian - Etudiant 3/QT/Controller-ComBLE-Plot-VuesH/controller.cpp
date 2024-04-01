/*Controller.cpp*/

#include "controller.h"
#include "plot.h"
#include <QDebug>

Controller::Controller()
{
    m_com = new ComBLE();

    // Connexion du signal deviceDiscovered à la méthode addPlot du Controller
    connect(m_com, &ComBLE::deviceDiscovered, this, &Controller::addPlot);

    connect(m_com, &ComBLE::deviceScanFinished, this, &Controller::afficherPlots);












}

QQmlListProperty<Plot> Controller::getListePlots()
{
    qDebug() << "Liste plot";
    return QQmlListProperty<Plot>(this, listePlots);
}

QQmlListProperty<Plot> Controller::getListePlotsSelected()
{
    qDebug() << "Liste plot selectionnés";
    return QQmlListProperty<Plot>(this, listePlotsSelected);
}

ComBLE *Controller::com() const { return m_com; }

QString Controller::getNomDernierPlotTrouve()
{
    return this->listePlots.last()->getNom();
}




/*Slot*/

void Controller::startScanning() {

    // Effacer la liste des plots détectés
    qDeleteAll(listePlots);
    listePlots.clear();

    // Émettre le signal indiquant que la liste de plots a changé
    emit listePlotsChanged();

    if(m_com){
        emit statutScanEnCours();
        m_com->startScanning();
    }
}


void Controller::afficherPlots(){
    // Emettre le signal indiquant que la liste de plots a changé
    qDebug()<< listePlots;
    emit listePlotsChanged();

    emit statutScanTermine();
}

void Controller::addSelectedPlots(const int id)
{
    qDebug() << "addSelectedPlots";
    for(int i = 0; i < listePlots.size(); i++)
    {
        if(id == listePlots.at(i)->getId())
        {
            listePlotsSelected.append(listePlots.at(i));
            qDebug() << "Nouveau plot ajouté dans la liste de plot selectionné";
            qDebug() << listePlotsSelected.last()->getId();
        }
    }
}

void Controller::removeSelectedPlots(const int id)
{
    qDebug() << "removeSelectedPlots";
    for(int i = listePlotsSelected.size() - 1; i >= 0; i--)
    {
        if(id == listePlotsSelected.at(i)->getId())
        {
            listePlotsSelected.removeAt(i);
            qDebug() << "Plot " << id << " a été retiré de la liste des plots selectionnés ";
        }
    }
}

void Controller::allumerPlotAleatoire()
{

    qDebug("dqsdsqdsqdqsdsqdsqdqsdsqsdq!!!");
    QString tableauDeCouleur[] = {"red", "blue", "green", "yellow", "white"};
    int lengthTableauDeCouleur = sizeof(tableauDeCouleur) / sizeof(*tableauDeCouleur);
    QString couleurAleatoire = tableauDeCouleur[rand() % lengthTableauDeCouleur];

    int indexPlot = (rand()  % (lengthTableauDeCouleur - 1)); // Index du plot que vous voulez modifier dans votre liste
    qDebug() << "Index : "<< indexPlot;
    int idPlot = listePlotsSelected.at(indexPlot)->getId();

    qDebug()<< "ID Plot : " << idPlot;

    // Vérifier si l'indexPlot est valide
    if (indexPlot >= 0 && indexPlot < listePlotsSelected.size()) {
        // Émettre le signal avec la couleur aléatoire pour le plot avec l'index spécifié
        emit plotAllumeChanged(idPlot, couleurAleatoire);
    } else {
        qDebug() << "Erreur : l'indexPlot est invalide.";
    }

}

int Controller::getIndexByIdSelectedPlot(int id)
{
    int indexPlot = -1;

    for(int i = 0; i < listePlotsSelected.size(); i++)
    {
        if(id == listePlotsSelected.at(i)->getId())
        {
            indexPlot = i;
            qDebug() <<indexPlot;
        }
    }

    return indexPlot;
}





int Controller::getLastPlotId()
{
    return this->listePlots.last()->getId();
}

void Controller::addPlotTest()
{
    for(int i=0; i < 12; i++)
    {
        listePlots.append(new Plot());
    }
}



void Controller::addPlot(const QBluetoothDeviceInfo &deviceInfo)
{




    // Vérifier si le périphérique existe déjà dans la liste des plots
    bool plotExists = false;
    for (Plot *plot : listePlots) {
        if (plot->getNom() == deviceInfo.name()) {
            plotExists = true;
            break;
        }
    }


    // Si le périphérique n'existe pas dans la liste, l'ajouter
    if (!plotExists) {
        // Créer un nouveau plot avec le nom du périphérique et l'ID correspondant à l'index de la ListView
        Plot *newPlot = new Plot();
        newPlot->setNom(deviceInfo.name());
        listePlots.append(newPlot);




        //créer le controller BLE pour le device (plot)
        QLowEnergyController *controllerBle =  QLowEnergyController::createCentral(deviceInfo, this);


        newPlot->setControllerBle(controllerBle);

        // Démarrer la connexion
        controllerBle->connectToDevice();

        connect(m_com, &ComBLE::batterieLue, this, [=](QLowEnergyService* service,const QByteArray &value) {
            qDebug()<< "hehe";
            if (service->serviceUuid() == QBluetoothUuid(QStringLiteral(SERVICE_UUID_BATTERIE))) {
                qDebug()<< value.toInt();
                int battery = value.toInt();
                qDebug()<<listePlots.last();

                this->listePlots.last()->setNvBatterie(battery);


                qDebug()<<listePlots.last()->getNvBatterie();


            }
        });

        m_com->scanServices(controllerBle);







        qDebug() << "L'id du plot est : " << newPlot->getId();
        qDebug() << "Le niveau de batterie du plot est de :" << listePlots.last()->getNvBatterie() << "%";









        qDebug() << "La taille de la liste de plot est de : " << listePlots.size();


   }

    //Pour tester


}





void Controller::couplerPlot(int index)
{
    // Vérifier si l'index est valide
    if (index >= 0 && index < listePlots.count()) {
        // Récupérer le plot correspondant à l'index
        qDebug() << "l'id du plot est" << index;
        Plot *plot = listePlots.at(index);

        // Effectuer le couplage du plot
        plot->activerPlot(plot,"1");
    }
}

/*void Controller::addSelectedPlots(const QVariant &selectedPlotsVariant)
{
    // Vérifier que la variante contient une liste
    if (selectedPlotsVariant.canConvert<QList<int>>()) {
        // Extraire la liste d'identifiants de plots
        QList<int> selectedPlotsIds = selectedPlotsVariant.value<QList<int>>();
        qDebug() << "Selected plots IDs:" << selectedPlotsIds;

        // Effacer la liste des plots sélectionnés actuelle
        listePlotsSelected.clear();

        // Ajouter les plots sélectionnés à la liste
        for (int plotId : selectedPlotsIds) {
            for (Plot *plot : listePlots) {
                if (plot->getId() == plotId) {
                    listePlotsSelected.append(plot);
                    break;
                }
            }
        }

        // Émettre le signal indiquant que la liste des plots sélectionnés a changé
        emit selectedPlotsChanged(selectedPlotsVariant);
    } else {
        qWarning() << "Unable to convert selectedPlotsVariant to QList<int>.";
    }
}


*/
