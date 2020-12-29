/* 20. Joystick.c
* 
* 조이스틱 모듈의 아날로그 데이터 값을 PCF8591 ADC 모듈을 이용하여 라즈베리파이로 받아 줍니다.
*
* 필요 소자
* 조이스틱 모듈, PCF8591 모듈
* 
* > PCF8591 모듈 (0,1 채널을 사용하기 위해 점퍼를 제거해 주어야 합니다.)
* 모듈의 전원은 각각 3.3V, GND 연결, SDA, SCL 핀은 라즈베리파이의 동일한 SDA(#2), SCL(#3) 에 연결합니다.
* 
* > 조이스틱
* +, - 핀은 각각 3.3V, GND에 연결해 줍니다.
* X : PCF8591모듈의 AIN0 (ADC IN ch0)
* Y : PCF8591모듈의 AIN1 (ADC IN ch1)
* B :  Wpi : 7 | BCM : #4   (조이스틱)
* 
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ female to female 케이블이 제품 구성에 포함되지 않으므로 브레드보드를 경유하여 두 보드를 연결하거나, PCF8591모듈에 포함되어있는 F/F 케이블을 사용합니다.
*/

#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define Q2W_ABASE       120
#define	BUTTON          7     // #4
#define ADC_CH_0        0
#define ADC_CH_1        1

int main (void)
{
    int adcCh0 = 0, adcCh1 = 0, button = 0;

    wiringPiSetup();

    pcf8591Setup(Q2W_ABASE, 0x48);

    pinMode(BUTTON, INPUT);

    while(1)
    {
        adcCh0 = analogRead(Q2W_ABASE + ADC_CH_0);
        adcCh1 = analogRead(Q2W_ABASE + ADC_CH_1);
        button = digitalRead(BUTTON);

        printf("> JOY X : %d | Y : %d | BTN : %d \n", adcCh0, adcCh1, button);
        delay (100);
    }

    return 0;
}
