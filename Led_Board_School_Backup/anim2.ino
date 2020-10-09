void runAnim2(int runTime){
  int num = random(1,9);
  hueIncrement = random(1,2);
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
     default:
     digitalWrite(11, HIGH);
     quadrantMirror(ranTime,hueIncrement);
     break;
  }
}
