#include <wiringPi.h>

int main()
{
	wiringPiSetup();
	pinMode(6,OUTPUT);
	int i;
	for(;;)
	{
		
		for(i=0;i<50;i++)
		{
		digitalWrite(6,HIGH);
		delay(1);
		digitalWrite(6,LOW);
		delay(17);
		}
		
		delay(100);
		
		for(i=0;i<50;i++)
		{
		digitalWrite(6,HIGH);
		delay(2);
		digitalWrite(6,LOW);
		delay(16);
		}
		
		
		
		
		
		}
	
	
	return 0;
	
	
	
	}
