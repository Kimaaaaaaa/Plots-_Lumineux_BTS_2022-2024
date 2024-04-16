#define BROCHE_CAPTEUR 13
#define DUREE_ATTENTE 10000

unsigned long tempsDebutProgramme=0; // Variable pour enregistrer le temps au début du programme

void setup() {
  Serial.begin(9600);
  tempsDebutProgramme = millis(); // Enregistrez le temps au début du programme
}

void loop() {
  int valeurCapteur = digitalRead(BROCHE_CAPTEUR);
  unsigned long tempsActuel = millis();
  
  if (valeurCapteur == LOW) {
    // Si la détection infrarouge est détectée
    unsigned long tempsDetection = tempsActuel - tempsDebutProgramme; // Calculez le temps écoulé depuis le début du programme
    Serial.print("Détection infrarouge détectée après ");
    Serial.print(tempsDetection);
    Serial.println(" millisecondes.");

  } else {
     // Si aucune détection infrarouge n'est détectée
    // Vérifier si le délai de 10 secondes est écoulé
    if (tempsActuel - tempsDebutProgramme > DUREE_ATTENTE) {
      Serial.println("Délai de 10 secondes écoulé, envoi du temps...");
      Serial.print("Temps écoulé : ");
      Serial.print(tempsActuel - tempsDebutProgramme);
      Serial.println(" millisecondes.");
    }
  }
}
