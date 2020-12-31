/* 09. Light detection.c
*
* CDS(LDR)의 빛 감지(저항 변화)값을 ADC 모듈(PCF8591)을 통해 받아 부저를 제어해 줍니다.
* 스마트폰의 카메라 플래시 등을 CDS에 비춰 주시면 동작합니다.
*
* 필요 소자
* PCF8591 모듈, 부저, CDS(LDR), 저항 1k옴 (갈검검갈갈) / 선택: 부저 대신 LED+저항 연결(소리 -> LED 점멸속도 변화).
* 
* > PCF8591 모듈 (0,1,3 채널 사용 시 사용 전 점퍼를 제거해 주어야 합니다. / 예제에서는 0번 채널 사용)
* 모듈의 전원은 각각 3.3V, GND 연결, SDA, SCL 핀은 라즈베리파이의 동일한 SDA(#2), SCL(#3) 에 연결합니다.
* > CDS(LDR) 
* [3.3V] - [1k 저항] - [CDS] - [GND] 순서로 연결한 뒤 저항과 CDS 부분에 점퍼를 연결, PCF8591 모듈의 AIN0으로 연결해 줍니다.
* > 부저 : Wpi : 15 | BCM : #14 (TXD) / 부저 대신 LED를 연결하셔도 됩니다. (부저 상단 (+) 극성 표시 참고)
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 라즈베리파이 설정에서 I2C를 Enable 해 주어야 PCF8591 모듈과 I2C 통신을 할 수 있습니다.
*/

#include <wiringPi.h>
#include <pcf8591.h>        // Need i2C Enable
#include <stdio.h>

#define	BUZZER       15
#define Q2W_ABASE   120
#define ADC_CH        0


void voice_freq(int del)
{
    digitalWrite(BUZZER,HIGH);
    delay(del);
    digitalWrite(BUZZER,LOW);
    delay(del);
}

int main(void)
{

    int value;
 
    wiringPiSetup();
    pcf8591Setup(Q2W_ABASE,0x48);
    pinMode(BUZZER,OUTPUT);
    digitalWrite(BUZZER,LOW);

    while(1)
    {
        // 아날로그 값 입력받음
        value = analogRead(Q2W_ABASE + ADC_CH);

        //printf("> %d \r\n",value);        // 출력 값 확인용

        if (value<100)
            voice_freq(value);
    }

    return 0;
}
