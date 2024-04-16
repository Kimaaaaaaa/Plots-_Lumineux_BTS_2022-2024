#include <BLEDevice.h>
#include <BLEServer.h>
#include "fonction.h"
#include <arduino.h>

bool idReceived = false;
unsigned long tempsDebutProgramme = 0;


void lireIDManuellement(BLECharacteristic* pCharacteristicID)
{
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
}


void lectureCapteur(int valeurCapteur, unsigned long tempsActuel, BLECharacteristic* pCharacteristicTempsDeReaction) {

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
