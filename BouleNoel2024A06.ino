  // BouleNoel2024A06
  // Theatre, mais très adapté pour des rings
  // ATtiny85
  // Ring 12 LEDs
  // claude.dufourmont@laposte.net
  // https://www.youtube.com/c/ClaudeDufourmont
  // https://github.com/claudiusmarius

  #include <Adafruit_NeoPixel.h>
  #define BrocheMatrice1_25  0                                                                            
  
  int tableauCouleurs [] = {                                                                                            // Tableau des couleurs ce tableau est là pour rappeler codes couleurs
  255, 255, 255,                                                                                                        // Blanc
  255, 0, 0,                                                                                                            // Rouge
  0, 255, 0,                                                                                                            // Vert
  0, 0, 255,                                                                                                            // Bleu
  255, 0, 255,                                                                                                          // Violet
  0, 255, 255,                                                                                                          // Cyan
  255, 125, 0,                                                                                                          // Jaune
  255, 40, 0,                                                                                                           // Orange
  255, 0, 100                                                                                                           // Rose
  };
    
  const int nombreLEDMatrice1_25 = 12;                                                                                        
  int LuminositeCourante = 20;                                                                                           
  int Sequence = 0;                                                                                                       
  unsigned long VitesseSlide = 50;

  Adafruit_NeoPixel Matrice1_25(nombreLEDMatrice1_25, BrocheMatrice1_25, NEO_GRB + NEO_KHZ800);
  
  
  void setup() 
  {
  Matrice1_25.begin();           
  Matrice1_25.show();            
  Matrice1_25.setBrightness(20); 
  }

  void loop() 
  {
  Matrice1_25.clear();
  Matrice1_25.show();
  
  theaterChase(Matrice1_25.Color(255, 0, 0), 10);
  theaterChase(Matrice1_25.Color(0, 255, 0), 10);
  theaterChase(Matrice1_25.Color(0, 255, 255),10);
  theaterChase(Matrice1_25.Color(255, 125, 0),10);
  theaterChase(Matrice1_25.Color(0, 255, 0), 10);
  theaterChase(Matrice1_25.Color(200,   150,   255),10);
  theaterChase(Matrice1_25.Color(255,   120,   120),10);
  theaterChase(Matrice1_25.Color(0, 0,  255),10);
  theaterChase(Matrice1_25.Color(255,   150,   255), 10);
  theaterChase(Matrice1_25.Color(255,   120,   120), 10);
  theaterChase(Matrice1_25.Color(100,   255,   120), 10);
  theaterChase(Matrice1_25.Color(255,   0,   0), 10);
  theaterChase(Matrice1_25.Color(255,   255,   90), 10);
  theaterChase(Matrice1_25.Color(40,   30,   255), 10);
  theaterChase(Matrice1_25.Color(50,   255,   255), 10);
  theaterChase(Matrice1_25.Color(255,   0,   10), 0);
  theaterChase(Matrice1_25.Color(200,   150,   255), 10);
  theaterChase(Matrice1_25.Color(255,   120,   120), 10);
  theaterChase(Matrice1_25.Color(255,   255,   0), 10);
  theaterChase(Matrice1_25.Color(255,   0,   255), 10);
  theaterChase(Matrice1_25.Color(200,   240,   255),10);
  theaterChase(Matrice1_25.Color(255,   120,   120), 10);
  theaterChase(Matrice1_25.Color(100,   255,   120), 10);

  theaterChase(Matrice1_25.Color(255, 0, 0), 2);
  theaterChase(Matrice1_25.Color(0, 0, 255), 2);
  theaterChase(Matrice1_25.Color(255, 0, 0), 2);
  theaterChase(Matrice1_25.Color(0, 0, 255), 2);
  theaterChase(Matrice1_25.Color(255, 0, 0), 2);
  theaterChase(Matrice1_25.Color(0, 0, 255), 2);
  theaterChase(Matrice1_25.Color(255, 0, 0), 2);
  theaterChase(Matrice1_25.Color(0, 0, 255), 2);

  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  theaterChase(Matrice1_25.Color(0, 255, 0), 1);
  theaterChase(Matrice1_25.Color(0, 0, 255), 1);
  }
   
  void theaterChase(uint32_t CouleurSlide1 ,int wait) 
  {
  for(int a=0; a<5; a++) 
  { 
  for(int b=0; b<3; b++)
  {
  for(int e=0; e<3; e++)
  { 
  Matrice1_25.clear();
  for(int c=b; c<Matrice1_25.numPixels(); c += 3)
  {  
  { 
  Matrice1_25.setPixelColor(c,CouleurSlide1);
  }
  }
  }
  Matrice1_25.show();
  delay(100);  
  }
  }
  }
  
  
  
