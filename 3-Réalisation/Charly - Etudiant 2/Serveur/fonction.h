#ifndef FONCTION_H
#define FONCTION_H

#define BROCHE_CAPTEUR 13
#define DUREE_ATTENTE 10000


#define SERVICE_BATTERY_UUID "0000180F-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_BATTERY_UUID_TX  "00002A19-0000-1000-8000-00805F9B34FB" // Utiliser un UUID standard pour la caractéristique de niveau de batterie

#define SERVICE_PLOT_UUID "4fafc202-1fb5-459e-8fcc-c5c9c331914b"
#define UUID_Characteristic_Couleur "8cd233ac-a2ca-450e-a7a2-d114bd53e2a3"
#define UUID_Characteristic_TempsPourAppuyer  "8cd233ac-a2ca-450e-a7a2-b1214ae851cc"
#define UUID_Characteristic_ID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define UUID_Characteristic_TempsDeReaction "beb5483e-36e1-4688-b7f5-ea07361b26aa"


extern bool idReceived; // Déclaration de la variable idReceived
extern unsigned long tempsDebutProgramme; // Déclaration de la variable tempsDebutProgramme

void lireIDManuellement(BLECharacteristic* pCharacteristicID);
void lectureCapteur(int valeurCapteur, unsigned long tempsActuel, BLECharacteristic* pCharacteristicTempsDeReaction);

#endif
