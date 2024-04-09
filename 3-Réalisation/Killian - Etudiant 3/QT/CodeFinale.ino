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

#define PIN       12

#define NUMPIXELS 12


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

BLECharacteristic *pCharacteristicBattery;
BLECharacteristic *pCharacteristicColor;



class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      pCharacteristicColor->setValue("Eteint");
      pCharacteristicBattery->setValue("50%");
      Heltec.display->clear();
      Heltec.display->drawString(0, 0, "Connecte");
      Heltec.display->drawString(0, 10, "Battery :" + String(pCharacteristicBattery->getValue().c_str()));
      Heltec.display->drawString(0, 20, "Couleur :" + String(pCharacteristicColor->getValue().c_str()));
      Heltec.display->display();
    };
};
class MyCharacteristicColorCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string receivedData = pCharacteristic->getValue();
      const char *data = receivedData.c_str();

      Heltec.display->clear();
      Heltec.display->drawString(0, 20, "Couleur : " + String(receivedData.c_str()));
      Heltec.display->display();

      int couleur = -1; // Initialisez à une valeur par défaut pour détecter les cas non gérés

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
        pixels.setBrightness(50);

        switch (couleur) {
          case 0:
            pixels.fill(pixels.Color(255, 255, 255)); // White
            break;
          case 1:
            pixels.fill(pixels.Color(255, 0, 0)); // Red
            break;
          case 2:
            pixels.fill(pixels.Color(0, 255, 0)); // Green
            break;
          case 3:
            pixels.fill(pixels.Color(0, 0, 255)); // Blue
            break;
          case 4:
            pixels.fill(pixels.Color(255, 255, 0)); // Yellow
            break;
          default:
            pixels.clear();
            break;
        }

        pixels.show();
      }
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

void setup() {

  Serial.begin(9600);

  // Configuration de l'écran
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setFont(ArialMT_Plain_10);

  // Create the BLE Device
  BLEDevice::init("PlotsLumineux2");

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

  // Set data received callback for the color characteristic
  pCharacteristicColor->setCallbacks(new MyCharacteristicColorCallbacks());
  pCharacteristicBattery->setCallbacks(new MyCharacteristicBatteryCallbacks());

  // Start the plot service
  pServicePlot->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {


}
