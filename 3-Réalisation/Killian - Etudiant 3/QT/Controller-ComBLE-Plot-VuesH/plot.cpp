/*Plot.cpp*/


#include "plot.h"

#define SERVICE_BATTERY_UUID "0000180f-0000-1000-8000-00805f9b34fb"
#define CHARACTERISTIC_BATTERY_UUID_TX  "0000180f-0000-1000-8000-00805f9b34fb"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic_Couleur "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"

/*Constructeur*/


int Plot::s_nextId = 1;

Plot::Plot()
{
    connect(this, &Plot::tempsRecu,
            this, &Plot::standBy);



    m_id = s_nextId++;
    qDebug() << "ID DU PLOT COURANT : "<<m_id;











    this->couleur = nullptr;
    nvBatterie = 0;
    selected = false;
    allume = false;

}

/*Méthode*/




bool Plot::activerPlot(Plot * plot, QString couleur)
{
    plot->couleur = couleur;

    //Composer le code permettant d'allumer le plot

    return true;

}

bool Plot::desactiverPlot(Plot *)
{
    //Composer le code permettat au plot de s'éteindre (Couleur éteindre ?)

    return true;
}

void Plot::setNvBatterie(int nv)
{
    nvBatterie = nv;
}

int Plot::getNvBatterie()
{
    return nvBatterie;
}

QString Plot::getNom()
{
    return m_nom;
}

bool Plot::getSelected()
{
    return selected;
}

void Plot::setSelected(bool selected)
{
    this->selected = selected;
    qDebug()<<"Selected changed : ";
}

QString Plot::nom() const
{
    return m_nom;
}

void Plot::setNom(const QString &nom)
{
    if (m_nom != nom) {
        m_nom = nom;
        emit nomChanged();
    }
}

void Plot::setId(const int id)
{
    this->m_id = id;
}

int Plot::getId() const {
    return m_id;
}



//Slot

void Plot::standBy()
{
    /*
    for(int i = 0; i < this->listePlot.count(); i++)
    {
        desactiverPlot(listePlot.takeAt(i));
    }*/

    //Bloquer 1 seconde......
}

void Plot::writeTimeout()
{
    qWarning() << "Write operation timed out.";
}

bool Plot::getAllume() const
{
    return allume;
}

void Plot::setAllume(bool newAllume)
{
    allume = newAllume;
}






QLowEnergyController *Plot::getControllerBle() const
{
    return controllerBle;
}

void Plot::setControllerBle(QLowEnergyController *newController)
{
    controllerBle = newController;
}

void Plot::deconnecterPlot()
{
    delete this->controllerBle;
}



void Plot::ecrireCouleurCharacteristic(const QString &couleur)
{

    if (!controllerBle) {
        qWarning() << "Controller BLE is not initialized.";

    }

    // Initialiser le contrôleur BLE en tant que rôle central
    if (controllerBle->role() != QLowEnergyController::CentralRole) {
        controllerBle->setRemoteAddressType(QLowEnergyController::PublicAddress);
        controllerBle->connectToDevice();

    }

    QLowEnergyService *servicePlot = nullptr;

    QList<QBluetoothUuid> services = controllerBle->services();
    for (const auto &serviceUuid : services) {
        if (serviceUuid == QBluetoothUuid(QStringLiteral(SERVICE_PLOT_UUID))) {
            servicePlot = controllerBle->createServiceObject(serviceUuid, this);
            break;
        }
    }

    if (!servicePlot) {
        qWarning() << "Service Plot not found";

    }

    // Anttendre de découvrir le service
    if (servicePlot->state() == QLowEnergyService::DiscoveryRequired) {
        QObject::connect(servicePlot, &QLowEnergyService::stateChanged, this, [this, servicePlot, couleur](QLowEnergyService::ServiceState newState) {
            if (newState == QLowEnergyService::ServiceDiscovered) {
                qDebug() << "État actuel du service : " << servicePlot->state();
                this->ecrireCouleurCharacteristic(couleur);
            }
        });
        servicePlot->discoverDetails();

    }

    QBluetoothUuid characteristicCouleurUuid(QStringLiteral(UUID_Characteristic_Couleur));
    QLowEnergyCharacteristic characteristicCouleur = servicePlot->characteristic(characteristicCouleurUuid);
    if (!characteristicCouleur.isValid()) {
        qWarning() << "Characteristic Couleur introuvable";
    }

    QByteArray dataByteArray = couleur.toUtf8();
    qDebug() << "Couleur envoyé : " << dataByteArray;



    servicePlot->writeCharacteristic(characteristicCouleur, dataByteArray, QLowEnergyService::WriteWithoutResponse);

}




