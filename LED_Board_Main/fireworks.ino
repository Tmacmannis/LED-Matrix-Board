int x = 6;
int y = 7;
int c = 60;
int z = 70;
int w = 20;

void showFireworks(int zero, int maxCount){
	while(zero < maxCount){
		checkForUpdates();

		FastLED.clear(true);

		x = random(5, 28);
		y = random(5, 10);
		c = random(0, 266);
		z = c + 20;
		w = random(15, 30);

		for( int i=15; i>y; i--) {
			FastLED.clear(true);
	    	leds.DrawLine(x, i, x, (i+1), CHSV(c, 255, brightness));
	    	FastLED.show();
	    	delay(20);
	    	leds.DrawLine(x, i, x, (i+1), CHSV(z, 255, brightness));
	    	FastLED.show();
	  	}

	  	leds.DrawCircle(x, y, 1, CHSV(c, 255, brightness)); 
	  	FastLED.show();
	  	delay(w*3);
	  	leds.DrawCircle(x, y, 1, CHSV(z, 255, brightness));
	  	FastLED.show();

	  	checkForUpdates();


	  	for ( int j=1;j<4; j++) {
		    leds.DrawLine(x, (y-5)-j, x, (y-4)-j, CHSV(c, 255, brightness));
		    leds.DrawLine(x, (y+2)+j, x, (y+3)+j, CHSV(c, 255, brightness));
		    leds.DrawLine((x-5)-j, y, (x-4)-j, y, CHSV(c, 255, brightness));
		    leds.DrawLine((x+2)+j, y, (x+3)+j, y, CHSV(c, 255, brightness));
		 
		    leds.DrawLine((x+1)+j, (y+1)+j, (x+3)+j, (y+3)+j, CHSV(z, 255, brightness));
		    leds.DrawLine((x-1)-j, (y+1)+j, (x-3)-j, (y+3)+j, CHSV(z, 255, brightness));
		    leds.DrawLine((x+1)+j, (y-1)-j, (x+3)+j, (y-3)-j, CHSV(z, 255, brightness));
		    leds.DrawLine((x-1)-j, (y-1)-j, (x-3)-j, (y-3)-j, CHSV(z, 255, brightness));
	     	FastLED.show();
		    delay(w*2);
		    checkForUpdates();
		     
		    leds.DrawLine(x, (y-5)-(j-1), x, (y-4)-(j-1), CHSV(z, 255, brightness));
		    leds.DrawLine(x, (y+2)+(j-1), x, (y+3)+(j-1), CHSV(z, 255, brightness));
		    leds.DrawLine((x-5)-(j-1), y, (x-4)-(j-1), y, CHSV(z, 255, brightness));
		    leds.DrawLine((x+2)+(j-1), y, (x+3)+(j-1), y, CHSV(z, 255, brightness));
		 
		    leds.DrawLine((x+1)+(j-1), (y+1)+(j-1), (x+3)+(j-1), (y+3)+(j-1), CHSV(z, 255, brightness));
		    leds.DrawLine((x-1)-(j-1), (y+1)+(j-1), (x-3)-(j-1), (y+3)+(j-1), CHSV(z, 255, brightness));
		    leds.DrawLine((x+1)+(j-1), (y-1)-(j-1), (x+3)+(j-1), (y-3)-(j-1), CHSV(z, 255, brightness));
		    leds.DrawLine((x-1)-(j-1), (y-1)-(j-1), (x-3)-(j-1), (y-3)-(j-1), CHSV(z, 255, brightness));
		    FastLED.show();
		    delay(w*2);
		 
		    leds.DrawLine(x, (y-5)-j, x, (y-4)-j, CHSV(z, 255, brightness));
		    leds.DrawLine(x, (y+2)+j, x, (y+3)+j, CHSV(z, 255, brightness));
		    leds.DrawLine((x-5)-j, y, (x-4)-j, y, CHSV(z, 255, brightness));
		    leds.DrawLine((x+2)+j, y, (x+3)+j, y, CHSV(z, 255, brightness));
		     
		 
		    leds.DrawLine((x+1)+j, (y+1)+j, (x+3)+j, (y+3)+j, CHSV(z, 255, brightness));
		    leds.DrawLine((x-1)-j, (y+1)+j, (x-3)-j, (y+3)+j, CHSV(z, 255, brightness));
		    leds.DrawLine((x+1)+j, (y-1)-j, (x+3)+j, (y-3)-j, CHSV(z, 255, brightness));
		    leds.DrawLine((x-1)-j, (y-1)-j, (x-3)-j, (y-3)-j, CHSV(z, 255, brightness));
		    FastLED.show();
		    delay(w*2);
		    FastLED.clear(true);
		    checkForUpdates();

	  	}

	  	delay(random(500, 1000));
  		zero++;
	}
}
	