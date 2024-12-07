  // BouleNoel2024A07
  // Respiration
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
  for (int brightness = 0; brightness <= 255; brightness += 5) 
  {
  setAll(strip.Color(255, 0, 0), brightness);  // Rouge
  delay(20);
  }
  for (int brightness = 255; brightness >= 0; brightness -= 5) 
  {
  setAll(strip.Color(0, 255, 0), brightness);  // Vert
  delay(20);
  }
  }

  void setAll(uint32_t color, int brightness) 
  {
  for (int i = 0; i < NUM_LEDS; i++) 
  {
  strip.setPixelColor(i, color);
  }
  strip.setBrightness(brightness);
  strip.show();
  }
