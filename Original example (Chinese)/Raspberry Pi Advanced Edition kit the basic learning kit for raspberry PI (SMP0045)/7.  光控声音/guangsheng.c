#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define	LED		  15
#define Q2W_ABASE       120

  
void  voice_freq (int del)
  {
	
	digitalWrite(15,HIGH);
	delay(del);
	digitalWrite(15,LOW);
	delay(del);
	
   }    

int main()
{
    
    int value;
    //int del;
    //int val=100;
    wiringPiSetup()	;
    pcf8591Setup(Q2W_ABASE,0x48);
    pinMode(15,OUTPUT);
    digitalWrite(15,LOW);
    

    
    for(;;)
    {
		value = analogRead (Q2W_ABASE + 0);
		if (value<80)
		voice_freq(value);   
		
		
		}
    
    }
