#include <FastLED.h>
#include <FastLED_GFX.h> // https://github.com/Jorgen-VikingGod/FastLED-GFX
#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>
#include <LEDSprites.h>



#define LED_PIN        12
#define COLOR_ORDER    RGB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   32  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_HEIGHT  16  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_TYPE    (MTX_MATRIX_TOP + MTX_MATRIX_LEFT + MTX_MATRIX_ROWS + MTX_MATRIX_PROGRESSIVE) // See top of LEDMatrix.h for matrix wiring types
#define MATRIX_TYPE2   (MTX_MATRIX_BOTTOM + MTX_MATRIX_LEFT + MTX_MATRIX_ROWS + MTX_MATRIX_PROGRESSIVE) // See top of LEDMatrix.h for matrix wiring types

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;
cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE2> leds2;
cLEDText ScrollingMsg;

double hue;
int16_t counter;
double hueIncrement = 4;
int8_t color = 0;
int x = 0; 
int y = 1;
int z = 2;
int directions;

int SpectrumStrobe = 10;
int SpectrumReset = 9;
int SpectrumLeft[16];
int ActualRight[7];
int ActualLeft[7];
int SpectrumRight[16];
int SpectrumBand;
double temp;
int rounded,rounded2;

int numReadings = 15;
int total = 0;

void setup()
{
  Serial.begin(9600);
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());

  FastLED.setBrightness(50);
  hue = 0;
  counter = 0;

  pinMode(0, INPUT);//inputs 0-5 from selector switch
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  
  pinMode(SpectrumReset, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(SpectrumStrobe, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(SpectrumReset, HIGH);
  digitalWrite(SpectrumReset, LOW);
  delayMicroseconds(75);
  digitalWrite(SpectrumStrobe, HIGH);
  delayMicroseconds(75);
}
  
  
 

void loop()
{
  

  readBrightness();
  
  //Selector Switch to pick program
  
 if (digitalRead(0) == LOW){
  FastLED.clear();
  digitalWrite(11, LOW);
  }
 else if (digitalRead(1) == LOW){ 
  digitalWrite(11, HIGH);
  FastLED.clear();
  runAnim(200);
  }
 else { 
  FastLED.clear();
  digitalWrite(11, HIGH);
  Spectrum(80);
  }
}



//Functions ***************************

//Brightness
void readBrightness(){
for (int thisReading = 0; thisReading < numReadings; thisReading++){
    total = total + analogRead(1);
  }
 int val = (total)/(numReadings);
 total = 0;
 int bright = map(val,1023,0,240,1);
 FastLED.setBrightness(bright);
}

//SoundOffset
void readSoundLevel(){
for (int thisReading = 0; thisReading < numReadings; thisReading++){
    total = total + analogRead(2);
  }
 int val = (total)/(numReadings);
 total = 0;
 int soundOffset = map(val,1023,0,245,1);
}




