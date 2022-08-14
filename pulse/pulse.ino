// Importe la librairie pour les leds
#include <FastLED.h>

// Définition du nombre de leds
#define NUM_LEDS 30
// Définition du numéro de sortie arduino
#define DATA_PIN 5

// Définition du ruban de leds
CRGB leds[NUM_LEDS];


void setup() {
  // Initialisation du ruban de leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // Attente de 100 millisecondes
  delay(100);
}

void loop() {
  // Augmente progressivement l'intensité de la led 10
  for (int i=0 ; i<50 ; i++) {
    leds[10].g = i;
    // Affichage sur le ruban
    FastLED.show();
    delay(20);
  }

  // éteint la led pendant 100ms
  leds[10].g = 0;
  FastLED.show();
  delay(500);
}
