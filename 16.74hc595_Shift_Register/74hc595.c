/* 16. 74hc595
*
* 74HC595 Shift Register IC를 이용하여 GPIO를 확장/ 제어해 줍니다.
* 이 IC를 이용하면 적은 GPIO 선으로 다수의 GPIO가 필요한 제품 LED, 7-segment 등을 제어할 수 있습니다.
* 본 예제에서는 IC의 출력 핀에 LED를 연결해 제어해 줍니다.
*
* 필요 소자
* 74HC595 IC, LED 8ea, 220옴 저항 8ea (색띠 : 빨빨검검갈)
*
* > 74HC595 IC
* Vcc, ~RESET  : 3.3V
* GND, ~OE    : GND
* Data   : Wpi: 4 | BCM : #23
* Clock  : Wpi: 5 | BCM : #24
* Latch  : Wpi: 6 | BCM : #25
* QA ~ QH 는 출력 핀으로 차례대로 LED(+저항)를 연결해 줍니다.
*    ┌──U──┐
* QB │     │ Vcc
* QC │  7  │ QA
* QD │  4  │ DATA
* QE │  5  │ ~OE (~Output Enable)
* QF │  9  │ Latch (Storage(Latch) Register Clock)
* QG │  5  │ Clock (Shift Register Clock)
* QH │     │ ~RESET
* GND│     │ QH'
*    └─────┘
* ※ 74595 IC는 Shift Register 및 Storage(Latch) Register 로 이루어져 있으며, Shift Register 는 데이터를 차례대로 각 핀에 할당,
* Storage(Latch) Register 는 위 Shift Register에 저장된 값을 받아 저장해 각 출력 핀으로 출력해 주는 역활을 합니다.
* 따라서, Shift Register에 8번의 클럭을 받아 데이터를 수신, Storage(Latch) Register에 1클럭을 주어 데이터를 출력(적용)해 주는 방식으로 동작됩니다.
*
* 참고 데이터시트 : https://www.eleparts.co.kr/data/goods_old/data/U74HC595A.pdf
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
#include <wiringPi.h>
#include <wiringShift.h>
#define data   4    //#23
#define clock  5    //#24
#define latch  6    //#25

/*   WPI : <wiringShift.h> 라이브러리 shiftOut 함수에 지연 추가   */
void shiftOut1 (uint8_t dPin, uint8_t cPin, uint8_t order, uint8_t val)
{
    int8_t i;

    if (order == MSBFIRST)
    {
        for (i = 7 ; i >= 0 ; --i)
        {
            digitalWrite (dPin, val & (1 << i));
            digitalWrite (cPin, HIGH);
            delayMicroseconds(1);        // 라즈베리파이의 IO 제어가 74HC595 최대 클럭 속도보다 빨라 지연 추가
            digitalWrite (cPin, LOW);
            delayMicroseconds(1);
        }
    }else{
        for (i = 0 ; i < 8 ; ++i)
        {
            digitalWrite (dPin, val & (1 << i));
            digitalWrite (cPin, HIGH);
            delayMicroseconds(1);
            digitalWrite (cPin, LOW);
            delayMicroseconds(1);
        }
    }
}

void updateLEDs(int value)  // LED 제어 함수
{
    digitalWrite(latch,LOW);
    shiftOut1(data,clock,MSBFIRST,value); // LSBFIRST MSBFIRST
    digitalWrite(latch,HIGH);
}

int main()
{
    int i;

    wiringPiSetup();

    pinMode(data,OUTPUT);   // 74HC595용 핀 설정
    pinMode(clock,OUTPUT);
    pinMode(latch,OUTPUT);

    while(1)                // 무한반복 - LED 제어
    {
        for (int i = 0; i < 255; i++)
        {
            updateLEDs(i);
            delay(500);
        }
    }

    return 0;
}
