#include <wiringPi.h>
#include <wiringShift.h>
#define data  4 
#define clock  5
#define latch  6

	void updateLEDs(int value)
	
	{
		digitalWrite(latch,LOW);
		shiftOut(data,clock,MSBFIRST,~value);
		digitalWrite(latch,HIGH);
		
		}
	

 
int main()
{
	wiringPiSetup();
	pinMode(data,OUTPUT);
	pinMode(clock,OUTPUT);
	pinMode(latch,OUTPUT);
	int i;
	
	for(;;)
	{
		for( i=0;i<256;i++)
		{
			updateLEDs(i);
			delay(500);
			
			}
		
		}
	

	
	
	}
