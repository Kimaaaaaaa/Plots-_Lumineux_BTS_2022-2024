#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "heltec.h"
#include "Arduino.h"
#define BROCHE_CAPTEUR 13
#define DUREE_ATTENTE 10000


BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
int txValue = 0;

#define SERVICE_UUID "0000180F-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_UUID_TX  "0000180F-0000-1000-8000-00805F9B34FB"

class MyServerCallbacks: public BLEServerCallbacks{
  void onConnect(BLEServer* pServer){
    deviceConnected = true;
  };

  
};

void setup() {
  Serial.begin(9600);

  //Configuration de l'écran
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setFont(ArialMT_Plain_10);

  //Create the BLE Device
  BLEDevice::init("PlotLumineux");

  //Create the BLE Server
  BLEServer * pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  //Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  //Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                              CHARACTERISTIC_UUID_TX,
                              BLECharacteristic::PROPERTY_READ
                             );

  //BLE2902 needed to notify
  pCharacteristic->addDescriptor(new BLE2902());

  //Start the service
  pService->start();

  //Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting for a client connection to notify...");

  

}

void loop() {
  if(deviceConnected){
    txValue = 50;

    //converison of tx Value
    String txString;
    txString = String(txValue);
    // Setting the value to the characteristic
    pCharacteristic->setValue((uint8_t*)txString.c_str(), txString.length());

    Heltec.display->clear();

    // Draw battery capacity on the screen
    int leftX = 0;  // Start from the leftmost side
    int topY = 0;   // Start from the top
    Heltec.display->drawString(leftX, topY, "Capacité batterie :" + txString + " %");

    String serviceUUIDString = String(SERVICE_UUID);
    serviceUUIDString.toLowerCase();
    String characteristicUUIDString = String(CHARACTERISTIC_UUID_TX);
    characteristicUUIDString.toLowerCase();

    // Write another text just below
    int lineHeight = 12; // Line height for additional text 
    Heltec.display->drawString(leftX, topY + lineHeight,serviceUUIDString);    
    Heltec.display->drawString(leftX, topY + 2 * lineHeight, characteristicUUIDString);

    Heltec.display->display();

    // Notifying the connected client
    pCharacteristic->notify();
    Serial.println("Sent value: " + String(txString));
    delay(500);
  }
}
