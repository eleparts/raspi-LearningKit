/* 19. Servo.c
*
* PWM을 이용하여 서보모터를 제어해 줍니다.
*
* 필요 소자
* 서보모터 (SG-90)
* 
* 빨간색 : VCC (5V)
* 갈색   : GND (GND)
* 주황색 : Signal | Wpi : 7 | BCM : #4
* 
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 모터는 전류 소모가 크기 때문에 라즈베리파이의 전원을 같이 사용하기에는 적합하지 않습니다. (2개 이상 서보 연결 시 별도 전원 사용 권장)
*  서보모터에 부하가 클수록 전류 소모가 크기 때문에 너무 큰 부하가 걸리지 않도록 해 줍니다. 
*/
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h> 

#define SERVO_PIN   7   // BCM #4

int main(void)
{
    wiringPiSetup();

    softPwmCreate(SERVO_PIN, 0, 200);  // create a period 20 ms

    while(1)
    {   
        /* 180도 서보모터의 사용 가능 Duty 범위는 500us(5)~2400us(24) 입니다 */
        /* 참조 : https://blog.naver.com/elepartsblog/221061007108 */
        softPwmWrite(SERVO_PIN,15);   // 0 degree
        delay(500);

        softPwmWrite(SERVO_PIN,5);    // -90 degree
        delay(500);

        softPwmWrite(SERVO_PIN,15);   // 0 degree
        delay(500);

        softPwmWrite(SERVO_PIN,24);   // 90 degree
        delay(500);
            
    }   

    return 0;
}