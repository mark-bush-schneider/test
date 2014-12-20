//class gpio
#include "stm32f4xx.h"
//-------------------------------------------------------
// class to encapsulate a GPIO pin.
// TODO add ability to set pull up pull downs, inputs
// and outputs etc
//-------------------------------------------------------

#ifndef CLASS_GPIO_H
#define CLASS_GPIO_H

typedef enum
{
	PUSH_PULL = 0x00,
	OPEN_COLLECTOR = 0x01
}PIN_OUTPUT_TYPE;

typedef enum
{
	NONE = 0x00,
	PULL_UP = 0x01,
	PULL_DOWN = 0x02,
}PIN_WEIGHTING;

typedef enum
{
	INPUT = 0,
	OUTPUT = 1,
	ALTERNATE = 2,
	ANALOGUE = 3
}PIN_MODE;

typedef enum 
{
	PORT_UNDEFINED,
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F,
	PORT_G

}GPIO_PORT;

typedef enum
{
	/* USART6 (AF8)*/
	
	USART6_C6_TX,	
	USART6_C7_RX,	
	USART6_C8_CK,  
	USART6_G7_CK, 	
	USART6_G8_RTS, 
	USART6_G9_RX, 	
	USART6_G12_RTS,
	USART6_G13_CTS,
	USART6_G14_TX, 
	USART6_G15_CTS,
	
 	/*USART1 */
	USART1_B6_TX,	 	
	USART1_B7_RX,	 
	USART1_A9_TX,	 	
	USART1_A10_RX,	 
	USART1_A8_CK,  	
	USART1_A12_RTS, 
	USART1_A11_CTS, 
 	
 	/*USART2 */
 	USART2_A9_TX,	
 	USART2_A10_RX,
 	USART2_A2_TX,	
 	USART2_A3_RX,	
 	USART2_A4_CK, 
 	USART2_A1_RTS,
 	USART2_A0_CTS
 	
}ALTERNATE_FUNCTION;

#define GPIO_AEN (0)
#define GPIO_BEN (1)
#define GPIO_CEN (2)
#define GPIO_DEN (3)
#define GPIO_EEN (4)
#define GPIO_FEN (5)
#define GPIO_GEN (6)
/* the gpio class implements a single pin.
 * a pin can in instatiated in 1 of 2 ways with 2 seperate constructers. 
 *  1. as an input/output
 *  2. as its alternate function
 */
class gpio
{
  public:
    gpio(GPIO_PORT port, uint8_t pinNo, PIN_MODE mode);
    gpio(ALTERNATE_FUNCTION altFunction);
    ~gpio(){};
    void set();
    void clear();
    void toggle();
    // set pin output type 
    void setPinOutputType(PIN_OUTPUT_TYPE type);
    // set pin pull up or pull down
    void setPinWeighting(PIN_WEIGHTING weighting);
    // read the value of the pin.
    uint8_t read();
	private:
    void initialisePin(GPIO_PORT portName, uint8_t pinNo, PIN_MODE mode);
    void setPort(GPIO_PORT portName);
    GPIO_TypeDef *port;
    uint32_t pinMask;
    uint32_t pin;
};




#endif
