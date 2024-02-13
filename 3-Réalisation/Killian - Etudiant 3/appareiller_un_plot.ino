#include <BluetoothSerial.h>
#include "heltec.h"

BluetoothSerial SerialBT;

void setup() {
    Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);
  
  Serial.begin(115200);
  SerialBT.begin("Plot"); // Nom du périphérique Bluetooth
  Heltec.display->drawString(0, 5, "Ready");


}

void loop() {
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
     Heltec.display->drawString(0, 5, "Disponible");
  }
  if (Serial.available()) {
    SerialBT.write(Serial.read());
     Heltec.display->drawString(0, 5, "Disponible");
  }
}
