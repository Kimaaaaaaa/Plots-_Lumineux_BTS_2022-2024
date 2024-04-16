#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include "fonction.h"
#include <arduino.h>
#include "heltec.h"


BLECharacteristic* pCharacteristictempsPourAppuyer;
BLECharacteristic* pCharacteristicID;
BLECharacteristic* pCharacteristicTempsDeReaction;
BLECharacteristic* pCharacteristicCouleur;

unsigned long tempsDetection = 0;

bool deviceConnected = false;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Heltec.display->clear();
      Heltec.display->drawString(0, 0, "Connecte");
      Heltec.display->drawString(0, 10, "Couleur : éteint");
      Heltec.display->display();
    };
};
// Function to handle data received for the color characteristic
class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      String receivedData = String(pCharacteristic->getValue().c_str());

      // Display received data on the screen
      Heltec.display->clear();
      Heltec.display->drawString(10, 10, "Received data: " + receivedData);
      Heltec.display->display();
    }
};

void setup() {
  Serial.begin(9600);

  //Create the BLE Device
  BLEDevice::init("PlotLumineux");

  //Create the BLE Server
  BLEServer * pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  //Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_PLOT_UUID);


  // Caractéristique ID
  pCharacteristicID = pService->createCharacteristic(
                        UUID_Characteristic_ID,
                        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                      );

  // Caractéristique Temps de Réaction
  pCharacteristicTempsDeReaction = pService->createCharacteristic(
                                     UUID_Characteristic_TempsDeReaction,
                                     BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                                   );
  // Caractéristique Couleur
  pCharacteristicCouleur = pService->createCharacteristic(
                             UUID_Characteristic_Couleur,
                             BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                           );

  pCharacteristicTempsPourAppuyer = pService->createCharacteristic(
                                      UUID_Characteristic_tempsPourAppuyer,
                                      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                                    );

  //Start the service
  pService->start();

  //Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
  tempsDebutProgramme = millis(); // Démarre le timer


}

void loop() {

  //lireIDManuellement(pCharacteristicID);

  /*pCharacteristicID->setValue("60");
    // Lecture de la valeur de la caractéristique ID
    std::string idValue = pCharacteristicID->getValue();

    // Vérification si une valeur a été reçue
    if (idValue.length() > 0) {
      int id = atoi(idValue.c_str());
      idReceived = true; // Marque que l'ID a été reçu

      pCharacteristicID->setValue(""); // Réinitialise la valeur de la caractéristique ID
    }*/

  // Si l'ID a été reçu, vérifiez le capteur infrarouge
  if (idReceived) {

    int valeurCapteur = digitalRead(BROCHE_CAPTEUR);
    unsigned long tempsActuel = millis();

    lectureCapteur(valeurCapteur, tempsActuel, pCharacteristicTempsDeReaction);
  }
}
