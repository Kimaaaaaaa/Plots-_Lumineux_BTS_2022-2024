#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "heltec.h"
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

bool deviceConnected = false;
int txValue = 0;

#define SERVICE_BATTERY_UUID "0000180f-0000-1000-8000-00805f9b34fb"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_CHARACTERISTIC_COULEUR "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"
#define UUID_CHARACTERISTIC_TEMPSDEREACTION "8cd233ac-a2ca-450e-a7a2-ea07361b26aa"
#define UUID_CHARACTERISTIC_ID "8cd233ac-a2ca-450e-a7a2-xp94574c14ee"
#define UUID_DESCRIPTOR_CLIENT_CHAR_CONFIG "2902"

#define PIN_LED 12
#define BROCHE_CAPTEUR 13
#define DUREE_ATTENTE 10000
#define NUMPIXELS 12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_LED, NEO_GRB + NEO_KHZ800);

BLECharacteristic *pCharacteristicBattery;
BLECharacteristic *pCharacteristicColor;
BLECharacteristic *pCharacteristicID;
BLECharacteristic *pCharacteristicTempsDeReaction;
BLECharacteristic *pCharacteristicTempsPourAppuyer;

int couleur = -1;
unsigned long tempsDebutProgramme = 0;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    deviceConnected = true;
    pCharacteristicColor->setValue("off");
    pCharacteristicBattery->setValue("50");
    pCharacteristicTempsDeReaction->setValue("1254 ms");

    Heltec.display->clear();
    Heltec.display->drawString(0, 0, "Connected");
    Heltec.display->drawString(0, 10, "Battery :" + String(pCharacteristicBattery->getValue().c_str()));
    Heltec.display->drawString(0, 20, "Color :" + String(pCharacteristicColor->getValue().c_str()));
    Heltec.display->drawString(0, 30, "Reaction time :" + String(pCharacteristicTempsDeReaction->getValue().c_str()));
    Heltec.display->display();
  }
};

class MyCharacteristicColorCallbacks : public BLECharacteristicCallbacks {
public:
  void onWrite(BLECharacteristic *pCharacteristic) override {
    std::string receivedData = pCharacteristic->getValue();
    const char *data = receivedData.c_str();
    String receivedDataStr = String(data);

    Heltec.display->clear();
    Heltec.display->drawString(0, 20, "Color : " + receivedDataStr);
    Heltec.display->display();

    if (strcmp(data, "white") == 0) {
      couleur = 0;
    } else if (strcmp(data, "red") == 0) {
      couleur = 1;
    } else if (strcmp(data, "green") == 0) {
      couleur = 2;
    } else if (strcmp(data, "blue") == 0) {
      couleur = 3;
    } else if (strcmp(data, "yellow") == 0) {
      couleur = 4;
    } else {
      couleur = 5;
    }

    if (couleur != -1) {
      pixels.begin();
      pixels.clear();
      pixels.setBrightness(100);

      switch (couleur) {
        case 0:
          pixels.fill(pixels.Color(255, 255, 255));  // White
          break;
        case 1:
          pixels.fill(pixels.Color(255, 0, 0));  // Red
          break;
        case 2:
          pixels.fill(pixels.Color(0, 255, 0));  // Green
          break;
        case 3:
          pixels.fill(pixels.Color(0, 0, 255));  // Blue
          break;
        case 4:
          pixels.fill(pixels.Color(255, 255, 0));  // Yellow
          break;
        default:
          pixels.clear();
          break;
      }

      tempsDebutProgramme = millis();
      Serial.println("Début de la capture du temps");
      pixels.show();

      couleur = 10;
    }
  }
};

class MyCharacteristicBatteryCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string receivedData = pCharacteristic->getValue();
    const char *data = receivedData.c_str();
    String receivedDataStr = String(data);

    Heltec.display->clear();
    Heltec.display->drawString(0, 30, "Battery : " + receivedDataStr);
    Heltec.display->display();
  }
};

class MyCharacteristicTempsDeReactionCallbacks : public BLECharacteristicCallbacks {
  void onRead(BLECharacteristic *pCharacteristic) {
    std::string receivedData = pCharacteristic->getValue();
    const char *data = receivedData.c_str();
    String receivedDataStr = String(data);

    Heltec.display->drawString(0, 40, "Reaction Time : " + receivedDataStr);
    Heltec.display->display();
  }
};

void setup() {
  Serial.begin(115200);

  // Configuration de l'écran
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setFont(ArialMT_Plain_10);

  // Create the BLE Device
  BLEDevice::init("PlotKillian");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Battery Service
  BLEService *pServiceBattery = pServer->createService(SERVICE_BATTERY_UUID);
  pCharacteristicBattery = pServiceBattery->createCharacteristic(
    SERVICE_BATTERY_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
  );


  
  pServiceBattery->start();

  // Create the BLE Plot Service
  BLEService *pServicePlot = pServer->createService(SERVICE_PLOT_UUID);
  pCharacteristicColor = pServicePlot->createCharacteristic(
    UUID_CHARACTERISTIC_COULEUR,
    BLECharacteristic::PROPERTY_WRITE);


    pCharacteristicTempsDeReaction = pServicePlot->createCharacteristic(
      UUID_CHARACTERISTIC_TEMPSDEREACTION,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);


      pCharacteristicID = pServicePlot->createCharacteristic(
    UUID_CHARACTERISTIC_ID,
    BLECharacteristic::PROPERTY_WRITE);


    

    

  pCharacteristicColor->setCallbacks(new MyCharacteristicColorCallbacks());
  pCharacteristicBattery->setCallbacks(new MyCharacteristicBatteryCallbacks());
  pCharacteristicTempsDeReaction->setCallbacks(new MyCharacteristicTempsDeReactionCallbacks());

  pCharacteristicTempsDeReaction->addDescriptor(new BLE2902());

  BLEDescriptor *pDescriptor = pCharacteristicTempsDeReaction->getDescriptorByUUID(BLEUUID(UUID_DESCRIPTOR_CLIENT_CHAR_CONFIG));
  if (pDescriptor != nullptr) {
      Serial.println("Descriptor added successfully.");
  } else {
      Serial.println("Failed to add descriptor.");
  }

  pServicePlot->start();


  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {
  static int lastSensorState = HIGH;

  if (couleur != -1 && (couleur >= 1)) {
    int currentSensorState = digitalRead(BROCHE_CAPTEUR);

    if (currentSensorState == HIGH) {
      
    

      while (digitalRead(BROCHE_CAPTEUR) == HIGH){
        delay(10);
      }

      unsigned long tempsAttente = millis() - tempsDebutProgramme;
      Serial.print("L'utilisateur a attendu ");
      Serial.print(tempsAttente);
      Serial.println(" millisecondes avant d'appuyer sur le capteur.");

      String tempsAttenteStr = String(tempsAttente);
      pCharacteristicTempsDeReaction->setValue(tempsAttenteStr.c_str());
      pCharacteristicTempsDeReaction->notify();
    }

    lastSensorState = currentSensorState;
  }
}
