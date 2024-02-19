#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

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

  //Create the BLE Device
  BLEDevice::init("Plot");

  //Create the BLE Server
  BLEServer * pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  //Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  //Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                              CHARACTERISTIC_UUID_TX,
                              BLECharacteristic::PROPERTY_NOTIFY
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
    txValue = random(0, 100);

    //converison of tx Value
    String txString;
    txString = String(txValue);

    //Setting the value to the characteristic
    pCharacteristic->setValue((uint8_t*)txString.c_str(), txString.length());


    //Notifying te connected client
    pCharacteristic->notify();
    Serial.println("Sent value: " + String(txString));
    delay(500);
  }

}
