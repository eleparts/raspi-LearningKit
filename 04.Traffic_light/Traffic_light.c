/* 04. Traffic_light.c
*
* 3가지 색상의 LED를 신호등과 동일하게 켜 줍니다.
*
* 필요 소자
* LED : 3ea (Red, Yellow, Blue 각 1ea) , 저항 220옴 3ea(색띠 : 빨빨검검갈)
* 
* Red LED    : Wpi : 15 | BCM : #14
* Yellow LED : Wpi : 16 | BCM : #15
* Bule LED   : Wpi : 1 | BCM : #18  - Green 색상이 없어 bule 로 대체
* 
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 투명한 LED 색상은 3.3V 핀을 이용해 쉽게 확인할 수 있습니다. (항상 저항을 같이 연결해 주어야 합니다.)
*/

#include <wiringPi.h>

#define redled     15     // Wpi : 15 | BCM : #14
#define yellowled  16     // Wpi : 16 | BCM : #15
#define buleled     1     // Wpi : 1 | BCM : #18


int main(void)
{
    wiringPiSetup();

    pinMode(buleled,OUTPUT);
    pinMode(yellowled,OUTPUT);
    pinMode(redled,OUTPUT);

    digitalWrite(buleled,LOW);
    digitalWrite(yellowled,LOW);
    digitalWrite(redled,LOW);
    
    while(1)
    {
        digitalWrite(buleled,HIGH);
        delay(5000);
        digitalWrite(buleled,LOW);

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
