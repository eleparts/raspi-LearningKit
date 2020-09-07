/* 09. RGB LED.c
*
* RGB LED 모듈에 내장된 LED 3종을 차례대로 ON/OFF해 줍니다.
*
* 필요 소자
* RGB LED 모듈
* 
* RGB LED
* V : VCC : 3.3V or 5V 
* R : Wpi : 0 | BCM : #17
* B : Wpi : 2 | BCM : #27
* G : Wpi : 3 | BCM : #22
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ VCC가 별도로 연결되고 GPIO는 GND 방향으로 연결되기 때문에 GPIO를 LOW로 설정해 줄 때 LED가 켜집니다.
*/
#include <stdio.h>
#include <wiringPi.h>

#define	LED_R   0  // #17
#define	LED_B   2  // #27
#define	LED_G   3  // #22

int main (void)
{
  wiringPiSetup();

  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_G, OUTPUT);

  digitalWrite(LED_R, 1);
  digitalWrite(LED_B, 1);
  digitalWrite(LED_G, 1);

  while(1)
  {
    digitalWrite(LED_R, 0); // 0 (LOW) : LED ON
    delay(1000);
    digitalWrite(LED_R, 1);
  
    digitalWrite(LED_B, 0);
    delay(1000);
    digitalWrite(LED_B, 1);

    digitalWrite(LED_G, 0);
    delay(1000);
    digitalWrite(LED_G, 1);
  }

  return 0;
}
