/*ComBLE*/


#include "comble.h"
#include <QDebug>

ComBLE::ComBLE(QObject *parent) : QObject(parent)
{
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);

    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(2000);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &ComBLE::deviceDetecte);
    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &ComBLE::terminerScanDevice);



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
    if(info.name().contains("Plot") || info.name().contains("PLOT") || info.name().contains("plot"))
    {
        qDebug() << "Device trouvé !";
        qDebug() << "Nom du périphérique:" << info.name();

        emit deviceDiscovered(info);
    }
}

/*void ComBLE::scanServices(QLowEnergyController *controllerBle){

    //scan des services
    connect(controllerBle, &QLowEnergyController::serviceDiscovered, [=](const QBluetoothUuid &uuid)
    {
        // Récupérer le service
        QLowEnergyService *service = controllerBle->createServiceObject(uuid);

        //Si un service a été déouvert
        if (service) {
            // Connecter le signal de service découvert à une fonction slot
            qDebug() << "test";
            connect(service, &QLowEnergyService::stateChanged, this, &ComBLE::serviceStateChanged);
            // Démarrer la découverte du service
            service->discoverDetails();
            listeDeService.push_back(service);

            //detecter les caracteristiques
            //characteristic  -> QlowEnergyCharacteristic
            const QLowEnergyCharacteristic characteristic = service->characteristic(uuid);


            connect(this, &ComBLE::serviceDetecte, this, [=](QLowEnergyService *service) {
                lireValeurCharacteristicBattery(service);
            });

        }
    });

}*/

void ComBLE::scanServices(QLowEnergyController *controllerBle){



    //scan des services
    connect(controllerBle, &QLowEnergyController::serviceDiscovered, [=](const QBluetoothUuid &uuid)
    {
        // Récupérer le service
        QLowEnergyService *service = controllerBle->createServiceObject(uuid);
        // qDebug() << "test";


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


    connect(controllerBle, &QLowEnergyController::discoveryFinished, [=]()
    {
        QList<QBluetoothUuid> listeUUIDService = controllerBle->services();

        foreach (QBluetoothUuid uuidService, listeUUIDService) {
            QLowEnergyService* service = controllerBle->createServiceObject(uuidService, controllerBle);
            service->discoverDetails();

            connect(service, &QLowEnergyService::stateChanged, this, &ComBLE::serviceStateChanged);

            // Lire la valeur des characteristiques découvert
            const QLowEnergyCharacteristic characteristic = service->characteristic(uuidService);
            if (characteristic.isValid()) {
                qDebug() << "Valeur actuelle de la caractéristique : " << characteristic.value();

                emit batterieLue(service, characteristic.value());
            }
        }
    });


    controllerBle->discoverServices();

}







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



/*void ComBLE::lireValeurCharacteristicBattery(QLowEnergyService *service)
{

    const QLowEnergyCharacteristic characteristic = service->characteristic(QBluetoothUuid(QStringLiteral(CHARACTERISTIC_UUID_BATTERIE)));



    qDebug() << characteristic.value();
}
*/


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
        emit valeurLue(service, characteristic.value() );
    }


    return listeValeur;
}
void ComBLE::writeCharacteristic(QLowEnergyController *controller, const QBluetoothUuid &serviceUuid, const QLowEnergyCharacteristic &characteristicUuid, const QByteArray &data)
{
    if (controller && controller->state() == QLowEnergyController::ConnectedState) {
        QLowEnergyService *service = controller->createServiceObject(serviceUuid, controller);
        if (service) {
            service->writeCharacteristic(characteristicUuid, data);
        }
    }
}

