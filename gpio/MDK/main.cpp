
#include <stdio.h>
#include <classLed.h>
#include <classPushButton.h>

main(int argc, char* argv[])
{
  // At this stage the system clock should have already been configured
  // at high speed.
  greenLed led;
  pushButton pb;

  // Infinite loop
  while (1)
    {
       // Add your code here.
      if(pb.isPressed())
      {
        led.on();
      }
      else
      {
        led.off();
      }

    }
}
