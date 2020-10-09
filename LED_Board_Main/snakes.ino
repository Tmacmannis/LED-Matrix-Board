// #define SNAKES_COUNT 5

// class Asnake {
//   uint16_t snakeIndices[100];
//   uint16_t snakeLength;
//   int direction;
//   int hue;
//   int step;
//   unsigned long lastStepAt = millis();
//   bool dead;
  
//   void die() {
//     dead = true;
//     headX = random(0, MATRIX_WIDTH);
//     headY = random(0, MATRIX_HEIGHT);
//     snakeLength = 3;
//     direction = random(0, 3);
//     hue = random(0, 255);
//     step = 70;
//   }
  
//   public:
//     Asnake() {
//       // die();
//       headX = random(0, MATRIX_WIDTH);
//       headY = random(0, MATRIX_HEIGHT);
//       snakeLength = 3;
//       direction = random(0, 3);
//       hue = random(0, 255);
//       step = 70;
//       dead = false;
//     }
  
//   bool isBlocked(int16_t x, int16_t y) {
//     int16_t index = gridIndexHorizontal(x, y);
//     if (Soulmate.leds[index] == CRGB(0, 255, 0)) {
//       return false;
//     } else if (Soulmate.leds[index] == CRGB(0, 0, 0)) {
//       return false;
//     } else {
//       return true;
//     }
//   }
  
//   int16_t headX = 0;
//   int16_t headY = 0;
  
//   void drawPixels() {
//     for (uint16_t i = 0; i < snakeLength; i++) {
//       Soulmate.leds[snakeIndices[i]] = CHSV(hue, 255, 255);
//     }
//   }
  
//   void move(int16_t fruitX, int16_t fruitY) {
//     if ((int)(millis() - lastStepAt) < step && !dead) {
//       drawPixels();
//       return;
//     };
    
//     dead = false;
    
//     lastStepAt = millis();
    
//     bool move = false;
//     int tries = 0;
    
//     bool r = random(0, 100) > 50;
    
//     if (r) {
//       if (fruitX > headX) {
//         direction = 0; // right
//       } else if (fruitY > headY) {
//         direction = 1; // up
//       } else if (fruitX < headX) {
//         direction = 2; // left
//       } else if (fruitY < headY) {
//         direction = 3; // down
//       } else {
//         direction = random(0, 4);
//       }
//     } else {
//       if (fruitY < headY) {
//         direction = 3; // down
//       } else if (fruitX < headX) {
//         direction = 2; // left
//       } else if (fruitY > headY) {
//         direction = 1; // up
//       } else if (fruitX > headX) {
//         direction = 0; // right
//       } else {
//         direction = random(0, 4);
//       }
//     }
    
//     while (!move && tries <= 10) {
//       if (direction == 0 && headX < MATRIX_WIDTH - 2) {
//         if (isBlocked(headX + 1, headY)) {
//           move = false;
//         } else {
//           headX++;
//           move = true;
//         }
//       } else if (direction == 1 && headY < MATRIX_HEIGHT - 2) {
//         if (isBlocked(headX, headY + 1)) {
//           move = false;
//         } else {
//           headY++;
//           move = true;
//         }
//       } else if (direction == 2 && headX > 0) {
//         if (isBlocked(headX - 1, headY)) {
//           move = false;
//         } else {
//           headX--;
//           move = true;
//         }
//       } else if (direction == 3 && headY > 0) {
//         if (isBlocked(headX, headY - 1)) {
//           move = false;
//         } else {
//           headY--;
//           move = true;
//         }
//       } else {}
//       if (!move) {
//         tries++;
//         direction++;
//         if (direction == 4) {
//           direction = 0;
//         }
//       }
//     }
    
//     if (!move || tries >= 10) {
//       die();
//     } else {
//       int16_t index = gridIndexHorizontal(headX, headY);
//       snakeIndices[snakeLength] = index;
//       if (fruitX == headX && fruitY == headY) {
        
//         step = step * 0.9;
        
//         if (snakeLength < 100) {
//           snakeLength++;
//         } else {
//           move = false;
//           die();
//         }
//       } else {
//         for (int i = 0; i < snakeLength; i++) {
//           snakeIndices[i] = snakeIndices[i + 1];
//         }
//       }
//     }
    
//     if (move) {
//       drawPixels();
//     }
//   }
// };

// namespace Snake {
//   Asnake snakes[SNAKES_COUNT];
  
//   uint16_t fruitX = 5;
//   uint16_t fruitY = 5;
  
//   void resetFruit() {
//     fruitX = (int) random(0, MATRIX_WIDTH - 2);
//     fruitY = (int) random(0, MATRIX_HEIGHT - 2);
//   }
  
//   void draw() {
//     EVERY_N_MILLISECONDS(150) {
//       // fill_solid(Soulmate.leds, N_LEDS, CRGB::Black);
//       fadeToBlackBy(Soulmate.leds, N_LEDS, 80);
      
//       int16_t fruitIndex = gridIndexHorizontal(fruitX, fruitY);
//       Soulmate.leds[fruitIndex] = CRGB(0, 255, 0);
      
//       for (int i = 0; i < SNAKES_COUNT; i++) {
//         snakes[i].move(fruitX, fruitY);
        
//         if (snakes[i].headX == fruitX && snakes[i].headY == fruitY) {
//           resetFruit();
//         }
//       }
//     }
//   }
// } // namespace Snake

// void draw() {
//   Snake::draw();
// }