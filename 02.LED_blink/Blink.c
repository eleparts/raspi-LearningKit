/* 02. Blink.c
*
* 1초 간격으로 LED를 점멸시켜 줍니다.
*
* 필요 소자
* LED : 1ea, 저항 220옴(색띠 : 빨빨검검갈)
* 
* LED : Wpi : 6 | BCM : #25 
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/

#include <wiringPi.h>

#define LED 6         // Wpi : 6 | BCM : #25

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
