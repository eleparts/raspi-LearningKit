#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>
 
 
int main()
{
	int value;
	int dat;
	wiringPiSetup();
	pcf8591Setup(120 , 0x48);
	for(;;)
	{
		value=analogRead(120+0);
		
		dat=(125*value*4)>>8;
		printf("dat=%d\n",dat);
		delay(100);
		
		
		}
	
	
	return 0;
	}
