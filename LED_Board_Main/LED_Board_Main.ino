#define FASTLED_ALLOW_INTERRUPTS 0
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <LEDMatrix.h>
#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>

#define PIN 12
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 16
#define NUMMATRIX (MATRIX_WIDTH*MATRIX_HEIGHT)
#define MATRIX_TYPE    (MTX_MATRIX_TOP + MTX_MATRIX_LEFT + MTX_MATRIX_ROWS + MTX_MATRIX_PROGRESSIVE)
#define NUM_LEDS MATRIX_WIDTH*MATRIX_HEIGHT

int brightness = 255;
int lastBrightness = 0;
int currentAnimation;

String textToPrint = "Jordan... pull me a mother fucking grav please..";

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;


CRGB *matrixleds = leds[0];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(matrixleds, MATRIX_WIDTH, MATRIX_HEIGHT, 1, 1, 
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE );

const uint16_t colors[] = {
  matrix->Color(255, 0, 0), matrix->Color(0, 255, 0), matrix->Color(0, 0, 255) };


// These parameters adjust the vertical thresholds
const float maxLevel = 0.3;      // 1.0 = max, lower is more "sensitive"
const float dynamicRange = 50.0; // total range to display, in decibels
const float linearBlend = 0.3;   // useful range is 0 to 0.7

// Audio library objects
AudioInputAnalog         adc1;       //xy=99,55
AudioAnalyzeFFT1024      fft;            //xy=265,75
AudioConnection          patchCord1(adc1, fft);

float thresholdVertical[MATRIX_HEIGHT];

int frequencyBinsHorizontal[MATRIX_WIDTH] = {
   1,  1,  1,  1,  1,
   2,  2,  2,  2,  3,
   3,  3,  3,  3,  4,
   5,  5,  6,  6,  6,
   9,  9, 10, 10, 11,
  15, 16, 17, 18, 19, 20, 22
};


void setup() {
  Serial.begin(57600);
  while (!Serial) {;}

  AudioMemory(12);
  computeVerticalLevels();
  
  FastLED.addLeds<WS2812B,PIN,RGB>(matrixleds, NUMMATRIX); 
  matrix->begin();
  leds.setTextWrap(false);
  matrix->setBrightness(brightness);
  leds.setTextColor(colors[0]);
}

void loop() {
	checkForUpdates();
	randomShowSelector();
  // spectrum();

  // randomBlinks(random(5000, 20000), millis());
  // draw(random(5000, 20000), millis());


}

bool checkForUpdates(){
  readDataFromPI();
  if(showNewData()){
    return true;
  }

}

void randomShowSelector(){

    switch(random(1,8)){
      case 1:
          testAnimation(random(5000, 15000), millis());
          break;
      case 2:
          showFireworks(0, random(3, 15));
          break;
      case 3:
          randomBlinks(random(5000, 20000), millis());
          break;
      case 4:
          draw(random(5000, 20000), millis());
          break;
      case 5:
          testText(random(5000, 20000), millis(), random(0,8), random(50, 100));
          break;
      case 6:
          spectrum(random(5000, 20000), millis());
          break;
      case 7:
          spectrum(random(5000, 20000), millis());
          break;
    }

}
