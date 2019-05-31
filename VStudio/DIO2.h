//-------------------------------------------------------------------
#ifndef DIO2_H_
#define DIO2_H_
//-------------------------------------------------------------------

#include "stdafx.h"

#include "Arduino.h"
//#include "ArduiEmulator.hpp"

#include "../board/mega/pins2_arduino.h"

extern void pinMode2(uint8_t pin, uint8_t mode);
extern void digitalWrite2(uint8_t pin, uint8_t val);
extern uint8_t digitalRead2(uint8_t pin);

extern void pinMode2f(GPIO_pin_t pin, uint8_t mode);
extern uint8_t digitalRead2f(GPIO_pin_t pin);
extern void digitalWrite2f(GPIO_pin_t pin, uint8_t value);

extern GPIO_pin_t Arduino_to_GPIO_pin(int aa);
extern int GPIO_to_Arduino_pin(GPIO_pin_t aa);

//-------------------------------------------------------------------				
#endif
//-------------------------------------------------------------------
