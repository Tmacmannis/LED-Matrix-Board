void runAnim(int runTime){
  int num = random(1,19);
  Serial.println(num);
  hueIncrement = random(3,8);
  int ranTime = random(runTime,runTime*2);
  //Serial.println(num);
  switch (num) {
    case 1:
    digitalWrite(11, HIGH);
    diagonal(ranTime,hueIncrement);
    break;
    case 2:
    digitalWrite(11, HIGH);
     horizontalMirror(ranTime,hueIncrement);
     break;
     case 3:
     digitalWrite(11, HIGH);
     verticalMirror(ranTime,hueIncrement);
     break;
     case 4:
     digitalWrite(11, HIGH);
     quadrantMirror(ranTime,hueIncrement);
     break;
     case 5:
     digitalWrite(11, HIGH);
     vertical(ranTime,hueIncrement);
     break;
     case 6:
     digitalWrite(11, HIGH);
     triangleTopMirror(ranTime,hueIncrement);
     break;
     case 7:
     digitalWrite(11, HIGH);
     triangleBottomMirror(ranTime,hueIncrement);
     break;
     case 8:
     digitalWrite(11, HIGH);
     quadrantBottomMirror(ranTime*2,hueIncrement);
     break;
     case 9:
     digitalWrite(11, HIGH);
     quadrantTopMirror(ranTime,hueIncrement);
     break;
     case 10:
     digitalWrite(11, HIGH);
     quadrantMirror(ranTime,hueIncrement);
     break;
     case 11:
     digitalWrite(11, HIGH);
     FastLED.clear(true);
     CircleSpectrum(ranTime+500);
     break;
     case 12:
     digitalWrite(11, HIGH);
     FastLED.clear(true);
     CircleSpectrum(ranTime+500);
     break;
     case 13:
     digitalWrite(11, HIGH);
     FastLED.clear(true);
     Spectrum32(ranTime+500);
     break;
     case 14:
     digitalWrite(11, HIGH);
     FastLED.clear(true);
     Spectrum32(ranTime+500);
     break;
     case 15:
     digitalWrite(11, HIGH);
     FastLED.clear(true);
     pacman();
     break;
     case 16:
     digitalWrite(11, HIGH);
     FastLED.clear(true);
     pacman();
     break;
     default:
     digitalWrite(11, LOW);
     digitalWrite(13, HIGH);
     delay(8000);
     digitalWrite(11, HIGH);
     digitalWrite(13, LOW);
     break;
  }
}
//***************************************************************************************************
//All of the functions for Music Sim

void diagonal(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int x=0; x<(leds.Width()+leds.Height()); ++x){
        leds.DrawLine(x - leds.Height(), leds.Height() - 1, x, 0, CHSV(h, 255, 255));
        h+=16;
      }
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void horizontalMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int x=0; x<(leds.Width()+leds.Height()); ++x){
        leds.DrawLine(x - leds.Height(), leds.Height() - 1, x, 0, CHSV(h, 255, 255));
        h+=16;
      }
  leds.HorizontalMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void verticalMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int x=0; x<(leds.Width()+leds.Height()); ++x){
        leds.DrawLine(x - leds.Height(), leds.Height() - 1, x, 0, CHSV(h, 255, 255));
        h+=16;
      }
  leds.VerticalMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void quadrantMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int x=0; x<(leds.Width()+leds.Height()); ++x){
        leds.DrawLine(x - leds.Height(), leds.Height() - 1, x, 0, CHSV(h, 255, 255));
        h+=16;
      }
  leds.QuadrantMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void quadrantRotateMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int x=0; x<(leds.Width()+leds.Height()); ++x){
        leds.DrawLine(x - leds.Height(), leds.Height() - 1, x, 0, CHSV(h, 255, 255));
        h+=16;
      }
  leds.QuadrantRotateMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void vertical(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int y=0; y<leds.Height(); ++y){
      leds.DrawLine(0, y, leds.Width() - 1, y, CHSV(h, 255, 255));
      h+=16;
    }
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void triangleTopMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int y=0; y<leds.Height(); ++y){
      leds.DrawLine(0, y, leds.Width() - 1, y, CHSV(h, 255, 255));
      h+=16;
    }
  leds.TriangleTopMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void triangleBottomMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int y=0; y<leds.Height(); ++y){
      leds.DrawLine(0, y, leds.Width() - 1, y, CHSV(h, 255, 255));
      h+=16;
    }
  leds.TriangleBottomMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void quadrantBottomMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int y=0; y<leds.Height(); ++y){
      leds.DrawLine(0, y, leds.Width() - 1, y, CHSV(h, 255, 255));
      h+=16;
    }
  leds.QuadrantBottomTriangleMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void quadrantTopMirror(int runTime, int colorSpeed){
  double h;  
  while (1){ 
  for (int y=0; y<leds.Height(); ++y){
      leds.DrawLine(0, y, leds.Width() - 1, y, CHSV(h, 255, 255));
      h+=16;
    }
  leds.QuadrantTopTriangleMirror();
  FastLED.show();
  hue+= colorSpeed;
  if (hue >= 255){
  hue = 0;
  }
  runTime--;
  h = hue;
  
  if (runTime == 0){
    break;
  }
  readBrightness();
}
}

void sunrise(int runTime, int colorSpeed){
  while(1){
  for(int i = 0; i<17;i++){
  leds.DrawRectangle(32,16,i,i,CHSV(color, 255, 255));
  color = color + 15;
  }
  hue+= colorSpeed;
  Serial.println(colorSpeed);
  color = hue;
  leds.HorizontalMirror();
  FastLED.show();
  runTime--;
  if (runTime == 0){
    break;
  }
  readBrightness();
  }
  }




