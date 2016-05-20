//-------------------------------------------------------------------
#ifndef __arduino_H__
#define __arduino_H__
//-------------------------------------------------------------------

#define uint8_t		unsigned __int8
#define uint16_t	unsigned __int16
#define boolean		bool
#define byte		unsigned char

#define HIGH	1
#define LOW		0
#define INPUT	1
#define INPUT_PULLUP	3
#define OUTPUT	2
#define DEC		1
#define BIN		2
#define HEX		3
#define NULL	0
#define PROGMEM

#define A0	100
#define A1	101
#define A2	102
#define A3	103
#define A4	104
#define A5	105
#define A6	106
#define A7	107

#define NUM_DIGITAL_PINS            70
#define NUM_ANALOG_INPUTS           16

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define LED_BUILTIN	13

#define F(string)	string
#define __FlashStringHelper	char
byte pgm_read_byte(const byte *);

void pinSetup();
void pinMode(int, int);
void digitalWrite(int, int);
int digitalRead(int);
void analogWrite(int, int);
int analogRead(int);
unsigned long millis();
unsigned long micros();
void delay(int);

int map(int, int, int, int, int);

void noInterrupts();
void interrupts();
void attachInterrupt(uint8_t, void(*)(void), int mode);
void detachInterrupt(uint8_t);
uint8_t digitalPinToInterrupt(uint8_t);

int freeMemory();

//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
