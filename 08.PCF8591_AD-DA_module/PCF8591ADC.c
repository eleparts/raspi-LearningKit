/* 08. pcf8591ADC.c
*
* PCF8591 8bit ADC/DAC 모듈로 아날로그 데이터를 받아 라즈베리파이로 전달해 줍니다.
*
* 필요 소자
* PCF8591 모듈, 가변저항 1ea, LED, 저항 220옴 (빨빨검검갈) 
* 
* > PCF8591 모듈 (0,1,3 채널의 모듈 내장 기능을 사용하므로 점퍼를 연결해 주어야 합니다.)
* 모듈의 전원은 각각 3.3V, GND 연결, SDA, SCL 핀은 라즈베리파이의 동일한 SDA(#2), SCL(#3) 에 연결합니다.
* > LED  : Wpi : 1 | BCM : #18
* > 가변저항 : 가변저항의 양 끝은 각각 Vcc(3.3V), GND에 연결해 주고, 가운데 핀은 PCF8591 모듈의 AIN 2에 연결해 줍니다.
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 라즈베리파이 설정에서 I2C를 Enable 해 주어야 PCF8591 모듈과 I2C 통신을 할 수 있습니다.
*/
#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define Q2W_ABASE       120
#define	LED             1

int main (void)
{
  int value[4] = {0,};

  wiringPiSetup();

  pcf8591Setup(Q2W_ABASE, 0x48);

  pinMode(LED, PWM_OUTPUT);
  pwmWrite(LED, 0);

  while(1)
  {
    /* ADC 채널별 출력 데이터 (P4,P5,P6의 점퍼는 연결해 두어야 합니다.)
    *  CH0 : 모듈 내장 CDS(빛 감지)
    *  CH1 : 모듈 내장 써미스터(온도 감지)
    *  CH2 : NC / 추가 가변저항 + LED PWM 제어
    *  CH3 : 모듈 내장 가변저항
    */
    for(int i=0; i<4; i++)
    {
      value[i] = analogRead(Q2W_ABASE + i);
    }
    
    pwmWrite (LED, value[2] * 4);
    printf("> CH0 : %d\t| CH1 : %d\t| CH2 : %d\t| CH3 : %d \n",value[0],value[1],value[2],value[3]);
    delay (100);
  }

  return 0;
}
