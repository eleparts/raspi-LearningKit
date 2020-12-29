/* 14. Onesegment
*
* 7-Segment를 이용하여 숫자를 표시해 줍니다. (1 Digit : 1칸짜리 세그먼트)
*
* 필요 소자
* 1Digit 7-Segment, 저항 8ea (220옴 / 색띠 : 빨빨검검갈)
*
* 7-Segment / 각 핀에 220옴 저항을 연결해 줍니다.
* ( 1)SEG_E : Wpi: 25 | BCM : #26
* ( 2)SEG_D : Wpi: 24 | BCM : #19
* ( 3)SEG_GND : GND
* ( 4)SEG_C : Wpi: 23 | BCM : #13
* ( 5)SEG_DP: Wpi: 22 | BCM : #6
* ( 6)SEG_B : Wpi: 26 | BCM : #12
* ( 7)SEG_A : Wpi: 27 | BCM : #16
* ( 8)SEG_GND : GND
* ( 9)SEG_F : Wpi: 28 | BCM : #20
* (10)SEG_G : Wpi: 29 | BCM : #21
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

#define a 27
#define b 26
#define c 23
#define d 24
#define e 25
#define f 28
#define g 29
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
