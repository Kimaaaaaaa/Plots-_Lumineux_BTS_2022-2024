/*Controller.cpp*/

#include "controller.h"
#include "plot.h"
#include <QDebug>

#define SERVICE_BATTERY_UUID "00002A19-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_BATTERY_UUID_TX  "0000180F-0000-1000-8000-00805F9B34FB"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic_Couleur "beb5483e-36e1-4688-b7f5-ea07361b26ab"

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

void Controller::tempsDepasse()
{
    qDebug()<< "Temps depassé, coup suivant";
    //éteindre tout les plots pendant 1 seconde
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

    int indexPlot = rand()  % listePlotsSelected.size(); // Index du plot que vous voulez modifier dans votre liste
    qDebug() << "Index : "<< indexPlot;
    int idPlot = listePlotsSelected.at(indexPlot)->getId();


    listePlotsSelected.at(indexPlot)->ecrireCouleurCharacteristic(couleurAleatoire);

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

const QList<Plot *> Controller::getListeSelectedPlot()
{
    return listePlotsSelected;
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
                qDebug()<< value << "!!";
                int battery = value.toInt();
                qDebug() << "Batterie = " << battery;
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

void Controller::startTimer(int tempsPourAppuyer)
{
    qDebug() << "Timer lancé de : " << tempsPourAppuyer << "s";

    QTimer timer(this);
    connect(&timer, &QTimer::timeout, this, &Controller::tempsDepasse);
    qDebug() << "Temps : " << tempsPourAppuyer * 1000;
    timer.start(tempsPourAppuyer * 1000); //Conversion en ms


}

void Controller::changerCouleurPlot(QString couleur, int id) {

    const QList<Plot*> listePlot = getListeSelectedPlot();

    // Maintenant vous pouvez parcourir listePlot et faire le traitement nécessaire
    for (Plot* plot : listePlot) {
        if (plot->getId() == id) {
            plot->ecrireCouleurCharacteristic(couleur);
            emit plotAllumeChanged(id, couleur);
            break; // Sortir de la boucle après avoir trouvé le plot
        }
    }
}

void Controller::lancerPartieJ1(int tempsPourAppuyer, int nbCoup, QString couleurJ1 )
{
    Partie* newPartie = new Partie(tempsPourAppuyer, nbCoup, couleurJ1); // Création d'une nouvelle partie

    // Initialisation des variables


    // Connexion du signal pour démarrer le premier tour
    connect(this, &Controller::startNextIteration, this, &Controller::nextIteration);

    // Émettre le signal pour démarrer le premier tour
    emit startNextIteration(newPartie,tempsPourAppuyer, nbCoup, couleurJ1);
}


void Controller::nextIteration(Partie* partie, int tempsPourAppuyer, int nbCoup, QString couleurJ1)
{
    if (partie->getTourCourant() < nbCoup) {
            // Sélectionner un plot aléatoire
            if (!listePlotsSelected.isEmpty()) {
                int randomIndex = QRandomGenerator::global()->bounded(0, listePlotsSelected.size());

                // Modifier le plot sélectionné
                listePlotsSelected.at(randomIndex)->ecrireCouleurCharacteristic(couleurJ1);
                emit plotAllumeChanged(listePlotsSelected.at(randomIndex)->getId(), couleurJ1);

                // Démarrer le timer pour ce plot
                QTimer* timer = new QTimer(this);
                connect(timer, &QTimer::timeout, this, &Controller::tempsDepasse);
                timer->start(tempsPourAppuyer * 1000); // Conversion en millisecondes

                // Augmenter le compteur d'itération
                partie->setTourCourant(partie->getTourCourant()+1);
            } else {
                qDebug() << "La liste des plots sélectionnés est vide.";
                return; // Arrêter si la liste est vide
            }
        } else {
            qDebug() << "Nombre d'itérations terminé.";
            return; // Fin de la partie
        }
}






/*QLowEnergyController* Controller::getControllerBLE()
{
    return controllerBLE;
}

void Controller::setControllerBLE(QLowEnergyController* controllerBLE)
{
    this->controllerBLE = controllerBLE;
}
*/

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
