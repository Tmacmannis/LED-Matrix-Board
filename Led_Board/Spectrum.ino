void Spectrum32(int runTime){
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

  for (int thisReading = 0; thisReading < numReadings; thisReading++){
    total = total + analogRead(3);
  }
  double soundOffset = 0;
 int val = (total)/(numReadings);
 total = 0;
 double readValue = map(val,1023,0,30,1);

 //***********************************************
 if (readValue < 10){
  soundOffset = (readValue/10);
  for (int i = 0; i < 17; i++){
  //int i = 0;  

  if ((SpectrumLeft[i]*soundOffset) > 200 && (SpectrumLeft[i]*soundOffset) <= 243 ){
    leds.DrawLine(i, 16, i, 15, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 14, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]*soundOffset) > 243 && (SpectrumLeft[i]*soundOffset) <= 286 ){
    leds.DrawLine(i, 16, i, 14,CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 13, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]*soundOffset) > 286 && (SpectrumLeft[i]*soundOffset) <= 329 ){
    leds.DrawLine(i, 16, i, 13, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 12, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]*soundOffset) > 329 && (SpectrumLeft[i]*soundOffset) <= 372 ){
    leds.DrawLine(i, 16, i, 12, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 11, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]*soundOffset) > 372 && (SpectrumLeft[i]*soundOffset) <= 415 ){
    leds.DrawLine(i, 16, i, 11, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 10, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]*soundOffset) > 415 && (SpectrumLeft[i]*soundOffset) <= 458 ){
    leds.DrawLine(i, 16, i, 10, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 9, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]*soundOffset) > 458 && (SpectrumLeft[i]*soundOffset) <= 501 ){
    leds.DrawLine(i, 16, i, 9, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 8, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]*soundOffset) > 501 && (SpectrumLeft[i]*soundOffset) <= 544 ){
    leds.DrawLine(i, 16, i, 8, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 7, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]*soundOffset) > 544 && (SpectrumLeft[i]*soundOffset) <= 587 ){
    leds.DrawLine(i, 16, i, 7, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 6, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]*soundOffset) > 587 && (SpectrumLeft[i]*soundOffset) <= 630 ){
    leds.DrawLine(i, 16, i, 6, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 5, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]*soundOffset) > 630 && (SpectrumLeft[i]*soundOffset) <= 673 ){
    leds.DrawLine(i, 16, i, 5,CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 4, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]*soundOffset) > 673 && (SpectrumLeft[i]*soundOffset) <= 716 ){
    leds.DrawLine(i, 16, i, 4, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 3, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumLeft[i]*soundOffset) > 716 && (SpectrumLeft[i]*soundOffset) <= 759 ){
    leds.DrawLine(i, 16, i, 3, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 2, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]*soundOffset) > 759 && (SpectrumLeft[i]*soundOffset) <= 802 ){
    leds.DrawLine(i, 16, i, 2, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 1, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumLeft[i]*soundOffset) > 802 && (SpectrumLeft[i]*soundOffset) <= 845 ){
    leds.DrawLine(i, 16, i, 1, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumLeft[i]*soundOffset) > 845 && (SpectrumLeft[i]*soundOffset) <= 888 ){
    leds.DrawLine(i, 16, i, 0,CHSV(h, 255, 255));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));  
  }
  else {}
  }

for (int i = 0; i < 17; i++){
  //int i = 0;  
 
  if ((SpectrumRight[i]*soundOffset) > 200 && (SpectrumRight[i]*soundOffset) <= 243 ){
    leds.DrawLine(i+16, 16, i+16, 15, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 14, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]*soundOffset) > 243 && (SpectrumRight[i]*soundOffset) <= 286 ){
    leds.DrawLine(i+16, 16, i+16, 14, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 13, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]*soundOffset) > 286 && (SpectrumRight[i]*soundOffset) <= 329 ){
    leds.DrawLine(i+16, 16, i+16, 13, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 12, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]*soundOffset) > 329 && (SpectrumRight[i]*soundOffset) <= 372 ){
    leds.DrawLine(i+16, 16, i+16, 12, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 11, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]*soundOffset) > 372 && (SpectrumRight[i]*soundOffset) <= 415 ){
    leds.DrawLine(i+16, 16, i+16, 11, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 10, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]*soundOffset) > 415 && (SpectrumRight[i]*soundOffset) <= 458 ){
    leds.DrawLine(i+16, 16, i+16, 10, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 9, CRGB(0, 0, 0));
   
  }
  else if ((SpectrumRight[i]*soundOffset) > 458 && (SpectrumRight[i]*soundOffset) <= 501 ){
    leds.DrawLine(i+16, 16, i+16, 9, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 8, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]*soundOffset) > 501 && (SpectrumRight[i]*soundOffset) <= 544 ){
    leds.DrawLine(i+16, 16, i+16, 8, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 7, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]*soundOffset) > 544 && (SpectrumRight[i]*soundOffset) <= 587 ){
    leds.DrawLine(i+16, 16, i+16, 7, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 6, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]*soundOffset) > 587 && (SpectrumRight[i]*soundOffset) <= 630 ){
    leds.DrawLine(i+16, 16, i+16, 6, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 5, CRGB(0, 0, 0));
    
  }
  else if ((SpectrumRight[i]*soundOffset) > 630 && (SpectrumRight[i]*soundOffset) <= 673 ){
    leds.DrawLine(i+16, 16, i+16, 5, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 4, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]*soundOffset) > 673 && (SpectrumRight[i]*soundOffset) <= 716 ){
    leds.DrawLine(i+16, 16, i+16, 4, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 3, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]*soundOffset) > 716 && (SpectrumRight[i]*soundOffset) <= 759 ){
    leds.DrawLine(i+16, 16, i+16, 3, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 2, CRGB(0, 0, 0));
      
  }
  else if ((SpectrumRight[i]*soundOffset) > 759 && (SpectrumRight[i]*soundOffset) <= 802 ){
    leds.DrawLine(i+16, 16, i+16, 2, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 1, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]*soundOffset) > 802 && (SpectrumRight[i]*soundOffset) <= 845 ){
    leds.DrawLine(i+16, 16, i+16, 1, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 0, CRGB(0, 0, 0));
     
  }
  else if ((SpectrumRight[i]*soundOffset) > 845 && (SpectrumRight[i]*soundOffset) <= 888 ){
    leds.DrawLine(i+16, 16, i+16, 0, CHSV(y, 255, 255));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));
      
  }
  else {
  }
  }
  
 }
 else {
  readValue = (readValue - 10);
 soundOffset = (readValue/10)+1;
 

  for (int i = 0; i < 17; i++){
  //int i = 0;  

  if (SpectrumLeft[i] > (300/soundOffset) && SpectrumLeft[i] <= (343/soundOffset) ){
    leds.DrawLine(i, 16, i, 15, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 14, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > (343/soundOffset) && SpectrumLeft[i] <= (386/soundOffset) ){
    leds.DrawLine(i, 16, i, 14,CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 13, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > (386/soundOffset) && SpectrumLeft[i] <= (429/soundOffset) ){
    leds.DrawLine(i, 16, i, 13, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 12, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > (429/soundOffset) && SpectrumLeft[i] <= (472/soundOffset) ){
    leds.DrawLine(i, 16, i, 12, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 11, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > (472/soundOffset) && SpectrumLeft[i] <= (515/soundOffset) ){
    leds.DrawLine(i, 16, i, 11, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 10, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > (515/soundOffset) && SpectrumLeft[i] <= (558/soundOffset) ){
    leds.DrawLine(i, 16, i, 10, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 9, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > (558/soundOffset) && SpectrumLeft[i] <= (601/soundOffset) ){
    leds.DrawLine(i, 16, i, 9, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 8, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > (601/soundOffset) && SpectrumLeft[i] <= (644/soundOffset) ){
    leds.DrawLine(i, 16, i, 8, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 7, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > (644/soundOffset) && SpectrumLeft[i] <= (687/soundOffset) ){
    leds.DrawLine(i, 16, i, 7, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 6, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > (687/soundOffset) && SpectrumLeft[i] <= (730/soundOffset) ){
    leds.DrawLine(i, 16, i, 6, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 5, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > (730/soundOffset) && SpectrumLeft[i] <= (773/soundOffset) ){
    leds.DrawLine(i, 16, i, 5,CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 4, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > (773/soundOffset) && SpectrumLeft[i] <= (816/soundOffset) ){
    leds.DrawLine(i, 16, i, 4, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 3, CRGB(0, 0, 0));
     
  }
  else if (SpectrumLeft[i] > (816/soundOffset) && SpectrumLeft[i] <= (859/soundOffset) ){
    leds.DrawLine(i, 16, i, 3, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 2, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > (859/soundOffset) && SpectrumLeft[i] <= (902/soundOffset) ){
    leds.DrawLine(i, 16, i, 2, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 1, CRGB(0, 0, 0));
    
  }
  else if (SpectrumLeft[i] > (902/soundOffset) && SpectrumLeft[i] <= (945/soundOffset) ){
    leds.DrawLine(i, 16, i, 1, CHSV(h, 255, 255));
    leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));
      
  }
  else if (SpectrumLeft[i] > (945/soundOffset) && SpectrumLeft[i] <= (988/soundOffset) ){
    leds.DrawLine(i, 16, i, 0,CHSV(h, 255, 255));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));  
  }
  else {}
  }

for (int i = 0; i < 17; i++){
  //int i = 0;  

  if (SpectrumRight[i] > (300/soundOffset) && SpectrumRight[i] <= (343/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 15, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 14, CRGB(0, 0, 0));
      
  }
  else if (SpectrumRight[i] > (343/soundOffset) && SpectrumRight[i] <= (386/soundOffset) ){
    leds.DrawLine(i+16, 16+16, i+16, 14,CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 13, CRGB(0, 0, 0));
      
  }
  else if (SpectrumRight[i] > (386/soundOffset) && SpectrumRight[i] <= (429/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 13, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 12, CRGB(0, 0, 0));
      
  }
  else if (SpectrumRight[i] > (429/soundOffset) && SpectrumRight[i] <= (472/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 12, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 11, CRGB(0, 0, 0));
     
  }
  else if (SpectrumRight[i] > (472/soundOffset) && SpectrumRight[i] <= (515/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 11, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 10, CRGB(0, 0, 0));
     
  }
  else if (SpectrumRight[i] > (515/soundOffset) && SpectrumRight[i] <= (558/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 10, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 9, CRGB(0, 0, 0));
     
  }
  else if (SpectrumRight[i] > (558/soundOffset) && SpectrumRight[i] <= (601/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 9, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 8, CRGB(0, 0, 0));
    
  }
  else if (SpectrumRight[i] > (601/soundOffset) && SpectrumRight[i] <= (644/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 8, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 7, CRGB(0, 0, 0));
     
  }
  else if (SpectrumRight[i] > (644/soundOffset) && SpectrumRight[i] <= (687/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 7, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 6, CRGB(0, 0, 0));
     
  }
  else if (SpectrumRight[i] > (687/soundOffset) && SpectrumRight[i] <= (730/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 6, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 5, CRGB(0, 0, 0));
    
  }
  else if (SpectrumRight[i] > (730/soundOffset) && SpectrumRight[i] <= (773/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 5,CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 4, CRGB(0, 0, 0));
    
  }
  else if (SpectrumRight[i] > (773/soundOffset) && SpectrumRight[i] <= (816/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 4, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 3, CRGB(0, 0, 0));
     
  }
  else if (SpectrumRight[i] > (816/soundOffset) && SpectrumRight[i] <= (859/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 3, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 2, CRGB(0, 0, 0));
    
  }
  else if (SpectrumRight[i] > (859/soundOffset) && SpectrumRight[i] <= (902/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 2, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 1, CRGB(0, 0, 0));
    
  }
  else if (SpectrumRight[i] > (902/soundOffset) && SpectrumRight[i] <= (945/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 1, CHSV(y, 255, 255));
    leds.DrawLine(i+16, 0, i+16, 0, CRGB(0, 0, 0));
      
  }
  else if (SpectrumRight[i] > (945/soundOffset) && SpectrumRight[i] <= (988/soundOffset) ){
    leds.DrawLine(i+16, 16, i+16, 0,CHSV(y, 255, 255));
    //leds.DrawLine(i, 0, i, 0, CRGB(0, 0, 0));  
  }
  else {}
  }
  
 
 }
 
  

  runTime --;
  FastLED.show(); 
  delay(10);
  if (runTime == 0){
    break;
  }
}
}

