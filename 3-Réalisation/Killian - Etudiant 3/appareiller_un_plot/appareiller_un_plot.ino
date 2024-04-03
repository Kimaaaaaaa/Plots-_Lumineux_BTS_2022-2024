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

#define SERVICE_BATTERY_UUID "0000180F-0000-1000-8000-00805F9B34FB"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic_Couleur "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };
};

// Function to handle data received for the color characteristic
class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string receivedData = pCharacteristic->getValue();
    
    // Display received data on the screen
    Heltec.display->clear();
    Heltec.display->drawString(0, 0, "Received data: " + String(receivedData.c_str()));
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
                                           UUID_Characteristic_Couleur,
                                           BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
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
  
if(deviceConnected)
}
