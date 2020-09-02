/* 03. flow_LED.c
*
* 6개의 LED를 차례대로 켰다가 꺼 줍니다.
*
* 필요 소자
* LED : 6ea, 저항 220옴 6ea(색띠 : 빨빨검검갈)
* 
* LED : Wpi : 15 | BCM : #14
* LED : Wpi : 16 | BCM : #15
* LED : Wpi : 1 | BCM : #18
* LED : Wpi : 4 | BCM : #23
* LED : Wpi : 5 | BCM : #24
* LED : Wpi : 6 | BCM : #25
* 
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/

#include <wiringPi.h>

int main(void)
{  
  wiringPiSetup();

  pinMode(15,OUTPUT);       // Wpi : 15 | BCM : #14
  pinMode(16,OUTPUT);       // Wpi : 16 | BCM : #15
  pinMode(1,OUTPUT);        // Wpi : 1 | BCM : #18
  pinMode(4,OUTPUT);        // Wpi : 4 | BCM : #23
  pinMode(5,OUTPUT);        // Wpi : 5 | BCM : #24
  pinMode(6,OUTPUT);        // Wpi : 6 | BCM : #25

  while(1)
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

  return 0;
}
