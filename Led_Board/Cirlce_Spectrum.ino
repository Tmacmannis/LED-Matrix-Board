void CircleSpectrum(int runTime){
  int h = random(1,255);
  while (1){
  digitalWrite(SpectrumReset, HIGH);
  digitalWrite(SpectrumReset, LOW);
  delayMicroseconds(75);
  for(SpectrumBand = 0; SpectrumBand < 7; SpectrumBand ++)
  {
  digitalWrite(SpectrumStrobe, LOW);
  delayMicroseconds(75);
  ActualLeft[SpectrumBand] = analogRead(8);
  ActualRight[SpectrumBand] = analogRead(7);
  digitalWrite(SpectrumStrobe, HIGH);
  delayMicroseconds(80); 
  }

  SpectrumLeft[0] = ActualLeft[0];
  SpectrumLeft[1] = (ActualLeft[0]+ActualLeft[1])/2;
  SpectrumLeft[2] = ActualLeft[1];
  SpectrumLeft[4] = (ActualLeft[1]+ActualLeft[2])/2;
  SpectrumLeft[5] = ActualLeft[2];
  SpectrumLeft[6] = (ActualLeft[2]+ActualLeft[3])/2;
  SpectrumLeft[8] = ActualLeft[3];
  SpectrumLeft[9] = (ActualLeft[3]+ActualLeft[4])/2;
  SpectrumLeft[10] = ActualLeft[4];
  SpectrumLeft[12] = (ActualLeft[4]+ActualLeft[5])/2;
  SpectrumLeft[13] = ActualLeft[5];
  SpectrumLeft[14] = (ActualLeft[5]+ActualLeft[6])/2;
  SpectrumLeft[16] = ActualLeft[6];
  SpectrumLeft[3] = (SpectrumLeft[2]+SpectrumLeft[4])/2;
  SpectrumLeft[7] = (SpectrumLeft[6]+SpectrumLeft[8])/2;
  SpectrumLeft[11] = (SpectrumLeft[10]+SpectrumLeft[12])/2;
  SpectrumLeft[15] = (SpectrumLeft[14]+SpectrumLeft[16])/2;
//*******************************************************************

  SpectrumRight[0] = ActualRight[0];
  SpectrumRight[1] = (ActualRight[0]+ActualRight[1])/2;
  SpectrumRight[2] = ActualRight[1];
  SpectrumRight[4] = (ActualRight[1]+ActualRight[2])/2;
  SpectrumRight[5] = ActualRight[2];
  SpectrumRight[6] = (ActualRight[2]+ActualRight[3])/2;
  SpectrumRight[8] = ActualRight[3];
  SpectrumRight[9] = (ActualRight[3]+ActualRight[4])/2;
  SpectrumRight[10] = ActualRight[4];
  SpectrumRight[12] = (ActualRight[4]+ActualRight[5])/2;
  SpectrumRight[13] = ActualRight[5];
  SpectrumRight[14] = (ActualRight[5]+ActualRight[6])/2;
  SpectrumRight[16] = ActualRight[6];
  SpectrumRight[3] = (SpectrumRight[2]+SpectrumRight[4])/2;
  SpectrumRight[7] = (SpectrumRight[6]+SpectrumRight[8])/2;
  SpectrumRight[11] = (SpectrumRight[10]+SpectrumRight[12])/2;
  SpectrumRight[15] = (SpectrumRight[14]+SpectrumRight[16])/2;
  
  int i=2;

  if (SpectrumLeft[i] > 200 && SpectrumLeft[i] <= 243 ){
    leds.fillCircle(16, 8, 1, CHSV(h, 255, 255));
    FastLED.show();
    delay(1);
    leds.fillCircle(16, 8, 1, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > 243 && SpectrumLeft[i] <= 286 ){
    leds.fillCircle(16, 8, 1, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 2, CHSV(h, 255, 255));
    FastLED.show();
    delay(1);
    leds.fillCircle(16, 8, 1, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 2, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > 286 && SpectrumLeft[i] <= 329 ){
    leds.fillCircle(16, 8, 1, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 2, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 3, CHSV(h, 255, 255));
    FastLED.show();
    delay(1);
    leds.fillCircle(16, 8, 1, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 2, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 3, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > 329 && SpectrumLeft[i] <= 372 ){
    leds.fillCircle(16, 8, 1, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 2, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 3, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 4, CHSV(h, 255, 255));
    FastLED.show();
    delay(1);
    leds.fillCircle(16, 8, 1, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 2, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 3, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 4, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > 372 && SpectrumLeft[i] <= 415 ){
    leds.fillCircle(16, 8, 1, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 2, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 3, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 4, CHSV(h, 255, 255));
    leds.fillCircle(16, 8, 5, CHSV(h, 255, 255));
    FastLED.show();
    delay(1);
    leds.fillCircle(16, 8, 1, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 2, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 3, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 4, CRGB(0, 0, 0));
    leds.fillCircle(16, 8, 5, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > 415 && SpectrumLeft[i] <= 458 ){
    for (int i = 1; i <7; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <7; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
  }
  else if (SpectrumLeft[i] > 458 && SpectrumLeft[i] <= 501 ){
    for (int i = 1; i <8; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <8; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
  }
  else if (SpectrumLeft[i] > 501 && SpectrumLeft[i] <= 544 ){
    for (int i = 1; i <9; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <9; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
  }
  else if (SpectrumLeft[i] > 544 && SpectrumLeft[i] <= 587 ){
   for (int i = 1; i <10; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <10; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
  }
  else if (SpectrumLeft[i] > 587 && SpectrumLeft[i] <= 630 ){
    for (int i = 1; i <11; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <11; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
  }
  else if (SpectrumLeft[i] > 630 && SpectrumLeft[i] <= 673 ){
   for (int i = 1; i <12; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <12; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
    
  }
  else if (SpectrumLeft[i] > 673 && SpectrumLeft[i] <= 716 ){
    for (int i = 1; i <13; i++){
    leds.fillCircle(16, 8, i, CHSV(h, 255, 255));
    }
    FastLED.show();
    delay(1);
    for (int i = 1; i <13; i++){
    leds.fillCircle(16, 8, i, CRGB(0, 0, 0));
    }
  }
  /*
  else if (SpectrumLeft[i] > 716 && SpectrumLeft[i] <= 759 ){
    leds.DrawLine(i, 16, i, 3, CRGB(0, 255, 0));
    leds.DrawLine(i, 0, i, 2, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > 759 && SpectrumLeft[i] <= 802 ){
    leds.DrawLine(i, 16, i, 2, CRGB(0, 255, 0));
    leds.DrawLine(i, 0, i, 1, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > 802 && SpectrumLeft[i] <= 845 ){
    leds.DrawLine(i, 16, i, 1, CRGB(0, 255, 0));
    leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > 845 && SpectrumLeft[i] <= 888 ){
    leds.DrawLine(i, 16, i, 0,CRGB(0, 255, 0));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));  
  }
  */
  else {}

  runTime --;
  //FastLED.show(); 
  if (runTime == 0){
    break;
  }
  //FastLED.clear(true);
}
}
  
