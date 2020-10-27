int cursorPos = leds.width();

void testTextOld(int dur, int cur, int yPos, int speed){

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

void testText(){

	int cursorPos = 0;

	leds.fillScreen(0);
	leds.setCursor(cursorPos, 5);
	leds.print("Jordan");
	FastLED.show();
	delay(500);

	while (cursorPos > -5){
		leds.fillScreen(0);
		leds.setCursor(cursorPos, 5);
		leds.print("Jordan");
		FastLED.show();
		delay(100);
		cursorPos--;
	}
	delay (500);

	leds.fillScreen(0);
	leds.setCursor(0, 0);
	leds.print("Pull");
	leds.setCursor(10, 9);
	leds.print("Me");
	FastLED.show();
	delay(500);


	cursorPos = 2;
	leds.fillScreen(0);
	leds.setCursor(5, 0);
	leds.print("A");
	leds.setCursor(cursorPos, 9);
	leds.print("Mother");
	FastLED.show();
	delay(200);

	while (cursorPos > -5){
		leds.fillScreen(0);
		leds.setCursor(5, 0);
		leds.print("A");
		leds.setCursor(cursorPos, 9);
		leds.print("Mother");
		FastLED.show();
		delay(50);
		cursorPos--;
	}

	delay(200);

	leds.fillScreen(0);
	leds.setCursor(0, 0);
	leds.print("Fucking");
	// leds.setCursor(6, 9);
	// leds.print("Grav");
	FastLED.show();
	delay(200);

	cursorPos = 0;
	while (cursorPos > -10){
		cursorPos--;
		leds.fillScreen(0);
		leds.setCursor(cursorPos, 0);
		leds.print("Fucking");
		// leds.setCursor(6, 9);
		// leds.print("Grav");
		FastLED.show();
		delay(50);
		
	}

	delay(200);

	leds.fillScreen(0);
	leds.setCursor(cursorPos, 0);
	leds.print("Fucking");
	leds.setTextColor(CHSV(0, 255, brightness));
	leds.setCursor(6, 9);
	leds.print("Grav");
	FastLED.show();
	delay(750);

	leds.setTextColor(colors[0]);
	leds.fillScreen(0);
	leds.setCursor(0, 6);
	leds.print("Please");	
	FastLED.show();
	delay(200);

	cursorPos = 0;
	while (cursorPos > -5){
		leds.fillScreen(0);
		leds.setCursor(cursorPos, 6);
		leds.print("Please");
		FastLED.show();
		delay(50);
		cursorPos--;
	}

	delay(2000);



}