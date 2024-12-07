  // BouleNoel2024A05
  // MULTICOLORPUNCHINGBAL
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

  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

  void setup() 
  { 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  }

  void loop() 
  {
  byte colors[3][3] = { {0xff, 0,0},
                        {0xff, 0xff, 0xff},
                        {0   , 0   , 0xff} };

  BouncingColoredBalls(3, colors);
  }

  void BouncingColoredBalls(int BallCount, byte colors[][3]) 
  {
  float Gravity = -9.81;
  int StartHeight = 1;
 
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
 
  for (int i = 0 ; i < BallCount ; i++) 
  {  
  ClockTimeSinceLastBounce[i] = millis();
  Height[i] = StartHeight;
  Position[i] = 0;
  ImpactVelocity[i] = ImpactVelocityStart;
  TimeSinceLastBounce[i] = 0;
  Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
  }

  while (true) 
  {
  for (int i = 0 ; i < BallCount ; i++) 
  {
  TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
  Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
 
  if ( Height[i] < 0 ) 
  {                      
  Height[i] = 0;
  ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
  ClockTimeSinceLastBounce[i] = millis();
 
  if ( ImpactVelocity[i] < 0.01 ) 
  {
  ImpactVelocity[i] = ImpactVelocityStart;
  }
  }
  Position[i] = round( Height[i] * (NUM_LEDS - 1) / StartHeight);
  }
 
  for (int i = 0 ; i < BallCount ; i++) 
  {
  setPixel(Position[i],colors[i][0],colors[i][1],colors[i][2]);
  }
  showStrip();
  setAll(0,0,0);
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
  for(int i = 0; i < NUM_LEDS; i++ ) 
  {
  setPixel(i, red, green, blue);
  }
  showStrip();
  }
