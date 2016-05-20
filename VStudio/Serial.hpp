//-------------------------------------------------------------------
#ifndef __serial_H__
#define __serial_H__
//-------------------------------------------------------------------

#define HardwareSerial		SerialClass
#define Serial		SerialClass::SerialInstance
#define Serial1		SerialClass::SerialInstance
#define Serial2		SerialClass::SerialInstance
#define Serial3		SerialClass::SerialInstance

class SerialClass
{
public:
	int available() { return 0; }
	void begin(int) {}
	char read() { return '0'; }
	void print(const char *line);
	void println(const char *line);
	void print(int value, int i = 0);
	void println(int value, int i = 0);

	static SerialClass SerialInstance;
};

//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------