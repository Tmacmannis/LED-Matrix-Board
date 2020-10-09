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

void showNewData() {
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

        Serial.print("got the num: ");
        Serial.println(num);
        newData = false;
    }
}
