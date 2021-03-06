/*
Speed test of fast digital I/O for Arduino Mega

Un-comment the version ï¿½f digitalWrite you wish to test in the
for loop below.
The program will print time in micro seconds it takes to perform 100-times
digitalWrite().

24.2.2014
*/

// Set to 1 to have fast but (maybe) bigger program (inline digital I/O functions)
// set 0 to have slower and (sometimes) smaller program 
#define	GPIO2_PREFER_SPEED	1
#include <DIO2.h>  // include the fast I/O 2 functions

uint8_t pin = 7;
uint8_t arduino_led_pin = 13;
GPIO_pin_t my_pin = DP7;
GPIO_pin_t led_pin = DP13;

void setup() {
  // put your setup code here, to run once:
  pinMode2(arduino_led_pin, OUTPUT);
  pinMode2(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
      // put your main code here, to run repeatedly: 
      uint32_t start, end;
      uint8_t cnt;

 	// Blink the LED to see if the program is running
	digitalWrite2(13, HIGH );		// version with pin number conversion
	delay(1000);
	digitalWrite2(13, LOW );
	delay(1000);

	Serial.println("testing...");
	start = micros();
	for ( cnt = 100; cnt > 0; cnt-- )
	{
          // Standard Arduino function
          //digitalWrite(pin, HIGH);    // 6.8 us; 3.40 us with timer-pin check disabled 
          
          // New functions
	      // Arduino compatible version using pin as a simple integer
	      //digitalWrite2(pin, HIGH);		// 2.20 us  (3.15 us with GPIO2_PREFER_SPEED = 0)
	      //digitalWrite2(7, HIGH);		// 1.00 us  
          
          // Fast version using pin code as a variable
	         digitalWrite2f(my_pin, HIGH);	// 1.40 us (2.30 us with GPIO2_PREFER_SPEED = 0)
	      //digitalWrite2f(DP7, HIGH);        // 0.75 us 
	}
	end = micros();

	Serial.print("100 digitalWrites took (microseconds): ");
	Serial.print(end - start);
	delay(5000);
}

