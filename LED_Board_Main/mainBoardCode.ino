#include <FastLED.h>
#include <FastLED_GFX.h> // https://github.com/Jorgen-VikingGod/FastLED-GFX
#include <LEDMatrix.h>

// Change the next 6 defines to match your matrix type and size

#define LED_PIN        12
#define COLOR_ORDER    GRB
#define CHIPSET        WS2812B

#define MATRIX_WIDTH   32  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_HEIGHT  16  // Set this negative if physical led 0 is opposite to where you want logical 0
#define MATRIX_TYPE    (MTX_MATRIX_TOP + MTX_MATRIX_LEFT + MTX_MATRIX_ROWS + MTX_MATRIX_PROGRESSIVE) // See top of LEDMatrix.h for matrix wiring types
#define NUM_LEDS MATRIX_WIDTH * MATRIX_HEIGHT

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;

int brightness = 127;
int lastBrightness = 0; 

void setup() {
	Serial.begin(57600);
	while (!Serial) {;}
	FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  	FastLED.setBrightness(brightness);
  	FastLED.clear(true);
  	delay(500);
}

void loop() {
	checkForUpdates();
	testAnimation(random(5000, 20000), millis());
	showFireworks(0, random(3, 15));
}

void checkForUpdates(){
	readDataFromPI();
	showNewData();
}
