//-------------------------------------------------------------------
#ifndef __DIO2_HPP__
#define __DIO2_HPP__
//-------------------------------------------------------------------

#include "DIO2.h"

namespace DIO2
{
	public ref class DioClass
	{
	public:
		static void _pinMode2(uint8_t pin, uint8_t mode);
		static void _digitalWrite2(uint8_t pin, uint8_t val);
		static uint8_t _digitalRead2(uint8_t pin);

		static void _pinMode2f(GPIO_pin_t pin, uint8_t mode);
		static uint8_t _digitalRead2f(GPIO_pin_t pin);
		static void _digitalWrite2f(GPIO_pin_t pin, uint8_t value);

		static GPIO_pin_t _Arduino_to_GPIO_pin(int aa);
		static int _GPIO_to_Arduino_pin(GPIO_pin_t aa);
	};
};

//-------------------------------------------------------------------				
#endif
//-------------------------------------------------------------------
