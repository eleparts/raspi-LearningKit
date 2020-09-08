/* 13. 7Segment(1Digit)
*
* 7-Segment를 이용하여 숫자를 표시해 줍니다. (1 Digit : 1칸짜리 세그먼트)
*
* 필요 소자
* 1Digit 7-Segment, 저항 8ea (220옴 / 색띠 : 빨빨검검갈)
*
* 7-Segment / 각 핀에 220옴 저항을 연결해 줍니다.
* ( 1)SEG_E : Wpi: 15 | BCM : #14
* ( 2)SEG_D : Wpi: 16 | BCM : #15
* ( 3)SEG_GND : GND
* ( 4)SEG_C : Wpi: 10 | BCM : #8
* ( 5)SEG_DP: Wpi: 11 | BCM : #7
* ( 6)SEG_B : Wpi: 6  | BCM : #25
* ( 7)SEG_A : Wpi: 5  | BCM : #24
* ( 8)SEG_GND : GND
* ( 9)SEG_F : Wpi: 4  | BCM : #23
* (10)SEG_G : Wpi: 1  | BCM : #18
* (괄호) 안의 숫자는 세그먼트 핀 번호(Segment pin number)
*
* G F GND A B
* 10 9 8  7 6  : Segment pin number
* ┌─────────┐
* │ segment │
* └─────────┘
* 1 2  3  4 5  : Segment pin number
* E D GND C DP
*
* GNS-5611A datasheet : https://www.electronicoscaldas.com/datasheet/GNS-5611-Series_G-NOR.pdf
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
#include <wiringPi.h>
#include <stdio.h>

#define SEG_A   5   // #24
#define SEG_B   6   // #25
#define SEG_C   10  // #8
#define SEG_D   16  // #15
#define SEG_E   15  // #14
#define SEG_F   4   // #23
#define SEG_G   1   // #18
#define SEG_DP  11  // #7

int segmentPinNumber[8] = {        // 세그먼트 GPIO 번호
  SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP
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

int main(void)
{
  wiringPiSetup();

  for(int i=0;i<8;i++)
  {
    pinMode(segmentPinNumber[i],OUTPUT);
  }

  while(1)
  {
    for(int j=0;j<11;j++)
    {
      for(int i=0;i<8;i++)
      {
        digitalWrite(segmentPinNumber[i],segmentValue[j][i]);
      }

      delay(1000);
    }
  }

  return 0;
}