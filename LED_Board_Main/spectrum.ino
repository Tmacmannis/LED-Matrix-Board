uint8_t specHue = 0;


void spectrum(int dur, int cur){
	while(millis() - cur < dur){
		unsigned int x, freqBin;
		float level;
		EVERY_N_MILLISECONDS(100){
			checkForUpdates();
			specHue += 5;
		}

		if (fft.available()) {
			freqBin = 0;

			for (x=0; x < MATRIX_WIDTH; x++) {
	      // get the volume for each horizontal pixel position
				level = fft.read(freqBin, freqBin + frequencyBinsHorizontal[x] - 1);

	      // uncomment to see the spectrum in Arduino's Serial Monitor
	       // Serial.print(level);
	       // Serial.print("  ");

				for (int y = MATRIX_HEIGHT - 1; y >= 0; y--) {
	        // for each vertical pixel, check if above the threshold
	        // and turn the LED on or off
					if (level >= thresholdVertical[y]) {
						leds.drawPixel(x, y, CHSV(specHue, 255, brightness));
					} else {
						leds.drawPixel(x, y, CHSV(0, 0, 0));
					}
				}
				freqBin = freqBin + frequencyBinsHorizontal[x];
			}
			EVERY_N_MILLISECONDS(1000/30) {
				FastLED.show();
			}
			
	    // Serial.println();
		}
	}
	
}


void computeVerticalLevels() {
	unsigned int y;
	float n, logLevel, linearLevel;

	for (y=0; y < MATRIX_HEIGHT; y++) {
		n = (float)y / (float)(MATRIX_HEIGHT - 1);
		logLevel = pow10f(n * -1.0 * (dynamicRange / 20.0));
		linearLevel = 1.0 - n;
		linearLevel = linearLevel * linearBlend;
		logLevel = logLevel * (1.0 - linearBlend);
		thresholdVertical[y] = (logLevel + linearLevel) * maxLevel;
	}
}