#include <wiringPi.h>

int main()
{  
	 wiringPiSetup();
	 pinMode(15,OUTPUT);
	 pinMode(16,OUTPUT);
	 pinMode(1,OUTPUT);
	 pinMode(4,OUTPUT);
	 pinMode(5,OUTPUT);
	 pinMode(6,OUTPUT);
	 
	for(;;)
	{
		digitalWrite(15,HIGH);
		delay(500);
		digitalWrite(16,HIGH);
		delay(500);
		digitalWrite(1,HIGH);
		delay(500);
		digitalWrite(4,HIGH);
		delay(500);
		digitalWrite(5,HIGH);
		delay(500);
		digitalWrite(6,HIGH);
		delay(500);
		digitalWrite(6,LOW);
		delay(500);
		digitalWrite(5,LOW);
		delay(500);
		digitalWrite(4,LOW);
		delay(500);
		digitalWrite(1,LOW);
		delay(500);
		digitalWrite(16,LOW);
		delay(500);
		digitalWrite(15,LOW);
		delay(500);
		
		
		}
	
	
	
	
	
	
	
	
	}
