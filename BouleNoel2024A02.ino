  // BouleNoel2024A02
  // Strandtest
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius 
  
  #include <Adafruit_NeoPixel.h>
  #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
  
  #define LED_PIN1    0
  #define LED_COUNT1 12

  Adafruit_NeoPixel strip1(LED_COUNT1, LED_PIN1, NEO_GRB + NEO_KHZ800);
 
  void setup() 
  {
  clock_prescale_set(clock_div_1);
  strip1.begin();
  strip1.show();
  strip1.setBrightness(50);
  }

  void loop() 
  {
  colorWipe(strip1.Color(255,   0,   0), 50); // Red
  colorWipe(strip1.Color(  0, 255,   0), 50); // Green
  colorWipe(strip1.Color(  0,   0, 255), 50); // Blue
  theaterChase(strip1.Color(127, 127, 127), 50); // White, half brightness
  rainbow(0.5);             // Flowing rainbow cycle along the whole strip
  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
  }

  void colorWipe(uint32_t color, int wait) 
  {
  for(int i=0; i<strip1.numPixels(); i++) 
  { 
  strip1.setPixelColor(i, color);
  strip1.show();
  delay(wait);                                                   
  }
  }

  void theaterChase(uint32_t color, int wait) 
  {
  for(int a=0; a<10; a++) 
  {  
  for(int b=0; b<3; b++) 
  { 
  strip1.clear();
  for(int c=b; c<strip1.numPixels(); c += 3) 
  {
  strip1.setPixelColor(c, color);
  }
  strip1.show(); // Update strip1 with new contents
  delay(wait);  // Pause for a moment
  }
  }
  }

  void rainbow(int wait) 
  {
  for(long firstPixelHue1 = 0; firstPixelHue1 < 5*65536; firstPixelHue1 += 256) 
  {
  for(int i=0; i<strip1.numPixels(); i++) 
  { 
  int pixelHue1 = firstPixelHue1 + (i * 65536L / strip1.numPixels());
  strip1.setPixelColor(i, strip1.gamma32(strip1.ColorHSV(pixelHue1)));
  }
  strip1.show();
  delay(wait);  
  }   
  }
  

  void theaterChaseRainbow(int wait) 
  {
  int firstPixelHue1 = 0;     // First pixel starts at red (hue 0)
  for(int a=0; a<30; a++)   // Repeat 30 times...
  {
  for(int b=0; b<3; b++)  //  'b' counts from 0 to 2...
  {
  strip1.clear();
  for(int c=b; c<strip1.numPixels(); c += 3) 
  {
  int hue1 = firstPixelHue1 + c * 65536L / strip1.numPixels();
  uint32_t color = strip1.gamma32(strip1.ColorHSV(hue1)); // hue -> RGB
  strip1.setPixelColor(c, color); // Set pixel 'c' to value 'color'
  strip1.show();                
  delay(wait);                 
  firstPixelHue1 += 65536 / 90; 
  }   
  }  
  }
  }
