  // BouleNoel2024A08
  // Strobe
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define PIN1      0
  #define N_LEDS1   12   

  Adafruit_NeoPixel strip1(N_LEDS1, PIN1, NEO_GRB + NEO_KHZ800);
  
  void setup()
  {
  strip1.begin();
  strip1.clear();
  strip1.setBrightness(100); 
  strip1.show(); 
  }
  
  void loop () 
  {
  strip1.begin();
  strip1.clear();
  strip1.setBrightness(50); 
  strip1.show();
  Strobe(0xff, 0xff, 0xff, 10, 50, 1000);       // Strobe(0xff, 0xff, 0xff, 10, 50, 1000)
  }

  void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) 
  {
  setAll(red,green,blue);
  showStrip();
  delay(FlashDelay);
  setAll(0,0,0);
  showStrip();
  delay(FlashDelay);
  }
  }

  void showStrip() 
  {
  strip1.show();
  }

  void setPixel(int Pixel, byte red, byte green, byte blue) 
  {
  strip1.setPixelColor(Pixel, strip1.Color(red, green, blue));
  }

  void setAll(byte red, byte green, byte blue) 
  {
  for(int i = 0; i < N_LEDS1; i++ ) {
  setPixel(i, red, green, blue);
  }
  showStrip();
  }

  
  
  
