/* 14. foursegment
*
* 7-Segment를 이용하여 숫자를 표시해 줍니다. (4 Digit : 4칸짜리 세그먼트)
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
#define a 29
#define b 27
#define c 22
#define d 24
#define e 25
#define f 28
#define g 21
#define one 5
#define two 4
#define three 1
#define four 7

void display0()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);  
}

void display1()
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
  
void display2()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void display3()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

int main(void)
{
  wiringPiSetup();
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(one,OUTPUT);
  pinMode(two,OUTPUT);
  pinMode(three,OUTPUT);
  pinMode(four,OUTPUT);

  while(1)
  {
    digitalWrite(one,LOW);
    display0();
    delay(5);
    digitalWrite(one,HIGH);
    digitalWrite(two,LOW);
    display1();
    delay(5);
    digitalWrite(two,HIGH);
    digitalWrite(three,LOW);
    display2();
    delay(5);
    digitalWrite(three,HIGH);
    digitalWrite(four,LOW);
    display3();
    delay(5);
    digitalWrite(four,HIGH);
  }

  return 0;
}
