#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "heltec.h"
#include "Arduino.h"

BLECharacteristic *pCharacteristicBattery;
BLECharacteristic *pCharacteristicColor;
bool deviceConnected = false;
int txValue = 0;


#define SERVICE_BATTERY_UUID "0000180f-0000-1000-8000-00805f9b34fb"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_CHARACTERISTIC_COULEUR "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"



class MyServerCallbacks : public BLEServerCallbacks {
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

  // Configuration de l'écran
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setFont(ArialMT_Plain_10);

  // Create the BLE Device
  BLEDevice::init("PLOT");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Battery Service
  BLEService *pServiceBattery = pServer->createService(SERVICE_BATTERY_UUID);

  // Create a BLE Characteristic for battery
  pCharacteristicBattery = pServiceBattery->createCharacteristic(
                              SERVICE_BATTERY_UUID,
                              BLECharacteristic::PROPERTY_READ
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
  pCharacteristicColor->setCallbacks(new MyCharacteristicCallbacks());

  // Start the plot service
  pServicePlot->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {
  
 /* pCharacteristicBattery->setValue("72");
  pCharacteristicColor->setValue("green");
  String color;
  color = String(pCharacteristicColor->getValue().c_str());
  Heltec.display->drawString(0, 0, "Couleur : " + color);*/
}
