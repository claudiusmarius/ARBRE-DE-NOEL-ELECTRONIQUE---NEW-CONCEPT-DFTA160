  // BouleNoel2024A09
  // Etoile filante
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
  strip.clear();
  int startPos = random(NUM_LEDS);
  for (int i = 0; i < NUM_LEDS / 2; i++) 
  {
  strip.setPixelColor((startPos + i) % NUM_LEDS, strip.Color(255 - i * 50, 255 - i * 50, 255));
  strip.show();
  delay(100);
  }
  }
