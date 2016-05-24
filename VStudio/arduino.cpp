#define ARDUINO2_MAIN

#include <Windows.h>
#include <string>
#include <time.h>

#include "arduino.h"
#include "Serial.hpp"
#include "DIO2.h"

//////////////////////////////////////////
// Arduino

int VC_pins[100];

void pinSetup()
{
	for (int i = 0; i < 100; i++)
		VC_pins[i] = -1;
}

void pinMode(int inPin, int inType)
{
	switch (inType)
	{
	case INPUT:
		VC_pins[inPin] = 0;
		break;
	case INPUT_PULLUP:
		VC_pins[inPin] = 1024;
		break;
	case OUTPUT:
		VC_pins[inPin] = 0;
		break;
	}
}

void printPins()
{
	char pins[100];
	int start = 0;

	for (int i = 0; i < 100; i++)
	{
		if (VC_pins[i] != -1)
		{
			start = i;
			break;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		switch (VC_pins[i])
		{
		case -1: // not affected
			if (i < start)
				pins[i] = 32;
			else
				pins[i] = 0;
			break;

		case 0: // light off
			pins[i] = '.';
			break;

		case 1:	// Light on
			pins[i] = 'O';
			break;

		default:
			// Analog value '1' to '9' !
			pins[i] = '0' + (VC_pins[i]/255.0) * 10;
			break;
		}
	}
	printf(pins);
	printf("\n");
}

void digitalWrite(int inPin, int inValue)
{
	if (inValue > 0 != VC_pins[inPin])
	{
		VC_pins[inPin] = inValue > 0;
		printPins();
	}
}

int digitalRead(int inPin)
{
	return VC_pins[inPin];
}

void analogWrite(int inPin, int inValue)
{
	if (inValue != VC_pins[inPin])
	{
		VC_pins[inPin] = inValue;
		printPins();
	}
}

int analogRead(int inPin)
{
	return VC_pins[inPin];
}

unsigned long millis()
{
	time_t t;
	time(&t);
	t = t % 1000;
	return (unsigned long)t*1000;
}

unsigned long micros()
{
	time_t t;
	time(&t);
	t = t % 1000;
	return (unsigned long)t*1000000;
}

void delay(int millis)
{
	Sleep(millis);
}

void interrupts()
{}

void noInterrupts()
{}

void attachInterrupt(uint8_t, void(*)(void), int mode)
{}

void detachInterrupt(uint8_t)
{}

uint8_t digitalPinToInterrupt(uint8_t)
{
	return 0;
}

uint16_t makeWord(uint16_t w)
{
	return w;
}

uint16_t makeWord(byte h, byte l)
{
	return (h << (uint16_t)8) + l;
}


//////////////////////////////////////////
// Memory

int freeMemory()
{
	return 20000;
}

//////////////////////////////////////////
// Serial

SerialClass SerialClass::SerialInstance;

std::string memo;

void SerialClass::print(const char *line)
{
	memo.append(line);
}

void SerialClass::println(const char *line)
{
	memo.append(line);
	printf(memo.c_str());
	printf("\n");
	memo.clear();
}

void SerialClass::print(int value, int i)
{
	memo.append(std::to_string(value));
}

void SerialClass::println(int value, int i)
{
	memo.append(std::to_string(value));
	printf(memo.c_str());
	printf("\n");
	memo.clear();
}

//////////////////////////////////////////
// Arduino 2

int GPIO_to_Arduino_pin(GPIO_pin_t inPin)
{
	int i;
	for (i = 0; i < GPIO_PINS_NUMBER; i++)
	{
		if (inPin == gpio_pins_progmem[i])
			return i;
	}

	return -1;
}

GPIO_pin_t Arduino_to_GPIO_pin(int inPin)
{
	return gpio_pins_progmem[inPin];
}

int map(int, int, int, int, int)
{
	return 0;
}

byte pgm_read_byte(const byte *str)
{
	return (byte)*str;
}
