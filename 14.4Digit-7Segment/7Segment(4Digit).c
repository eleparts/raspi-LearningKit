/* 14. 7Segment(4Digit)
*
* 7-Segment를 이용하여 숫자를 표시해 줍니다. (4 Digit : 4칸짜리 세그먼트)
* 여러 채널(4Digit) 세그먼트의 동작 구조는 각 채널을 매우 빠른 속도로 순서대로 on/off하여 눈이 잔상을 인식해 모든 채널이 켜져 있는 것처럼 보이는 구조입니다.
* 스마트폰 등에 슬로우 모션 촬영 기능이 있는 경우 동작 영상 촬영해 보시거나 아래 코드의 BLINK_SPEED 값을 늘리면 동작 확인이 가능합니다.
*
* 필요 소자
* 4Digit 7-Segment, 저항 8ea (220옴 / 색띠 : 빨빨검검갈) // 연결 시 저항 다리가 쇼트되지 않도록 주의해 줍니다.
*
* 7-Segment / 각 핀(A~G,DP)에 220옴 저항을 연결해 줍니다. (D1~D4는 GND의 역활로 저항을 연결하지 않음)
* ( 1)SEG_E  : Wpi: 25 | BCM : #26
* ( 2)SEG_D  : Wpi: 24 | BCM : #19
* ( 3)SEG_DP : Wpi: 23 | BCM : #13
* ( 4)SEG_C  : Wpi: 22 | BCM : #6
* ( 5)SEG_G  : Wpi: 21 | BCM : #5
* ( 6)SEG_D4 : Wpi:  7 | BCM : #4
* ( 7)SEG_B  : Wpi: 27 | BCM : #16
* ( 8)SEG_D3 : Wpi:  1 | BCM : #18
* ( 9)SEG_D2 : Wpi:  4 | BCM : #23
* (10)SEG_F  : Wpi: 28 | BCM : #20
* (11)SEG_A  : Wpi: 29 | BCM : #21
* (12)SEG_D1 : Wpi:  5 | BCM : #24
* (괄호) 안의 숫자는 세그먼트 핀 번호(Segment pin number)
* 4-Digit 모듈은 전체 모듈의 공통 GND 가 없으며, 4개의 7-Segment 회로마다 독립된 COM 단자(D1~D4)가 GND 역활을 해 줍니다.
* 이를 이용하여 각 4개의 7-Segment 회로를 독립적으로 제어할 수 있습니다.
*
* D1  A  F D2 D3  B
* 12 11 10  9  8  7  : Segment pin number
* ┌────────────────┐
* │ │4ch segment│  │
* │ D1│ D2│ D3│ D4 │
* └────────────────┘
*  1  2  3  4  5  6  : Segment pin number
*  E  D DP  C  G D4
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
#include <wiringPi.h>
#include <stdio.h>

#define SEG_A       29
#define SEG_B       27
#define SEG_C       22
#define SEG_D       24
#define SEG_E       25
#define SEG_F       28
#define SEG_G       21
#define SEG_DP      23
#define SEG_Digit1   5
#define SEG_Digit2   4
#define SEG_Digit3   1
#define SEG_Digit4   7

int segmentPinNumber[8] = {        // 세그먼트 GPIO 번호
  SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP
};

int segmentDigitPinNumber[4] = {
  SEG_Digit1, SEG_Digit2, SEG_Digit3, SEG_Digit4

};

int segmentValue[11][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,1,0,1,1,0}, // 9
  {0,0,0,0,0,0,0,1}, // DOT
};


int drawSegment(int number)
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(segmentPinNumber[i],segmentValue[number][i]);
  }
  return 0;
}

int draw4DigitSegment(int value)
{
  int D1,D2,D3,D4;

  value = value % 10000;
  
  D1 = value / 1000;
  D2 = (value / 100) % 10;
  D3 = (value / 10) % 10;
  D4 = value % 10;

  digitalWrite(segmentDigitPinNumber[0],LOW);
  drawSegment(D1);
  delay(2);
  digitalWrite(segmentDigitPinNumber[0],HIGH);

  digitalWrite(segmentDigitPinNumber[1],LOW);
  drawSegment(D2);
  delay(2);
  digitalWrite(segmentDigitPinNumber[1],HIGH);

  digitalWrite(segmentDigitPinNumber[2],LOW);
  drawSegment(D3);
  delay(2);
  digitalWrite(segmentDigitPinNumber[2],HIGH);

  digitalWrite(segmentDigitPinNumber[3],LOW);
  drawSegment(D4);
  delay(2);
  digitalWrite(segmentDigitPinNumber[3],HIGH);

  return 0;
}

int main(void)
{
  int bootMsTime = 0;
  int value = 0;

  wiringPiSetup();

  for(int i=0;i<8;i++)
  {
    pinMode(segmentPinNumber[i],OUTPUT);
  }

  for(int i=0;i<4;i++)
  {
    pinMode(segmentDigitPinNumber[i],OUTPUT);
  }
  
  bootMsTime = millis();

  while(1)
  {
    value = (millis() - bootMsTime)/10;
    //printf("> %d \n",value);            // 터미널로 표시 값 출력
    draw4DigitSegment(value);
  }

  return 0;
}