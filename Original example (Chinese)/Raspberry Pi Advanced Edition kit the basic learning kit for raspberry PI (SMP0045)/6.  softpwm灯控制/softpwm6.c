#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main()
{    
	 int bright;
	 wiringPiSetup () ;
	 softPwmCreate (6, 0, 100) ;


	for (;;)
  {
    for (bright = 0 ; bright < 100 ; ++bright)
    {
      softPwmWrite (6, bright) ;
      delay (10) ;
    }

    for (bright = 100 ; bright >= 0 ; --bright)
    {
      softPwmWrite (6, bright) ;
      delay (10) ;
    }
  }  
	
	}

