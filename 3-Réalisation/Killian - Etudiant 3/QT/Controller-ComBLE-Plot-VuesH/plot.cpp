/*Plot.cpp*/


#include "plot.h"

#define SERVICE_BATTERY_UUID "00002A19-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_BATTERY_UUID_TX  "0000180F-0000-1000-8000-00805F9B34FB"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_CHARACTERISTIC_COULEUR "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"
#define UUID_CHARACTERISTIC_TEMPSPOURAPPUYER  "8cd233ac-a2ca-450e-a7a2-b1214ae851cc"
#define UUID_CHARACTERISTIC_ID "8cd233ac-a2ca-450e-a7a2-ea07361b26a8"
#define UUID_CHARACTERISTIC_TEMPSDEREACTION "8cd233ac-a2ca-450e-a7a2-ea07361b26aa"

/*Constructeur*/


int Plot::s_nextId = 1;

Plot::Plot()
{




    m_id = s_nextId++;
    qDebug() << "ID DU PLOT COURANT : "<<m_id;

    controllerBle= nullptr;
    servicePlot = nullptr;











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

    QBluetoothUuid characteristicCouleurUuid(QStringLiteral(UUID_CHARACTERISTIC_COULEUR));
    QLowEnergyCharacteristic characteristicCouleur = servicePlot->characteristic(characteristicCouleurUuid);
    if (!characteristicCouleur.isValid()) {
        qWarning() << "Characteristic Couleur introuvable";
    }

    QByteArray dataByteArray = couleur.toUtf8();
    qDebug() << "Couleur envoyé : " << dataByteArray;



    servicePlot->writeCharacteristic(characteristicCouleur, dataByteArray, QLowEnergyService::WriteWithoutResponse);

}


void Plot::lireTempsDeReaction()
{
    if (!controllerBle) {
        qWarning() << "BLE controller is not connected.";
        return;
    }

    // Check if servicePlot is already discovered
    if (!servicePlot) {
        QList<QBluetoothUuid> services = controllerBle->services();
        for (const auto &serviceUuid : services) {
            if (serviceUuid == QBluetoothUuid(QStringLiteral(SERVICE_PLOT_UUID))) {
                servicePlot = controllerBle->createServiceObject(serviceUuid, this);
                break;
            }
        }
    }

    if (!servicePlot) {
        qWarning() << "Service Plot not found.";
        return;
    }

    // Connect to characteristic for temps de reaction
    QBluetoothUuid characteristicUuid(QStringLiteral(UUID_CHARACTERISTIC_TEMPSDEREACTION));
    m_characteristicTempsDeReaction = servicePlot->characteristic(characteristicUuid);
    if (!m_characteristicTempsDeReaction.isValid()) {
        qWarning() << "Characteristic Temps de Reaction not found.";
        return;
    }

    // Connect characteristic read signal to appropriate slot
    connect(servicePlot, &QLowEnergyService::characteristicWritten,
            this, &Plot::characteristicRead);

    // Read the value of characteristic
    servicePlot->readCharacteristic(m_characteristicTempsDeReaction);
}

void Plot::characteristicRead(const QLowEnergyCharacteristic &characteristic, const QByteArray &value)
{
    if (characteristic.uuid() == QBluetoothUuid(QStringLiteral(UUID_CHARACTERISTIC_TEMPSDEREACTION))) {
        if (value.size() >= sizeof(unsigned long)) {
            unsigned long temps = *reinterpret_cast<const unsigned long*>(value.constData());
            m_listeTempsDeReaction.append(temps);
            emit tempsDeReactionReceived(temps);
        } else {
            qWarning() << "Invalid data received for Temps de Reaction.";
        }
    }
}

QList<unsigned long> Plot::getListeTempsDeReaction() const
{
    return m_listeTempsDeReaction;
}






