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



/*Slot*/

void Controller::startScanning() {
    if (m_com) {
        m_com->startScanning();
    }
}

void Controller::afficherPlots(){
    // Emettre le signal indiquant que la liste de plots a changé
    emit listePlotsChanged();
}

void Controller::addPlot(const QBluetoothDeviceInfo &deviceInfo)
{
    if(deviceInfo.name().contains("Plot")) {
        // Créer un nouveau plot avec le nom du périphérique
        Plot *newPlot = new Plot();
        newPlot->setNom(deviceInfo.name());

        // Ajoutez le nouveau plot à la liste
        listePlots.append(newPlot);


    }
}
