#include <wiringPi.h>
#include <stdio.h>
#define a 5
#define b 6
#define c 10
#define d 16
#define e 15
#define f 4
#define g 1

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
	
	for(;;)
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
