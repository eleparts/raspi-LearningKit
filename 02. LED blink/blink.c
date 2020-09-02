#include <wiringPi.h>

#define LED 6

int main(void)
{ 

  wiringPiSetup();
  
  pinMode(LED,OUTPUT);

  while(1)
  { 
   
    digitalWrite(LED,HIGH);
    delay(1000);
   
    digitalWrite(LED,LOW);
    delay(1000); 

  }

  return 0;
}
