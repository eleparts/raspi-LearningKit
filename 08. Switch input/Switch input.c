#include <stdio.h>
#include <wiringPi.h>

#define	LED1     
#define	LED2     
#define	TACTSW   
#define	BALLSW   



int main (void)
{
  int value ;

  wiringPiSetup () ;

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
