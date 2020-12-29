/* 13.LM35
*
* LM35 온도 센서의 아날로그 출력 신호를 받아 온도로 계산하여 출력해 줍니다.
*
* 필요 소자
* LM35 온도센서, PCF8591(ADC) 모듈
*
* > PCF8591 모듈 (0,1,3 채널 사용 시 사용 전 점퍼를 제거해 주어야 합니다. / 예제에서는 0번 채널 사용)
* 모듈의 전원은 각각 3.3V, GND 연결, SDA, SCL 핀은 라즈베리파이의 동일한 SDA(#2), SCL(#3) 에 연결합니다.
* > LM35 
* 방향(극성)에 주의하여 5V, PCF8591의 ADC IN, GND에 연결해 줍니다. 
* 방향은 납작한 부분이 정면으로 보이도록 하고, 다리(핀)을 하단으로 두었을 때 좌측이 5V핀 입니다. // 이미지 참조
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 라즈베리파이 설정에서 I2C를 Enable 해 주어야 PCF8591 모듈과 I2C 통신을 할 수 있습니다.
*
* ※ 본 예제는 PCF8591 보드 사용 시 값이 정확하게 나오지 않습니다.
* LM35는 4V 이상의(4~20V)전압을 공급 시 1'C 당 10mV의 전압을 출력하는 소자입니다 (1~150'C / 10~1500mV) 
* 단, PCF8591 칩/모듈이 8bit(256) ADC로 정밀도가 낮아 3.3V 연결 시 최소 전압 측정 범위가 12.9mV가 됩니다. 
* 또한, 500mV 이하의 낮은 전압에서 크게는 100mV 까지 오차가 발생하는 현상 등이 있어 상온(25'C / 250mV) 출력 전압이 정확하게 읽히지 않습니다.
* 별도의 고정밀 ADC보드가 있는 경우가 아니라면 대략적인 온도 변화의 유무 확인용으로만 사용하시는 것을 권장드립니다.
*
*/

#include <wiringPi.h>
#include <pcf8591.h>    // Need i2C Enable
#include <stdio.h>

#define Q2W_ABASE   120
#define ADC_CH        0

int main(void)
{
    int value, dat, temp;

    wiringPiSetup();
    pcf8591Setup(Q2W_ABASE, 0x48);

    while(1)
    {
        value = analogRead(Q2W_ABASE + ADC_CH);

        // printf("data: %d \r\n ",value);

        /*
        *  ADC data :
        *  19.61 : ADC 8bit(256 / 0~5V)
        *  12.94 : ADC 8bit(256 / 0~3.3V)
        */
        dat = (value * 12.94);
        temp = dat / 10;

        printf("dat : %d mV | temp : %d 'C \n", dat, temp);
        delay(100);
    }

    return 0;
}


