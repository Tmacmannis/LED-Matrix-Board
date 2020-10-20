// Copyright (2018) Soulmate Lighting, LLC

#ifndef RAIN_H
#define RAIN_H
#define NUM_RAINDROPS 12
#define RAINDROP_DROP_LENGTH 16

class Raindrop {
public:
  int x;
  float y = -2;

  Raindrop() {
    x = random(0, MATRIX_WIDTH);
  }

  void start() {
    x = random(0, MATRIX_WIDTH);
    y = random(-2, 16);
  }

  void reset(int newX) {
    x = newX;
    y = random(-15, -2);
  }

  void draw(int8_t hue) {
    int16_t thisHue = hue + x * 2;

    // Draw head
    int16_t index = leds.mXY(x,y);
    if (y >= 0 && y < 16) {
      matrixleds[index] = CHSV(thisHue, 255, brightness);
    }

    // Draw leading pixel
    int16_t nextY = y - 1;
    int16_t nextIndex = leds.mXY(x,nextY);
    if (y >= 1 && y < 16) {
      matrixleds[nextIndex] = CHSV(thisHue, 255, brightness);
    }

    // // Another leading pixel
    // float nextnextY = y - 2;
    // int16_t nextnextIndex = leds.mXY(x,nextnextY);
    // if (y >= 2 && y < 16) {
    //   matrixleds[nextnextIndex] =
    //       CHSV(thisHue, 255, brightness);
    // }
  }

  bool move() {
    if (y >= 16)
      return false;
    y += 1;
    return true;
  }
};

namespace Rain {
  int8_t hue = 0;
  Raindrop raindrops[NUM_RAINDROPS] = {};

  // Check there isn't a raindrop in the way...
  bool checkNewRaindrop(int x) {
    for (int i = 0; i < NUM_RAINDROPS; i++) {
      Raindrop drop = raindrops[i];
      // if (drop.x == x && drop.y > MATRIX_HEIGHT - RAINDROP_DROP_LENGTH) {
      //   return false;
      // }
    }
    return true;
  }

  // Start a raindrop at the top
  void resetRaindrop(int raindropIndex) {
    int x = random(0, MATRIX_WIDTH);
    if (checkNewRaindrop(x)) {
      raindrops[raindropIndex].reset(x);
    }
  }

  bool started = false;

  void draw() {
    if (!started) {
      started = true;
      for (int16_t i = 0; i < NUM_RAINDROPS; i++) {
        raindrops[i].start();
      }
    }

    // Move all the raindrops. If they can't move, reset them
    EVERY_N_MILLISECONDS(10) {
      for (int16_t i = 0; i < NUM_RAINDROPS; i++) {
        if (!raindrops[i].move()) {
          resetRaindrop(i);
        }
      }
    }

    // Draw all the raindrops
    for (int i = 0; i < NUM_RAINDROPS; i++) {
      raindrops[i].draw(hue);
    }

    // Change colour
    EVERY_N_MILLISECONDS(120) {
      hue++;
    }

    // Fade tails
    fadeToBlackBy(matrixleds, NUM_LEDS, 10);
  }
} // namespace Rain

#endif

void draw(int dur, int cur) {
	while(millis() - cur < dur){
	  Rain::draw();
	  matrix->show();
	  checkForUpdates();
  	}
}