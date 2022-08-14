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

  // Définition d'une coordonnée de leds
  int num = 5;
  // Changement de la couleur de la led
  leds[num].r = 255; 
  leds[num].g = 0; 
  leds[num].b = 0;
  // Affichage sur le ruban
  FastLED.show();
}

void loop() {
  
}
