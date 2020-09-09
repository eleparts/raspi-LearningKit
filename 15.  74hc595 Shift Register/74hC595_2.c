/* 15. 74hc595_2
*
* 74HC595 Shift Register IC를 이용하여 GPIO를 확장/ 제어해 줍니다.
* 이 IC를 이용하면 적은 GPIO 선으로 다수의 GPIO가 필요한 제품 LED, 7-segment 등을 제어할 수 있습니다
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
#include <stdio.h>
#include <unistd.h>

void SIPO(unsigned char byte);
void pulse(int pin);

int SER   = 4;
int RCLK  = 6;
int SRCLK = 5;
unsigned char LED[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void init() 
{
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  digitalWrite(SER, 0);
  digitalWrite(SRCLK, 0);
  digitalWrite(RCLK, 0);
}

void delayMS(int x) 
{
  usleep(x * 1000);
}


int main (void)
{
  if (wiringPiSetup() == -1) {
    printf("Setup wiringPi failed!");
    return 1;
  }

  init();

  int i;

  while(1)
  {  

    for(i = 0; i < 8; i++)
    {
      SIPO(LED[i]);
      pulse(RCLK);
      delayMS(100);
      //printf(" i = %d", i);
    }

    //printf("\n");
    delayMS(500); // 500 ms
    
    for(i = 7; i >= 0; i--)
    {
      SIPO(LED[i]);
      pulse(RCLK);
      delayMS(100);
      //printf(" i = %d", i);
    }
    delayMS(500); // 500 ms

  }

  usleep(1000);
  digitalWrite(RCLK, 1);
}


void SIPO(unsigned char byte) 
{
  int i;
  for (i=0;i<8;i++) 
  {
    digitalWrite(SER,((byte & (0x80 >> i)) > 0));
    pulse(SRCLK);
  }
}


void pulse(int pin) 
{
  digitalWrite(pin, 1);
  usleep(1);
  digitalWrite(pin, 0);
  usleep(1);
}