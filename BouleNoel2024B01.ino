  // BouleNoel2024B01
  // 7 couleurs une à une 
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define PIN 0          // La broche de l'ATtiny85 connectée aux NeoPixels
  #define NUMPIXELS 12    // Nombre de pixels que tu veux allumer
  #define BRIGHTNESS 4

  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
{
  pixels.begin();      // Initialiser les NeoPixels
  pixels.setBrightness(BRIGHTNESS);
  pixels.show();       // Éteint tous les pixels au démarrage
  }

  void loop() 
  {
  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Rouge
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(805);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);             // Pause avant de recommencer la boucle


  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // vert
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(801);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);             // Pause avant de recommencer la boucle

  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Bleu
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(803);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);

  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(255, 128, 0)); 
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(804);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);             // Pause avant de recommencer la boucle

  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(255, 255, 0)); 
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(807);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);             // Pause avant de recommencer la boucle

  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(0, 128, 128)); 
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(806);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);

  for (int i = 0; i < NUMPIXELS; i++) 
  {
  pixels.setPixelColor(i, pixels.Color(255, 0, 128));
  pixels.show();        // Mettre à jour l'affichage avec la couleur définie
  delay(1);           // Pause pour voir les LEDs s’allumer une à une
  }
  
  delay(800);             // Pause pour observer le résultat
  pixels.clear();          // Éteindre tous les pixels
  pixels.show();
  delay(10);
  }


