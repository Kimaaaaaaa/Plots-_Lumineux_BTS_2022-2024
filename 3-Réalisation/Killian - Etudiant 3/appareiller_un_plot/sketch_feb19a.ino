#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "heltec.h"
#include "Arduino.h"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
int txValue = 0;

#define SERVICE_BATTERY_UUID "0000180F-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_BATTERY_UUID_TX  "0000180F-0000-1000-8000-00805F9B34FB"
#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic_Couleur "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"
#define UUID_Characteristic_tempsPourAppuyer  "8cd233ac-a2ca-450e-a7a2-b1214ae851cc"

class MyServerCallbacks: public BLEServerCallbacks{
  void onConnect(BLEServer* pServer ){
    deviceConnected = true;
  };

     void onWrite(BLECharacteristic *pCharacteristic) override {
        std::string value = pCharacteristic->getValue();

        if (value.length() > 0) {
            Serial.println("Valeur reçue : ");
            for (int i = 0; i < value.length(); i++)
                Serial.print(value[i]);
            
            Serial.println();
            //convertir la valeur.
        }
    }

  
};

void setup() {
  Serial.begin(9600);

  //Configuration de l'écran
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setFont(ArialMT_Plain_10);

  //Create the BLE Device
  BLEDevice::init("PLOT");

  //Create the BLE Server
  BLEServer * pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());


  //Battery
  //Create the BLE Battery Service
  BLEService *pServiceBattery = pServer->createService(SERVICE_BATTERY_UUID);

  //Create a BLE Characteristic
  pCharacteristicBattery = pServiceBattery->createCharacteristic(
                              CHARACTERISTIC_BATTERY_UUID_TX,
                              BLECharacteristic::PROPERTY_READ
                             );

  //Create the BLE Plot Service
  BLEService *pServicePlot = pServer->createService(SERVICE_PLOT_UUID);

// Create the BLE Plot Color Characteristic
BLECharacteristic *pCharacteristicColor = pServicePlot->createCharacteristic(
                                           UUID_Characteristic_Couleur,
                                           BLECharacteristic::PROPERTY_WRITE
                                         );
BLECharacteristic *pCharacteristicTempsPourAppuyer = pServicePlot->createCharacteristic(
                                           UUID_Characteristic_tempsPourAppuyer,
                                           BLECharacteristic::BLECharacteristic::PROPERTY_READ
                                         );








  

  //BLE2902 needed to notify
  pCharacteristic->addDescriptor(new BLE2902());

  //Start the service
  pServiceBattery->start();
  pServicePlot->start();

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
