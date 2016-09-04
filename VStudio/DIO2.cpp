#define ARDUINO2_MAIN

#include "DIO2.hpp"
#include "DIO2.h"

void DIO2::DioClass::_pinMode2(uint8_t pin, uint8_t mode)
{
	ArduiEmulator::Arduino::_pinMode(pin, mode);
}

void DIO2::DioClass::_digitalWrite2(uint8_t pin, uint8_t val)
{
	ArduiEmulator::Arduino::_digitalWrite(pin, val);
}

uint8_t DIO2::DioClass::_digitalRead2(uint8_t pin)
{
	return ArduiEmulator::Arduino::_digitalRead(pin);
}

void DIO2::DioClass::_pinMode2f(GPIO_pin_t pin, uint8_t mode)
{
	ArduiEmulator::Arduino::_pinMode(_GPIO_to_Arduino_pin(pin), mode);
}

uint8_t DIO2::DioClass::_digitalRead2f(GPIO_pin_t pin)
{
	return ArduiEmulator::Arduino::_digitalRead(_GPIO_to_Arduino_pin(pin));
}

void DIO2::DioClass::_digitalWrite2f(GPIO_pin_t pin, uint8_t value)
{
	ArduiEmulator::Arduino::_digitalWrite(_GPIO_to_Arduino_pin(pin), value);
}

int DIO2::DioClass::_GPIO_to_Arduino_pin(GPIO_pin_t inPin)
{
	int i;
	for (i = 0; i < GPIO_PINS_NUMBER; i++)
	{
		if (inPin == gpio_pins_progmem[i])
			return i;
	}

	return -1;
}

GPIO_pin_t DIO2::DioClass::_Arduino_to_GPIO_pin(int inPin)
{
	return gpio_pins_progmem[inPin];
}
