  // BouleNoel2024B04
  // Chenardillette 
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define LED_PIN    0  // or any other PWM capable pin
  #define LED_AMOUNT 12
  #define BRIGHTNESS 255   // [1..255]
  #define DEMO_DELAY 100 // in milliseconds

  Adafruit_NeoPixel apaLeds = Adafruit_NeoPixel(LED_AMOUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

  void setup()
  {
  apaLeds.begin();
  }

  void loop()
  {
  for (byte i = 0; i < LED_AMOUNT; i++) {
  apaLeds.setPixelColor(i, apaLeds.Color(0, 0, 0));
  apaLeds.show();
  delay(DEMO_DELAY);

  apaLeds.setPixelColor(i, apaLeds.Color(BRIGHTNESS, 0, 0));
  apaLeds.show();
  delay(DEMO_DELAY);

  apaLeds.setPixelColor(i, apaLeds.Color(0, BRIGHTNESS, 0));
  apaLeds.show();
  delay(DEMO_DELAY);

  apaLeds.setPixelColor(i, apaLeds.Color(0, 0, BRIGHTNESS));
  apaLeds.show();
  delay(DEMO_DELAY);
  }
  apaLeds.clear ();
  apaLeds.show();
  delay(200);
  }
