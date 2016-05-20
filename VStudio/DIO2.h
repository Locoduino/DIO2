//-------------------------------------------------------------------
#ifndef ARDUINO2_H_
#define ARDUINO2_H_
//-------------------------------------------------------------------

#include "arduino.h"

#include "../board/mega/pins2_arduino.h"

static inline void pinMode2(uint8_t, uint8_t) {}
static inline void digitalWrite2(uint8_t, uint8_t) {}
static inline uint8_t digitalRead2(uint8_t) {return 0;}

static inline void pinMode2f(GPIO_pin_t pin, uint8_t mode) {}
static inline uint8_t digitalRead2f(GPIO_pin_t pin) { return 0;}
static inline void digitalWrite2f(GPIO_pin_t pin, uint8_t value) {}
int GPIO_to_Arduino_pin(GPIO_pin_t);
GPIO_pin_t Arduino_to_GPIO_pin(int);

//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
