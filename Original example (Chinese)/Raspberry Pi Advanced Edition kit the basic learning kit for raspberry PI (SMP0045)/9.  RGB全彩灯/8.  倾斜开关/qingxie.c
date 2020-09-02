#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define	LED		  6
#define Q2W_ABASE       120

int main (void)
{
  int value ;

// Enable the on-goard GPIO

  wiringPiSetup () ;

// Add in the pcf8591 on the q2w board

  pcf8591Setup (Q2W_ABASE, 0x48) ;

  printf ("Raspberry Pi - Quick2Wire Analog Test\n") ;

// Setup the LED

  //pinMode  (LED, PWM_OUTPUT) ;
  //pwmWrite (LED, 0) ;
    pinMode  (LED, OUTPUT) ;
    digitalWrite (LED, LOW) ;
    
  for (;;)
  {
    value = analogRead  (Q2W_ABASE + 0) ;
    //pwmWrite (LED, value * 4) ;
    printf("value=%d\n",value);
    if (value>250)
    {digitalWrite(LED,HIGH);}
    else
    {digitalWrite(LED,LOW);}
    delay (100) ;
  }

  return 0 ;
}
