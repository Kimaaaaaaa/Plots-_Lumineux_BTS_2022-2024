#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "heltec.h"
#include "Arduino.h"

BLECharacteristic *pCharacteristicBattery;
BLECharacteristic *pCharacteristicColor;
BLECharacteristic* pCharacteristicTempsPourAppuyer;
BLECharacteristic* pCharacteristicID;
BLECharacteristic* pCharacteristicTempsDeReaction;
bool deviceConnected = false;
int txValue = 0;

unsigned long tempsDebutProgramme = 0;
bool idReceived = false;

#define SERVICE_BATTERY_UUID "0000180f-0000-1000-8000-00805f9b34fb"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_CHARACTERISTIC_COULEUR "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"
#define UUID_CHARACTERISTIC_TEMPSPOURAPPUYER  "8cd233ac-a2ca-450e-a7a2-b1214ae851cc"
#define UUID_CHARACTERISTIC_ID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define UUID_CHARACTERISTIC_TEMPSDEREACTION "beb5483e-36e1-4688-b7f5-ea07361b26aa"


#define BROCHE_CAPTEUR 13
#define DUREE_ATTENTE 10000



class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      pCharacteristicColor->setValue("Eteint");
      pCharacteristicBattery->setValue("50%");
      pCharacteristicTempsDeReaction->setValue("1254 ms");
      Heltec.display->clear();
      Heltec.display->drawString(0, 0, "Connecte");
      Heltec.display->drawString(0, 10, "Battery :" + String(pCharacteristicBattery->getValue().c_str()));
      Heltec.display->drawString(0, 20, "Couleur :" + String(pCharacteristicColor->getValue().c_str()));
      Heltec.display->drawString(0, 30, "TempsDeReaction :" + String(pCharacteristicTempsDeReaction->getValue().c_str()));
      Heltec.display->display();
    };
};

// Function to handle data received for the color characteristic
class MyCharacteristicColorCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      String receivedData = String(pCharacteristic->getValue().c_str());

      // Display received data on the screen
      Heltec.display->clear();
      Heltec.display->drawString(0, 20, "Couleur : " + receivedData);
      Heltec.display->display();
    }
};


// Function to handle data received for the color characteristic
class MyCharacteristicBatteryCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      String receivedData = String(pCharacteristic->getValue().c_str());

      // Display received data on the screen
      Heltec.display->clear();
      Heltec.display->drawString(0, 30, "Batterie : " + receivedData);
      Heltec.display->display();
    }
};
class MyCharacteristicTempsDeReactionCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      String receivedData = String(pCharacteristic->getValue().c_str());

      // Display received data on the screen
      Heltec.display->clear();
      Heltec.display->drawString(0, 40, "Temps de reaction : " + receivedData);
      Heltec.display->display();
    }
};

void setup() {
  Serial.begin(115200);

  // Configuration de l'écran
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setFont(ArialMT_Plain_10);

  // Create the BLE Device
  BLEDevice::init("PlotLumineux");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Battery Service
  BLEService *pServiceBattery = pServer->createService(SERVICE_BATTERY_UUID);

  // Create a BLE Characteristic for battery
  pCharacteristicBattery = pServiceBattery->createCharacteristic(
                             SERVICE_BATTERY_UUID,
                             BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                           );

  // Add descriptor for Battery Level
  pCharacteristicBattery->addDescriptor(new BLE2902());

  // Start the battery service
  pServiceBattery->start();

  // Create the BLE Plot Service
  BLEService *pServicePlot = pServer->createService(SERVICE_PLOT_UUID);

  // Create the BLE Plot Color Characteristic
  pCharacteristicColor = pServicePlot->createCharacteristic(
                           UUID_CHARACTERISTIC_COULEUR,
                           BLECharacteristic::PROPERTY_WRITE
                         );
  pCharacteristicID = pServicePlot->createCharacteristic(
                        UUID_CHARACTERISTIC_ID,
                        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                      );

  // Caractéristique Temps de Réaction
  pCharacteristicTempsDeReaction = pServicePlot->createCharacteristic(
                                     UUID_CHARACTERISTIC_TEMPSDEREACTION,
                                     BLECharacteristic::PROPERTY_READ
                                   );

  pCharacteristicTempsPourAppuyer = pServicePlot->createCharacteristic(
                                      UUID_CHARACTERISTIC_TEMPSPOURAPPUYER,
                                      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
                                    );

  // Set data received callback for the color characteristic
  pCharacteristicColor->setCallbacks(new MyCharacteristicColorCallbacks());
  pCharacteristicBattery->setCallbacks(new MyCharacteristicBatteryCallbacks());
  pCharacteristicTempsDeReaction->setCallbacks(new MyCharacteristicTempsDeReactionCallbacks());

  // Start the plot service
  pServicePlot->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() { 
  static String idValue = ""; // Variable statique pour stocker l'ID en cours de lecture

  while (Serial.available()) {
    char c = Serial.read(); // Lire le prochain caractère du moniteur série
    if (c == '\n') { // Si le caractère de nouvelle ligne est reçu
      if (idValue.length() > 0) { // S'assurer que l'ID est non vide
        int id = idValue.toInt(); // Convertir l'ID en entier
        Serial.print("ID du plot entré : ");
        Serial.println(id);
        pCharacteristicID->setValue(idValue.c_str()); // Définir la valeur de la caractéristique ID avec l'ID entré
        idReceived = true;
        tempsDebutProgramme = millis(); // Démarre le timer // Marque que l'ID a été reçu
      }
      idValue = ""; // Réinitialiser la variable d'ID pour la prochaine lecture
    } else if (isDigit(c)) { // Vérifie si le caractère est un chiffre
      idValue += c; // Ajouter le caractère lu à l'ID en cours de lecture
    }
  }
  // Si l'ID a été reçu, vérifiez le capteur infrarouge
  if (idReceived) {

    int valeurCapteur = digitalRead(BROCHE_CAPTEUR);
    unsigned long tempsActuel = millis();
    
  if (valeurCapteur == LOW) {
    unsigned long tempsDetection = tempsActuel - tempsDebutProgramme;
    Serial.print("Détection infrarouge détectée après ");
    Serial.print(tempsDetection);
    Serial.println(" millisecondes.");
    pCharacteristicTempsDeReaction->setValue((uint8_t*)&tempsDetection, sizeof(tempsDetection));
    pCharacteristicTempsDeReaction->notify();
    tempsDebutProgramme = millis();
    idReceived = false; // Remettre idReceived à false pour attendre un nouvel ID
    
  } else {
    if (tempsActuel - tempsDebutProgramme > DUREE_ATTENTE) {
      unsigned long tempsDetection = tempsActuel - tempsDebutProgramme;
      Serial.println("Délai de 10 secondes écoulé, envoi du temps...");
      Serial.print("Temps écoulé : ");
      Serial.print(tempsDetection);
      Serial.println(" millisecondes.");
      // Mettre le temps de réaction dans la caractéristique
      pCharacteristicTempsDeReaction->setValue((uint8_t*)&tempsDetection, sizeof(tempsDetection));
      pCharacteristicTempsDeReaction->notify();
      tempsDebutProgramme = millis();
      idReceived = false; // Remettre idReceived à false pour attendre un nouvel ID
    }
  }
  }
}
