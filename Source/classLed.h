// ledClass
#include "stm32f4xx.h"
#include "classGpio.h"

//-------------------------------------------------------
// This module implements the 4 LED's on the
// ST32F4-descover board
//-------------------------------------------------------

class led : private gpio
{
	public:
	led(GPIO_PORT port, uint8_t pinNo) : gpio(port,pinNo,OUTPUT){};
    using gpio::toggle;
	void on()
	{
		gpio::set();
	}
	void off()
	{
		gpio::clear();
	}
};
//-------------------------------------------------------
//-------------------------------------------------------
class greenLed : public led
{
	public:
	greenLed() : led(PORT_D,12){};
	~greenLed(){};
};
//-------------------------------------------------------
//-------------------------------------------------------
class redLed : public led
{
	public:
	redLed() : led(PORT_D,14){};
	~redLed(){};
};
//-------------------------------------------------------
//-------------------------------------------------------
class blueLed : public led
{
	public:
	blueLed() : led(PORT_D,15){};
	~blueLed(){};
};
//-------------------------------------------------------
//-------------------------------------------------------
class orangeLed : public led
{
	public:
	orangeLed() : led(PORT_D,13){};
	~orangeLed(){};
};
