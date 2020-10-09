void test(){
  leds.drawPixel(0,0,CHSV(55, 255, 255));
  FastLED.show(); 
  delay(100);

  FastLED.show(); 
  delay(100);
  
  FastLED.clear();
}

