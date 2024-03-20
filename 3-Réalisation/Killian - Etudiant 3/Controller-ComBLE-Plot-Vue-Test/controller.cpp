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
    return QQmlListProperty<Plot>(this, listePlots);
}

ComBLE *Controller::com() const { return m_com; }

QString Controller::getNomDernierPlotTrouve()
{
    return this->listePlots.takeLast()->getNom();
}

int Controller::getIdPlot()
{
    // Vérifiez d'abord si la liste des plots n'est pas vide
    if (!listePlots.isEmpty()) {
        // Récupérez le dernier plot ajouté dans la liste
        Plot *lastPlot = listePlots.last();

        // Vérifiez si le dernier plot est valide (non nul)
        if (lastPlot) {
            // Obtenez l'ID du dernier plot
            return lastPlot->getId();
        }
    }

    // Retournez une valeur par défaut si la liste des plots est vide ou si le dernier plot est nul
    return -1;
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
    emit listePlotsChanged();

    emit statutScanTermine();
}

/*TEST*/

/*
void Controller::addPlot(const QBluetoothDeviceInfo &deviceInfo)
{
    //if(deviceInfo.name().contains("Plot")) {
        // Créer un nouveau plot avec le nom du périphérique
        Plot *newPlot = new Plot();
        newPlot->setNom(deviceInfo.name());

        // Ajoutez le nouveau plot à la liste
        listePlots.append(newPlot);


    //}
}*/
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
        newPlot->setId(listePlots.size() + 1); // Utiliser la taille actuelle de la liste comme ID du plot
         connect(this, &Controller::batteryValueChanged, newPlot, &Plot::affecterBatterie);
        qDebug() << "L'id du plot est : " << newPlot->getId();

        //créer le controller BLE pour le device (plot)
        QLowEnergyController *controllerBle =  QLowEnergyController::createCentral(deviceInfo, this);





        newPlot->setControllerBle(controllerBle);

        // Démarrer la connexion
        controllerBle->connectToDevice();

        m_com->scanServices(controllerBle);

        connect(this, &Controller::batteryValueChanged, newPlot, &Plot::affecterBatterie);





    }

    qDebug() << "La taille de la liste de plot est de : " << listePlots.size();
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


