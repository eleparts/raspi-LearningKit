/* 21. HC-SR04.c
*
* ultrasonic sensor(초음파 거리측정)의 예제로 초음파 센서와 물체의 거리를 터미널 창으로 실시간 출력해 줍니다.
* 
* 필요 소자 : HC-SR04(Ultrasonic) 센서
*
* > HC-SR04(Ultrasonic) 센서 
* VCC 핀  : 5V | GND 핀 : GND
* TRIG핀  : Wpi : 4 | BCM : #23
* ECHO핀  : Wpi : 5 | BCM : #24
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 초음파 센서는 센서에서 초음파를 방출, 다시 되돌아오는 시간을 측정합니다.
*   이를 이용해 앞에 있는 물체와의 거리를 계산, 측정할 수 있습니다.
*/

#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define TRIG 4  // Trig 핀 wiringPi 번호 정의
#define ECHO 5  // ECHO 핀 wiringPi 번호 정의


int main(void){

    int distance=0;
    int pulse=0;


    if(wiringPiSetup()==-1){
        return 1;
    }
    
    pinMode(TRIG,OUTPUT);
    pinMode(ECHO,INPUT);

    while(1){

        long travelTime=0;
        long startTime=0;

        digitalWrite(TRIG,LOW);
        usleep(2);

        digitalWrite(TRIG,HIGH);                  // 10us 초음파 방사
        usleep(10);
        digitalWrite(TRIG,LOW);

        while(digitalRead(ECHO) == LOW){          // 초음파 송신 시간
            startTime = micros();
        }

        while(digitalRead(ECHO) == HIGH){         // 초음파 수신 시간
            travelTime = micros() - startTime;      // 초음파 총 이동 시간 계산 
        }

        int distance = travelTime / 58;           // 초음파 속도 340m/s = 0.034cm/us, 1cm당 지연시간 약 29.41us * 2(왕복) = 58 
        printf("Distance: %dcm\r\n", distance);

        delay(100);
    }
}