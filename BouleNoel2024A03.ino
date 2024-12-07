  // BouleNoel2024A03
  // Fire 
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius
  
  #include <Adafruit_NeoPixel.h>
  #define PIN 0
  #define NUM_LEDS 12

  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
  {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  }

  void loop() 
  {
  Fire(55, 120, 15);
  }

  void Fire(int Cooling, int Sparking, int SpeedDelay) 
  {
  static byte heat[NUM_LEDS];
  int cooldown;

  // Step 1. Cool down every cell a little
  for (int i = 0; i < NUM_LEDS; i++) 
  {
  cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);
  if (cooldown > heat[i]) 
  {
  heat[i] = 0;
  } else {
  heat[i] = heat[i] - cooldown;
  }
  }

  // Step 2. Heat from each cell drifts 'up' and diffuses a little
  for (int k = NUM_LEDS - 1; k >= 2; k--) 
  {
  heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  // Step 3. Randomly ignite new 'sparks' near the bottom
  if (random(255) < Sparking) 
  {
  int y = random(7);
  heat[y] = heat[y] + random(160, 255);
  }

  // Step 4. Convert heat to LED colors
  for (int j = 0; j < NUM_LEDS; j++) 
  {
  setPixelHeatColor(j, heat[j]);
  }

  showStrip();
  delay(SpeedDelay);
  }

  void setPixelHeatColor(int Pixel, byte temperature) 
  {
  byte t192 = round((temperature / 255.0) * 191);
  byte heatramp = t192 & 0x3F;
  heatramp <<= 2;

  if (t192 > 0x80) 
  {
  setPixel(Pixel, 255, 255, heatramp);
  } 
  else if (t192 > 0x40) 
  {
  setPixel(Pixel, 255, heatramp, 0);
  } 
  else 
  {
  setPixel(Pixel, heatramp, 0, 0);
  }
  }

  void showStrip() 
  {
  strip.show();
  }

  void setPixel(int Pixel, byte red, byte green, byte blue) 
  {
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
  }

  void setAll(byte red, byte green, byte blue) 
  {
  for (int i = 0; i < NUM_LEDS; i++) 
  {
  setPixel(i, red, green, blue);
  }
  showStrip();
  }

