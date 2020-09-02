#include <wiringPi.h>
int main()
{ wiringPiSetup();
  pinMode(6,OUTPUT);
  
  for(;;)
  { 
	digitalWrite(6,HIGH);
	delay(1000);
	digitalWrite(6,LOW);
	delay(1000); 
	  
	  }
	
	}
