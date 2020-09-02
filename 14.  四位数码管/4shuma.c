#include <wiringPi.h>
#include <stdio.h>
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define one 7
#define two 8
#define three 9
#define four 10

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

int main()
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
	
	
	for(;;)
	
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
	
	
	
	}
