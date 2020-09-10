void textTest(int runTime){

FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds2[0], leds2.Size());


const unsigned char TxtDemo[] = { EFFECT_FRAME_RATE "\x00"
                                  EFFECT_SCROLL_LEFT "                         This is a test of how long text can be here " };


  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&leds2, leds2.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0x00, 0xff);
  int count = 1;
while (count==1){
  if (ScrollingMsg.UpdateText() == -1){
    ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
    count = 0;
    leds.drawPixel(0,0,CHSV(55, 255, 255));
    FastLED.show();
    delay(500);
     leds2.drawPixel(0,0,CHSV(0, 0, 0));
    FastLED.show();
    delay(500);
    break;
     
  }
  else{
    FastLED.show();
  delay(10);
  }
  }

FastLED.clear();
FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
}

