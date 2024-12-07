  // BouleNoel2024A04
  // Battement Bleu, Vert, Rouge 
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define PIN 0
  #define NUM_LEDS 12
  // Parameter 1 = number of pixels in strip
  // Parameter 2 = pin number (most are valid)
  // Parameter 3 = pixel type flags, add together as needed:
  //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
  //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
  //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
  //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
  {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  }

  void loop() 
  {
  RGBLoop();
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
  for(int i = 0; i < NUM_LEDS; i++ ) 
  {
  setPixel(i, red, green, blue);
  }
  showStrip();
  }

  void RGBLoop()
  {
  for(int j = 0; j < 3; j++ ) 
  {
  // Fade IN
  for(int k = 0; k < 256; k++) 
  {
  switch(j) 
  {
  case 0: setAll(k,0,0); break;
  case 1: setAll(0,k,0); break;
  case 2: setAll(0,0,k); break;
  }
  showStrip();
  delay(3);
  }
  // Fade OUT
  for(int k = 255; k >= 0; k--) 
  {
  switch(j) 
  {
  case 0: setAll(k,0,0); break;
  case 1: setAll(0,k,0); break;
  case 2: setAll(0,0,k); break;
  }
  showStrip();
  delay(3);
  }
  }
  }
