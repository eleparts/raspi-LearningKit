#include <wiringPi.h>

int main()
{
	wiringPiSetup();
	int i=0;
	int greenled=15;
 	int yellowled=16;
	int redled=1;
	pinMode(greenled,OUTPUT);
	pinMode(yellowled,OUTPUT);
	pinMode(redled,OUTPUT);
	
	for(;;)
	{
		digitalWrite(greenled,HIGH);
		delay(5000);
		digitalWrite(greenled,LOW);
		for( i=0;i<3;i++)
		{
		digitalWrite(yellowled,HIGH);
		delay(500);
		digitalWrite(yellowled,LOW);
		delay(500);
		 }
		digitalWrite(redled,HIGH);
		delay(5000);
		digitalWrite(redled,LOW);
		//delay(500);
		
 	  
 	  
 	  }
	
	
	
	
	}
