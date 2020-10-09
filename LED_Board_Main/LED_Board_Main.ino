#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <LEDMatrix.h>

#define PIN 12
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 16
#define NUMMATRIX (MATRIX_WIDTH*MATRIX_HEIGHT)
#define MATRIX_TYPE    (MTX_MATRIX_TOP + MTX_MATRIX_LEFT + MTX_MATRIX_ROWS + MTX_MATRIX_PROGRESSIVE)

int brightness = 127;
int lastBrightness = 0;

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;


CRGB *matrixleds = leds[0];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(matrixleds, MATRIX_WIDTH, MATRIX_HEIGHT, 1, 1, 
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE );

const uint16_t colors[] = {
  matrix->Color(255, 0, 0), matrix->Color(0, 255, 0), matrix->Color(0, 0, 255) };

void setup() {
  Serial.begin(57600);
  while (!Serial) {;}
  FastLED.addLeds<WS2812B,PIN,RGB>(matrixleds, NUMMATRIX); 
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setBrightness(brightness);
  matrix->setTextColor(colors[0]);
}

void loop() {
	checkForUpdates();
	// testAnimation(random(5000, 20000), millis());
//	showFireworks(0, random(3, 15));

  fadeToBlackBy( matrixleds, NUMMATRIX, 10);
  int pos = random16(NUMMATRIX);
  matrixleds[pos] += CHSV( 50 + random8(64), 200, brightness);
  matrix->show();
  FastLED.delay(1000/120);

}

void checkForUpdates(){
	readDataFromPI();
	showNewData();
}
