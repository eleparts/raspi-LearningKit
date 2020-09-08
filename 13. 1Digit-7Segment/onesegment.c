/* 13. onesegment
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

#define a 5
#define b 6
#define c 10
#define d 16
#define e 15
#define f 4
#define g 1
// DP not use

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

void display4()
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void display5()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
  
void display6()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void display7()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void display8()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void display9()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
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

  while(1)
  {
    display0();
    delay(1000);
    display1();
    delay(1000);
    display2();
    delay(1000);
    display3();
    delay(1000);
    display4();
    delay(1000);
    display5();
    delay(1000);
    display6();
    delay(1000);
    display7();
    delay(1000);
    display8();
    delay(1000);
    display9();
    delay(1000);
  }

  return 0;	
}
