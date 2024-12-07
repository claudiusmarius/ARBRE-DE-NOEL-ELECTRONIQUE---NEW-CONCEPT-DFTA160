  // BouleNoel2024B03
  // Chase doux
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define PIN 0
  #define NUM_LEDS 12
  #define BRIGHTNESS 50

  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
  {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();
  }

  void loop() 
  { 
  for (int i = 0; i < NUM_LEDS; i++) 
  {
  strip.clear();
  strip.setPixelColor(i, strip.Color(255, 0, 100)); // Violet doux
  strip.show();
  delay(100);
  }
  }
