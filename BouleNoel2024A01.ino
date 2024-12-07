  // BouleNoel2024A01
  // RuningLight Bleu, Vert, Rouge 
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define PIN 0
  #define NUMPIXELS 12
  #define BRIGHTNESS 4

  Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
  {
  pixels.begin();      // Initialiser les NeoPixels
  pixels.setBrightness (BRIGHTNESS);
  pixels.show();       // Éteint tous les pixels au démarrage
  }

  void loop() 
  {
  RunningLights(0,0,255, 200);
  RunningLights(0,255,0, 200);
  RunningLights(255,0,0, 200);
  }

  void showStrip() 
  {
  pixels.show(); 
  }

  void setPixel(int Pixel, byte red, byte green, byte blue) 
  {
  pixels.setPixelColor(Pixel, pixels.Color(red, green, blue));
  }

  void setAll(byte red, byte green, byte blue) 
  {
  for(int i = 0; i < NUMPIXELS; i++ ) 
  {
  setPixel(i, red, green, blue);
  }
  showStrip();
  }

  void RunningLights(byte red, byte green, byte blue, int WaveDelay) 
  {
  int Position=0;
 
  //for(int j=0; j<NUMPIXELS*2; j++)
  for(int j=0; j<NUMPIXELS*10; j++)
  {
  Position++; // = 0; //Position + Rate;
  for(int i=0; i<NUMPIXELS; i++) 
  {
  // sine wave, 3 offset waves make a rainbow!
  //float level = sin(i+Position) * 127 + 128;
  //setPixel(i,level,0,0);
  //float level = sin(i+Position) * 127 + 128;
  setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,((sin(i+Position) * 127 + 128)/255)*green,((sin(i+Position) * 127 + 128)/255)*blue);
  } 
  showStrip();
  delay(WaveDelay);
  }
  }
