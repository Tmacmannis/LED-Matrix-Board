#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

#define PIN 12
#define mw 32
#define mh 16
#define NUMMATRIX (mw*mh)

int brightness = 127;
int lastBrightness = 0;


CRGB matrixleds[NUMMATRIX];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(matrixleds, mw, mh, 1, 1, 
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE );

const uint16_t colors[] = {
  matrix->Color(255, 0, 0), matrix->Color(0, 255, 0), matrix->Color(0, 0, 255) };

void setup() {
  Serial.begin(57600);
  FastLED.addLeds<WS2812B,PIN,RGB>(matrixleds, NUMMATRIX); 
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(brightness);
  matrix->setTextColor(colors[0]);
}

void loop() {
//	checkForUpdates();
//	testAnimation(random(5000, 20000), millis());
//	showFireworks(0, random(3, 15));
  fadeToBlackBy( matrixleds, NUMMATRIX, 10);
  int pos = random16(NUMMATRIX);
  matrixleds[pos] += CHSV( 50 + random8(64), 200, 255);
  matrix->show();
  FastLED.delay(1000/120);

}

void checkForUpdates(){
	readDataFromPI();
	showNewData();
}
