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

  // On parcours chacune des adresses des leds
  for (int i=0 ; i<NUM_LEDS ; i = i + 1) {
    // Allumage de la led i
    leds[i].r = 255; 
    leds[i].g = 0; 
    leds[i].b = 0;
    // Affichage sur le ruban
    FastLED.show();

    // On laisse la led affichée 100ms
    delay(100);

    // Extinction de la led i
    leds[i].r = 0; 
    leds[i].g = 0; 
    leds[i].b = 0;
    // Affichage sur le ruban
    FastLED.show();
  }
}

void loop() {
  
}
