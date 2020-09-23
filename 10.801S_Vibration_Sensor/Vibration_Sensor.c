/* 10. Vibration_Sensor.c
* 
* 801S 진동센서로 진동을 감지하여 감지된 데이터를 출력해 줍니다.
* 
* 필요 소자
* PCF8591 모듈, 801S 진동센서 모듈
* 
* > PCF8591 모듈 (0,1,3 채널 사용 시 사용 전 점퍼를 제거해 주어야 합니다. / 예제에서는 0번 채널 사용)
* 모듈의 전원은 각각 3.3V, GND 연결, SDA, SCL 핀은 라즈베리파이의 동일한 SDA(#2), SCL(#3) 에 연결합니다.
* > 801S 진동센서 모듈
* VCC : 3.3V | GND : GND
* DO (Digtal Out) : Wpi : 1 | BCM : #18
* AO (Analog Out) : PCF8591 모듈의 AIN 0 에 연결해 줍니다.
*
* ※ 801S 진동센서 모듈의 Digtal Out 출력 민감도는 센서보드의 가변저항을 돌려 조절해 줄 수 있습니다.
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 라즈베리파이 설정에서 I2C를 Enable 해 주어야 PCF8591 모듈과 I2C 통신을 할 수 있습니다.
*/
#include <wiringPi.h>
#include <pcf8591.h>        // Need i2C Enable
#include <stdio.h>

#define	D_801S        1     // #18
#define Q2W_ABASE     120
#define ADC_CH        0


int main(void)
{

  int digtalValue = 0, analogValue = 0;
  
  wiringPiSetup();

  pcf8591Setup(Q2W_ABASE,0x48);

  pinMode(D_801S, INPUT);

  printf("-- 801S Vibration Sensor --\n\n");
  
  while(1)
  {
    digtalValue = digitalRead(D_801S);
    analogValue = analogRead(Q2W_ABASE + ADC_CH);
    
    /* 디지털 데이터 및 아날로그 데이터 출력 (디지털 출력은 ! 로 표시) */
    printf("Digtal : %s \t| Analog : %d  \n", (digtalValue ? "!!!": " . " ), analogValue);
    //printf("Digtal : %d \t| Analog : %d  \n", digtalValue, analogValue);      // 출력 값 확인(기본)
    delay(200);
  }

  return 0;
}
