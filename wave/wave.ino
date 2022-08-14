// Importe la librairie pour les leds
#include <FastLED.h>

// Définition du nombre de leds
#define NUM_LEDS 30
// Définition du numéro de sortie arduino
#define DATA_PIN 5

// Définition du ruban de leds
CRGB leds[NUM_LEDS];

// Etats des leds sur le ruban
int etat[NUM_LEDS];


void setup() {
  // Initialisation du ruban de leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // Attente de 100 millisecondes
  delay(100);
}


void mets_a_jour(int led) {
  // Si la led a commencé à clignoter, continuer
  if (etat[led] > 0) {
    // Si la led est dans les 50 premier cycles, augmenter la luminosité de 1
    if (etat[led] <= 50) {
      leds[led].r = leds[led].r + 1;
    }
    // Si la led est entre le 50e et le 100e cycle, diminuer la luminosité de 1
    else if (etat[led] <= 100) {
      leds[led].r = leds[led].r - 1;
    }
    // Augmenter l'état de la led
    etat[led] += 1;
  }

  

  // Remettre à 0 si l'état de la led à dépassé 100
  if (etat[led] > 100) {
    etat[led] = 0;
  }
}

void loop() {
  // Initialisation de l'état de la première led
  etat[0] = 1;

  while (true) {
    // Mise à jour de toutes les leds
    for (int led=0 ; led<NUM_LEDS ; led++) {
      mets_a_jour(led);
      // Déclenche la led suivante si besoin
      if (etat[led] == 15) {
        etat[(led + 1) % NUM_LEDS] = 1;
      }
    }

    // Affichage du nouvel état
    FastLED.show();
    delay(5);
  }
}
