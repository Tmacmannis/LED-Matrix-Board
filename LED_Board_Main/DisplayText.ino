int cursorPos = leds.width();

void testText(int dur, int cur, int yPos, int speed){

	while(true){
		
		int textLength = (textToPrint.length())*(-6);

		EVERY_N_MILLISECONDS(speed) {
			leds.fillScreen(0);
			leds.setCursor(cursorPos, yPos);
			leds.print(textToPrint);
			if(--cursorPos < textLength) {
				cursorPos = leds.width();
				if(checkLeaveText(dur, cur)){
					break;
				}
			}
			FastLED.show();
		}
		if(checkForUpdates()){
			matrix->setBrightness(brightness);
		}
	}
	
}

bool checkLeaveText(int dur, int cur){
	if(millis() - cur > dur){
		return true;
	}
}