/* 06. Softpwm.c
*
* Software PWM 기능을 이용해 LED의 밝기를 조절해 줍니다.
*
* 필요 소자
* LED : 1ea, 저항 220옴 1ea(색띠 : 빨빨검검갈)
* 
* LED : Wpi : 6 | BCM : #25
* 
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/

#include <wiringPi.h>
#include <softPwm.h>      // wiringPi - Software PWM Library
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{    
    int bright;

    wiringPiSetup();

    softPwmCreate(6, 0, 100);           // 소프트웨어 PWM 설정

    while(1)                            // 무한반복 - PMW 밝기 제어 반복
    {
        for (bright = 0 ; bright < 100 ; ++bright)
        {
            softPwmWrite(6, bright);
            delay(10);
        }

        for (bright = 100 ; bright >= 0 ; --bright)
        {
            softPwmWrite(6, bright);
            delay(10);
        }
    }
    return 0;
}

