  // BouleNoel2024B02
  // Multicolor progessif
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define PIN 0                // Pin de sortie pour les NeoPixels
  #define NUM_LEDS 86        // Nombre de LEDs
  #define TOTAL_STEPS 100       // Nombre de variations pour le dégradé
  #define DELAY_TIME 1000     // Temps d'attente en millisecondes pour chaque étape
  #define BRIGHTNESS_FACTOR 1 // Facteur de luminosité (réglable entre 0.0 et 1.0)

  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
  {
  strip.begin();
  strip.show(); // Initialise toutes les LEDs à 'off'
  }

  void loop() 
  {
  for (int step = 0; step < TOTAL_STEPS * 2; step++) 
  {
  int currentStep = (step < TOTAL_STEPS) ? step : (TOTAL_STEPS * 2 - 1 - step);
  uint32_t color = getColor(currentStep, TOTAL_STEPS);
  for (int i = 0; i < NUM_LEDS; i++) 
  {
  strip.setPixelColor(i, color); // Applique la couleur avec le facteur de luminosité
  }
  strip.show();
  delay(DELAY_TIME); // Attente avant de passer à la couleur suivante
  }
  }

  // Fonction pour calculer la couleur intermédiaire en fonction de l'étape avec luminosité réduite
  uint32_t getColor(int step, int totalSteps) 
  {
  float phase = (float)step / totalSteps;
  
  // Calcul des couleurs intermédiaires rouge -> vert -> bleu
  int r = (phase < 0.5) ? 255 * (1 - 2 * phase) : 0;  // Rouge diminue dans la première moitié
  int g = (phase < 0.5) ? 255 * 2 * phase : 255 * (1 - 2 * (phase - 0.5));  // Vert augmente puis diminue
  int b = (phase > 0.5) ? 255 * 2 * (phase - 0.5) : 0;  // Bleu augmente dans la deuxième moitié

  // Application du facteur de luminosité
  r *= BRIGHTNESS_FACTOR;
  g *= BRIGHTNESS_FACTOR;
  b *= BRIGHTNESS_FACTOR;

  return strip.Color(r, g, b);
  }
