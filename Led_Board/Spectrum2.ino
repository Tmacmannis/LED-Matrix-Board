void Spectrum(int runTime){
  int h = random(1,255);
  int y = random(1,255);
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

  readBrightness();

 //***********************************************

  for (int i = 0; i < 17; i++){
  //int i = 0;  

  if ((SpectrumLeft[i]) > 200 && (SpectrumLeft[i]) <= 243 ){
    leds.DrawLine(i, 16, i, 15, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 14, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]) > 243 && (SpectrumLeft[i]) <= 286 ){
    leds.DrawLine(i, 16, i, 14,CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 13, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]) > 286 && (SpectrumLeft[i]) <= 329 ){
    leds.DrawLine(i, 16, i, 13, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 12, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]) > 329 && (SpectrumLeft[i]) <= 372 ){
    leds.DrawLine(i, 16, i, 12, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 11, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]) > 372 && (SpectrumLeft[i]) <= 415 ){
    leds.DrawLine(i, 16, i, 11, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 10, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]) > 415 && (SpectrumLeft[i]) <= 458 ){
    leds.DrawLine(i, 16, i, 10, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 9, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]) > 458 && (SpectrumLeft[i]) <= 501 ){
    leds.DrawLine(i, 16, i, 9, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 8, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]) > 501 && (SpectrumLeft[i]) <= 544 ){
    leds.DrawLine(i, 16, i, 8, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 7, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]) > 544 && (SpectrumLeft[i]) <= 587 ){
    leds.DrawLine(i, 16, i, 7, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 6, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]) > 587 && (SpectrumLeft[i]) <= 630 ){
    leds.DrawLine(i, 16, i, 6, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 5, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]) > 630 && (SpectrumLeft[i]) <= 673 ){
    leds.DrawLine(i, 16, i, 5,CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 4, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]) > 673 && (SpectrumLeft[i]) <= 716 ){
    leds.DrawLine(i, 16, i, 4, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 3, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]) > 716 && (SpectrumLeft[i]) <= 759 ){
    leds.DrawLine(i, 16, i, 3, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 2, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]) > 759 && (SpectrumLeft[i]) <= 802 ){
    leds.DrawLine(i, 16, i, 2, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 1, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]) > 802 && (SpectrumLeft[i]) <= 845 ){
    leds.DrawLine(i, 16, i, 1, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]) > 845 && (SpectrumLeft[i]) <= 888 ){
    leds.DrawLine(i, 16, i, 0,CHSV(h, 255, 255));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));  
  }
  else {}
  }

for (int i = 0; i < 17; i++){
  //int i = 0;  
 
  if ((SpectrumRight[i]) > 200 && (SpectrumRight[i]) <= 243 ){
    leds.DrawLine(i+16, 16, i+16, 15, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 14, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]) > 243 && (SpectrumRight[i]) <= 286 ){
    leds.DrawLine(i+16, 16, i+16, 14, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 13, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]) > 286 && (SpectrumRight[i]) <= 329 ){
    leds.DrawLine(i+16, 16, i+16, 13, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 12, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]) > 329 && (SpectrumRight[i]) <= 372 ){
    leds.DrawLine(i+16, 16, i+16, 12, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 11, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]) > 372 && (SpectrumRight[i]) <= 415 ){
    leds.DrawLine(i+16, 16, i+16, 11, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 10, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]) > 415 && (SpectrumRight[i]) <= 458 ){
    leds.DrawLine(i+16, 16, i+16, 10, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 9, CRGB(0, 0, 0));
   
  }
  else if ((SpectrumRight[i]) > 458 && (SpectrumRight[i]) <= 501 ){
    leds.DrawLine(i+16, 16, i+16, 9, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 8, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]) > 501 && (SpectrumRight[i]) <= 544 ){
    leds.DrawLine(i+16, 16, i+16, 8, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 7, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]) > 544 && (SpectrumRight[i]) <= 587 ){
    leds.DrawLine(i+16, 16, i+16, 7, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 6, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]) > 587 && (SpectrumRight[i]) <= 630 ){
    leds.DrawLine(i+16, 16, i+16, 6, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 5, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]) > 630 && (SpectrumRight[i]) <= 673 ){
    leds.DrawLine(i+16, 16, i+16, 5, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 4, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]) > 673 && (SpectrumRight[i]) <= 716 ){
    leds.DrawLine(i+16, 16, i+16, 4, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 3, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]) > 716 && (SpectrumRight[i]) <= 759 ){
    leds.DrawLine(i+16, 16, i+16, 3, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 2, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]) > 759 && (SpectrumRight[i]) <= 802 ){
    leds.DrawLine(i+16, 16, i+16, 2, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 1, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]) > 802 && (SpectrumRight[i]) <= 845 ){
    leds.DrawLine(i+16, 16, i+16, 1, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 0, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]) > 845 && (SpectrumRight[i]) <= 888 ){
    leds.DrawLine(i+16, 16, i+16, 0, CHSV(y, 255, 255));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));
      
  }
  else{}
}
 
  runTime --;
  FastLED.show(); 
  delay(10);
  if (runTime == 0){
    break;
  }
}
}


