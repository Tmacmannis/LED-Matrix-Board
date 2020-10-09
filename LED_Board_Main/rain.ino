// byte rain[NUM_LEDS];
// int speed = 1;

// void rainAnimation(){
// 	raininit();


// }


// void changepattern () {
//   int rand1 = random16 (NUM_LEDS);
//   int rand2 = random16 (NUM_LEDS);
//   if ((rain[rand1] == 1) && (rain[rand2] == 0) )   //simple get two random dot 1 and 0 and swap it,
//   {
//     rain[rand1] = 0;  //this will not change total number of dots
//     rain[rand2] = 1;
//   }
// } //changepattern

// void raininit() {                               //init array of dots. run once
//   for (int i = 0; i < NUM_LEDS; i++) {
//     if (random8(20) == 0) {
//       rain[i] = 1;  //random8(20) number of dots. decrease for more dots
//     }
//     else {
//       rain[i] = 0;
//     }
//   }
// } //raininit

// void updaterain() {
//   for (byte i = 0; i < MATRIX_WIDTH; i++) {
//     for (byte j = 0; j < MATRIX_HEIGHT; j++) {
//       byte layer = rain[XY(i, ((j + speed + random8(2) + MATRIX_HEIGHT) % MATRIX_HEIGHT))];   //fake scroll based on shift coordinate
//       // random8(2) add glitchy look
//       if (layer) {
//         // leds[XY((MATRIX_WIDTH - 1) - i, (MATRIX_HEIGHT - 1) - j)] = CHSV(110, 255, brightness);
//         leds.pixel((MATRIX_WIDTH - 1) - i, (MATRIX_HEIGHT - 1) - j) = CHSV(110, 255, brightness);
//       }
//     }
//   }

//   speed ++;
// //    leds.fadeToBlackBy(40);
//   // blurRows(leds, MATRIX_WIDTH, MATRIX_HEIGHT, 16);      //if you want
// } //updaterain

// uint16_t XY (uint8_t x, uint8_t y) {
//   return (y * MATRIX_WIDTH + x);
// }
