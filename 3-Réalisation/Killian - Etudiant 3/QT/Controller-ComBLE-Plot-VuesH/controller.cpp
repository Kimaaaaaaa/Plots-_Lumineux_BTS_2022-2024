/*Controller.cpp*/

#include "controller.h"
#include "plot.h"
#include <QDebug>



Controller::Controller()
{
    m_com = new ComBLE();
    m_timer = new QTimer(this);
    partie = nullptr;

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

    QString tableauDeCouleur[] = {"red", "blue", "green", "yellow", "white"};
    int lengthTableauDeCouleur = sizeof(tableauDeCouleur) / sizeof(*tableauDeCouleur);
    QString couleurAleatoire = tableauDeCouleur[rand() % lengthTableauDeCouleur];

    int indexPlot = rand()  % listePlotsSelected.size(); // Index du plot que vous voulez modifier dans votre liste
    qDebug() << "Index : "<< indexPlot;
    int idPlot = listePlotsSelected.at(indexPlot)->getId();


    listePlotsSelected.at(indexPlot)->ecrireCouleurCharacteristic(couleurAleatoire);
    //Garder en mémoire l'id du dernier plot allumer
    idDuDernierPlotAllume = idPlot;

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



const QList<Plot *> Controller::getListeSelectedPlot()
{
    return listePlotsSelected;
}

bool Controller::getIsLaunched(bool)
{
    return partie->getIsLaunched();
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

        //Venire écrire dans la characteristique id


        //créer le controller BLE pour le device (plot)
        QLowEnergyController *controllerBle =  QLowEnergyController::createCentral(deviceInfo, this);


        newPlot->setControllerBle(controllerBle);

        // Démarrer la connexion
        controllerBle->connectToDevice();

        connect(m_com, &ComBLE::batterieLue, this, [=](QLowEnergyService* service,const QByteArray &value) {
            if (service->serviceUuid() == QBluetoothUuid(QStringLiteral(SERVICE_UUID_BATTERIE))) {
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

    affecterIDCharacteristique();


    //Instanciation d'une nouvelle partie

    partie = new Partie(tempsPourAppuyer, nbCoup, couleurJ1); // Création d'une nouvelle partie
    connect(this->m_com, &ComBLE::plotAppuye, this, &Controller::handleReactiontime);
    partie->setIsLaunched(true);



    // Connexion du signal pour démarrer le premier tour
    connect(this, &Controller::startNextIteration, this, &Controller::nextIteration);

    isMode1J = true;
    isMode2J = false;

    emit startNextIteration();
}

void Controller::lancerPartieJ2(int tempsPourAppuyer, int nbCoup, QString couleurJ1, QString couleurJ2)
{

    affecterIDCharacteristique();


    //Instanciation d'une nouvelle partie

    partie = new Partie(tempsPourAppuyer, nbCoup, couleurJ1, couleurJ2); // Création d'une nouvelle partie
    connect(this->m_com, &ComBLE::plotAppuye, this, &Controller::handleReactiontime);
    partie->setIsLaunched(true);


    // Connexion du signal pour démarrer le premier tour
    connect(this, &Controller::startNextIteration, this, &Controller::nextIteration);


    isMode1J = false;
    isMode2J = true;


    emit startNextIteration();


}

void Controller::affecterIDCharacteristique()
{

    for(int i = 0; i < listePlotsSelected.size(); i++)
    {
        //ecrireIDCharacteristic(listePlotsSelected.at(i)->getId());
    }
}


void Controller::nextIteration()
{

    qDebug("NEXT ITERATION");
    // Augmenter le compteur d'itération
    partie->setTourCourant(partie->getTourCourant()+1);

    if(partie->getCouleurJ1() == "random")
    {
        partie->setIsColorRandom(true);
    }
    else{
        partie->setIsColorRandom(false);

    }


    if (partie->getIsColorRandom() && isMode1J) {
        QList<QString> listeDeCouleur;

        listeDeCouleur.append("white");
        listeDeCouleur.append("red");
        listeDeCouleur.append("yellow");
        listeDeCouleur.append("blue");
        listeDeCouleur.append("green");

        // Generate a random index
        int randomIndex = rand() % listeDeCouleur.size();

        // Retrieve a random color from the list
        partie->setCouleurJ1(listeDeCouleur.at(randomIndex));
    }




    if(isMode1J)
    {
        if (partie->getTourCourant() < partie->getNbCoup()) {
            // Sélectionner un plot aléatoire
            if (!listePlotsSelected.isEmpty()) {
                indexCourant = QRandomGenerator::global()->bounded(0, listePlotsSelected.size());
                partie->setRandomIndex(indexCourant);


                // Allumer le plot sélectionné
                listePlotsSelected.at(indexCourant)->ecrireCouleurCharacteristic(partie->getCouleurJ1());
                idDuDernierPlotAllume = listePlotsSelected.at(indexCourant)->getId();
                emit plotAllumeChanged(listePlotsSelected.at(indexCourant)->getId(), partie->getCouleurJ1());
                listePlotsSelected.at(indexCourant)->setAllume(true);







                //connecter timer

                connect(m_timer, &QTimer::timeout, this, &Controller::eteindreToutLesPlots );
                //connect appui
                connect(m_com, &ComBLE::plotAppuye, this ,&Controller::handleReactiontime);



                // Démarrer le timer pour ce plot
                m_timer->setSingleShot(true);
                m_timer->start(partie->getTempsPourAppuyer() * 1000);





                qDebug() << "Tour courant : " << partie->getTourCourant();


            } else {
                qDebug() << "La liste des plots sélectionnés est vide.";
                return; // Arrêter si la liste est vide
            }
        } else {
            qDebug() << "Nombre d'itérations terminé.";
            partie->setIsLaunched(false);






            delete partie;

            return; // Fin de la partie
        }

    }
    else if(isMode1J == false && isMode2J == true)
    {
        //faire la logique pour le mode 2 joueurs
        QList <QString>  listeCouleurJ1J2;
        listeCouleurJ1J2.append(partie->getCouleurJ1());
        listeCouleurJ1J2.append(partie->getCouleurJ2());

        if (partie->getTourCourant() < (partie->getNbCoup() * 2)) {
            //pair = Joueur 1
            //impair = Joueur 2

            if(partie->getTourCourant() % 2 == 0)
            {
                    //Tour Joueur 1
                    if (!listePlotsSelected.isEmpty()) {
                        indexCourant = QRandomGenerator::global()->bounded(0, listePlotsSelected.size());
                        partie->setRandomIndex(indexCourant);


                        // Allumer le plot sélectionné
                        listePlotsSelected.at(indexCourant)->ecrireCouleurCharacteristic(partie->getCouleurJ1());
                        idDuDernierPlotAllume = listePlotsSelected.at(indexCourant)->getId();
                        emit plotAllumeChanged(listePlotsSelected.at(indexCourant)->getId(), partie->getCouleurJ1());
                        listePlotsSelected.at(indexCourant)->setAllume(true);







                        //connecter timer

                        connect(m_timer, &QTimer::timeout, this, &Controller::eteindreToutLesPlots );
                        //connect appui
                        connect(m_com, &ComBLE::plotAppuye, this ,&Controller::handleReactiontime);



                        // Démarrer le timer pour ce plot
                        m_timer->setSingleShot(true);
                        m_timer->start(partie->getTempsPourAppuyer() * 1000);





                        qDebug() << "Tour courant : " << partie->getTourCourant();


                    } else {
                        qDebug() << "La liste des plots sélectionnés est vide.";
                        return; // Arrêter si la liste est vide
                    }

            }
            else{
                if (!listePlotsSelected.isEmpty()) {
                    indexCourant = QRandomGenerator::global()->bounded(0, listePlotsSelected.size());
                    partie->setRandomIndex(indexCourant);


                    // Allumer le plot sélectionné
                    listePlotsSelected.at(indexCourant)->ecrireCouleurCharacteristic(partie->getCouleurJ2());
                    idDuDernierPlotAllume = listePlotsSelected.at(indexCourant)->getId();
                    emit plotAllumeChanged(listePlotsSelected.at(indexCourant)->getId(), partie->getCouleurJ2());
                    listePlotsSelected.at(indexCourant)->setAllume(true);







                    //connecter timer

                    connect(m_timer, &QTimer::timeout, this, &Controller::eteindreToutLesPlots );
                    //connect appui
                    connect(m_com, &ComBLE::plotAppuye, this ,&Controller::handleReactiontime);



                    // Démarrer le timer pour ce plot
                    m_timer->setSingleShot(true);
                    m_timer->start(partie->getTempsPourAppuyer() * 1000);





                    qDebug() << "Tour courant : " << partie->getTourCourant();


                } else {
                    qDebug() << "La liste des plots sélectionnés est vide.";
                    return; // Arrêter si la liste est vide
                }

            }


        }
        else{
                qDebug() << "Nombre d'itérations terminé.";
                partie->setIsLaunched(false);

                delete partie;

                return; // Fin de la partie
        }


    }


}

void Controller::eteindreToutLesPlots()
{
    disconnect(m_timer, &QTimer::timeout, this, &Controller::eteindreToutLesPlots );
    disconnect(m_com, &ComBLE::plotAppuye, this ,&Controller::handleReactiontime);
    QList<Plot*> listeDePlot = getListeSelectedPlot();

    for(Plot * plot:listePlotsSelected)
    {
        plot->setAllume(false);
        plot->ecrireCouleurCharacteristic("off");
        emit plotAllumeChanged(plot->getId(), "#D3D3D3");
    }

    qDebug("Debut des deux secondes d'attentes");
    QTimer::singleShot(2000, [this]() {
        // Ce code est exécuté après un délai de 2 secondes
        qDebug("fin des deux secondes d'attentes");
        emit startNextIteration();
    });



}

void Controller::handleReactiontime(QByteArray reactionTime)
{

    //faire le traitement pour retrouver de quelle plot il s'agit, comparer valeur characteristique id avec idDuDernierPlotAllume

    //récupérer la valeur de la characteristique du plot appuyé
    qDebug() << "Le plot d'id" << "" << "a été appuyé avec un temps de reaction de :" << reactionTime << "ms" ;


    //

    //Stocker les score dans la partie
    eteindreToutLesPlots();
}


void Controller::handlePartieLaunchedChanged(bool isLaunched) {

    emit partieLaunchedChanged(isLaunched);
}








