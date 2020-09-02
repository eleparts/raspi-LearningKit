#include <wiringPi.h>
#include <softPwm.h>      // wiringPi - Software PWM Library
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{    
   int bright;
   wiringPiSetup();
   softPwmCreate(6, 0, 100);


  while(1)
  {
    for (bright = 0 ; bright < 100 ; ++bright)
    {
      softPwmWrite(6, bright);
      delay(10);
    }

    for (bright = 100 ; bright >= 0 ; --bright)
    {
      softPwmWrite(6, bright);
      delay(10);
    }
  }
  return 0;
}

