//classGpio.cpp

#include "classGpio.h"

/* define the bits in the alternate function registers
 */
#define AF0   (0x00u)
#define AF1   (0x01u)
#define AF2   (0x02u)
#define AF3   (0x03u)
#define AF4   (0x04u)
#define AF5   (0x05u)
#define AF6   (0x06u)
#define AF7   (0x07u)
#define AF8   (0x08u)
#define AF9   (0x09u)
#define AF10  (0x0Au)
#define AF11  (0x0Bu)
#define AF12  (0x0Cu)
#define AF13  (0x0Du)
#define AF14  (0x0Eu)
#define AF15  (0x0Fu)

#define AF_PIN0 		(0)
#define AF_PIN1 		(4)
#define AF_PIN2 		(8)
#define AF_PIN3 		(12)
#define AF_PIN4 		(16)
#define AF_PIN5 		(20)
#define AF_PIN6 		(24)
#define AF_PIN7 		(28)
#define AF_PIN8 		(0)
#define AF_PIN9 		(4)
#define AF_PIN10 		(8)
#define AF_PIN11 		(12)
#define AF_PIN12 		(16)
#define AF_PIN13 		(20)
#define AF_PIN14 		(24)
#define AF_PIN15 		(28)

gpio::gpio(GPIO_PORT port, uint8_t pinNo, PIN_MODE mode)
{
  initialisePin(port, pinNo, mode);
};
	
gpio::gpio(ALTERNATE_FUNCTION altFunction)
{
  switch(altFunction)
  {
    case USART6_C6_TX:
      initialisePin(PORT_C,6,ALTERNATE);
      port->AFR[0] &= ~(0xFu << AF_PIN6);
      port->AFR[0] |= (AF8<<AF_PIN6);
    break;
    case USART6_C7_RX:
      initialisePin(PORT_C,7,ALTERNATE);
      port->AFR[0] &= ~(0xFu << AF_PIN7);
      port->AFR[0] |= (AF8<<AF_PIN7);
    break;
    case USART1_B6_TX:
      initialisePin(PORT_B,6,ALTERNATE);
      port->AFR[0] &= ~(0xFu << AF_PIN6);
      port->AFR[0] |= (AF7<<AF_PIN6);
    break;
    case USART1_B7_RX:
      initialisePin(PORT_B,7,ALTERNATE);
      port->AFR[0] &= ~(0xFu << AF_PIN7);
      port->AFR[0] |= (AF7<<AF_PIN7);
    break;

    default:
    break;
  }
};

void gpio::set()
{
  port->BSRRL = pinMask;
};
void gpio::clear()
{
  port->BSRRH = pinMask;
};

	//--------------------------------------------------------
	// set pin output type 
void gpio::setPinOutputType(PIN_OUTPUT_TYPE type)
{
  port->OTYPER &= ~(1<<pin);
  port->OTYPER |= (type<<pin);
}
	// set pin pull up or pull down
void gpio::setPinWeighting(PIN_WEIGHTING weighting)
{
  port->PUPDR &= ~(2<<(pin<<1));
  port->PUPDR |= (weighting<<(pin<<1));
}
void gpio::toggle()
{
  port->ODR ^= pinMask;
}
// read the value of the pin.
uint8_t gpio::read()
{
  return ((port->IDR & pinMask)>>pin);
}

void gpio::initialisePin(GPIO_PORT portName, uint8_t pinNo, PIN_MODE mode)
{
  setPort(portName);
  pinMask = (1<<pinNo);
  pin = pinNo;
  port->MODER &= ~(3<<(pin<<1));
  port->MODER |= (mode<<(pin<<1));	
}	

void gpio::setPort(GPIO_PORT portName)
{
  switch(portName)
  {
    case PORT_A:
      port = (GPIO_TypeDef*)GPIOA_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_AEN);
      break;
    case PORT_B:
      port = (GPIO_TypeDef*)GPIOB_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_BEN);
      break;
    case PORT_C:
      port = (GPIO_TypeDef*)GPIOC_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_CEN);
      break;
    case PORT_D:
      port = (GPIO_TypeDef*)GPIOD_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_DEN);
      break;
    case PORT_E:
      port = (GPIO_TypeDef*)GPIOE_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_EEN);
      break;
    case PORT_F:
      port = (GPIO_TypeDef*)GPIOF_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_FEN);
      break;
    case PORT_G:
      port = (GPIO_TypeDef*)GPIOG_BASE;
      RCC->AHB1ENR  |= (1UL <<  GPIO_GEN);
      break;

    case PORT_UNDEFINED:
    default:
      port = 0;
      break;
  }
}

