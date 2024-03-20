#include "comble.h"
#include "plot.h"
#include <QDebug>


ComBLE::ComBLE(QObject *parent) : QObject(parent)
{
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(2000);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &ComBLE::deviceDetecte);
    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &ComBLE::terminerScanDevice);

    connect(this,  &ComBLE::serviceDetecte, this, &ComBLE::lireValeurCharacteristicBattery);




}

bool ComBLE::isScanning() const
{
    return m_scanning;
}

void ComBLE::terminerScanDevice(){
    emit deviceScanFinished();
}

void ComBLE::startScanning()
{


    qDebug() << "Scanning for devices...";
    m_deviceDiscoveryAgent->start();
}

void ComBLE::stopScanning()
{
    qDebug() << "Scanning stopped.";
    m_deviceDiscoveryAgent->stop();
}

void ComBLE::deviceDetecte(const QBluetoothDeviceInfo &info)
{
    if(/*info.name().contains("Plot") ||*/ info.name().contains("PLOT"))
    {
        qDebug() << "Device trouvé !";
        qDebug() << "Nom du périphérique:" << info.name();

        emit deviceDiscovered(info);
    }
}

void ComBLE::scanServices(QLowEnergyController *controllerBle){

    //scan des services
    connect(controllerBle, &QLowEnergyController::serviceDiscovered, [=](const QBluetoothUuid &uuid)
    {
        // Récupérer le service
        QLowEnergyService *service = controllerBle->createServiceObject(uuid);

        //Si un service a été déouvert
        if (service) {
            // Connecter le signal de service découvert à une fonction slot
            connect(service, &QLowEnergyService::stateChanged, this, &ComBLE::serviceStateChanged);
            // Démarrer la découverte du service
            service->discoverDetails();
            listeDeService.push_back(service);
            //detecter les caracteristiques
            //characteristic  -> QlowEnergyCharacteristic
            const QLowEnergyCharacteristic characteristic = service->characteristic(uuid);


            emit serviceDetecte(service);
          // qDebug()<< characteristicBattery.value();

        }
    });




}

void ComBLE::lireValeurCharacteristicBattery(QLowEnergyService* service)
{
    const QLowEnergyCharacteristic characteristic = service->characteristic(QBluetoothUuid(QStringLiteral(CHARACTERISTIC_UUID_BATTERIE)));
    qDebug() << characteristic.value();

}




/*void ComBLE::scanServices(QLowEnergyController *controller)
{
    // Scanner les services du périphérique
    connect(controller, &QLowEnergyController::serviceDiscovered, [=](const QBluetoothUuid &uuid) {
        // Récupérer le service
        QLowEnergyService *service = controller->createServiceObject(uuid);
        if (service) {
            // Connecter le signal de service découvert à une fonction slot
            connect(service, &QLowEnergyService::stateChanged, this, &ComBLE::serviceStateChanged);
            // Démarrer la découverte du service
            service->discoverDetails();
            listeDeService.push_back(service);

            // Connecter le signal characteristicChanged au slot de Plot

        }
    });

    connect(controller, &QLowEnergyController::discoveryFinished,[=](){
        for(QLowEnergyService* service : listeDeService)
        {
            recupererValeurCharacteristic(service);
        }
    });

    // Démarrer la découverte des services
    controller->discoverServices();
}*/



void ComBLE::serviceStateChanged(QLowEnergyService::ServiceState newState)
{
    QLowEnergyService *service = qobject_cast<QLowEnergyService*>(sender());
    if (!service)
        return;

    switch (newState) {
    case QLowEnergyService::DiscoveringServices:
        qDebug() << "Discovering services...";
        break;
    case QLowEnergyService::ServiceDiscovered:
        qDebug() << "Service discovered:" << service->serviceName();
        // Traitez le service découvert ici
        break;
    default:
        // Traitez les autres états si nécessaire
        break;
    }
}

//Coder un slot qui récupère les services puis extraits les valeurs dans une QList<QByteArray>
QList<QByteArray> ComBLE::recupererValeurCharacteristic(QLowEnergyService* service)
{
    QList<QLowEnergyCharacteristic> listCharacteristic = service->characteristics();

    QList<QByteArray> listeValeur;

    for (const QLowEnergyCharacteristic &characteristic : listCharacteristic)
    {
        //Récupère la valeur de chacune des characteristic
        qDebug() << "Récupérer valeur characteristic";
        listeValeur.append(characteristic.value());

        qDebug() << "Valeur de la characteristic " << characteristic.name() << "du device " <<    " : "  << characteristic.value();
    }


    return listeValeur;
}








