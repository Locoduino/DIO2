//-------------------------------------------------------------------
#ifndef DIO2_H_
#define DIO2_H_
//-------------------------------------------------------------------

#include "arduino.h"

#include "../board/nano/pins2_arduino.h"

#define pinMode2(pin, mode)			ArduiEmulator::Arduino::_pinMode(DIO2::DioClass::_GPIO_to_Arduino_pin(pin), mode)
#define digitalWrite2(pin, val)		ArduiEmulator::Arduino::_digitalWrite(DIO2::DioClass::_GPIO_to_Arduino_pin(pin), val);
#define digitalRead2(pin)			ArduiEmulator::Arduino::_digitalRead(DIO2::DioClass::_GPIO_to_Arduino_pin(pin));

#define pinMode2f(pin, mode)		ArduiEmulator::Arduino::_pinMode(DIO2::DioClass::_GPIO_to_Arduino_pin(pin), mode);
#define digitalWrite2f(pin, value)	ArduiEmulator::Arduino::_digitalWrite(DIO2::DioClass::_GPIO_to_Arduino_pin(pin), value)
#define digitalRead2f(pin)			ArduiEmulator::Arduino::_digitalRead(DIO2::DioClass::_GPIO_to_Arduino_pin(pin));

#define GPIO_to_Arduino_pin(GPIO_PIN)		DIO2::DioClass::_GPIO_to_Arduino_pin(GPIO_PIN)
#define Arduino_to_GPIO_pin(PIN)			DIO2::DioClass::_Arduino_to_GPIO_pin(PIN)

//-------------------------------------------------------------------				
#endif
//-------------------------------------------------------------------
