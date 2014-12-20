//push button class
#include "classGpio.h"

#ifndef CLASS_PUSH_BUTTON_H
#define CLASS_PUSH_BUTTON_H

typedef enum
{
	PRESSED,
	RELEASED
}BUTTON_STATE;


// the push button in connected to GPIO A0
class pushButton : gpio
{
	public:
	pushButton() : gpio(PORT_A,0,INPUT){};
	~pushButton(){};
	bool isPressed()
	{
		bool retValue = false;
		if(read() == 1)
		{
			retValue = true;
		}
		return retValue;
	}
	
};


#endif
