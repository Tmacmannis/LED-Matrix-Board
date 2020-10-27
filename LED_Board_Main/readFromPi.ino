char inChar;

bool recvInProgress = false;
int receivedCount = 0;

char receivedChars[512];
boolean newData = false;

void readDataFromPI(){

	char startMarker = '<';
    char endMarker = '>';

	while (Serial.available() > 0 && newData == false) {
    	inChar = Serial.read();

		if (recvInProgress == true) {
			if (inChar != endMarker) {
                receivedChars[receivedCount] = inChar;
                receivedCount++;
            }
            else {
                receivedChars[receivedCount] = '\0'; // terminate the string
                recvInProgress = false;
                receivedCount = 0;
                newData = true;
            }
		} else if (inChar == startMarker) {
            recvInProgress = true;
            Serial.println("got it!");
        }
  	}
}

bool showNewData() {
    if (newData == true) {
        Serial.print("This just ins ... ");

        int num = (int) receivedChars[0];

        if(num == 0){
            Serial.println("got the zero");
            lastBrightness = brightness;
            brightness = 0;
        } 

        if(num == 1){
            Serial.println("got the one");
            brightness = lastBrightness;
        }

        if(num > 1 && num < 103){
            Serial.print("changing brightness to: ");
            Serial.println(num - 2);
            brightness = map((num -2),0,100, 0, 255);
        }

        if(num == 110){
            Serial.println((int) receivedChars[1]);
            String newText = "";
            for(int i = 2; i < ((int) receivedChars[1]) + 2; i++){
                // Serial.print(receivedChars[i]);
                newText = String(newText + receivedChars[i]);
            }
            Serial.println(newText);
        }

        switch(num){
            case 103:
                Serial.println("spectrum");
                currentProgram = 2;
                break;
            case 104:
                Serial.println("rainbow");
                currentProgram = 3;
                break;
            case 105:
                Serial.println("rain");
                currentProgram = 4;
                break;
            case 106:
                Serial.println("custom text");
                currentProgram = 5;
                break;
            case 107:
                Serial.println("jordan");
                currentProgram = 6;
                break;
            case 108:
                Serial.println("fireworks");
                currentProgram = 7;
                break; 
            case 109:
                Serial.println("random");
                currentProgram = 1;
                break;
        }

        Serial.print("got the num: ");
        Serial.println(num);
        Serial.println(">");
        newData = false;
        return true;
    }
}
