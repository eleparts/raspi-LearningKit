#include <wiringPi.h>

#define greenled  15
#define yellowled 16
#define redled     1


int main(void)
{
  wiringPiSetup();

  pinMode(greenled,OUTPUT);
  pinMode(yellowled,OUTPUT);
  pinMode(redled,OUTPUT);

  digitalWrite(greenled,LOW);
  digitalWrite(yellowled,LOW);
  digitalWrite(redled,LOW);
  
  while(1)
  {
    digitalWrite(greenled,HIGH);
    delay(5000);
    digitalWrite(greenled,LOW);

    for(int i=0;i<3;i++)
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

  return 0;
}
