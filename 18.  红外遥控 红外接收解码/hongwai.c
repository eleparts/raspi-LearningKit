#include "wiringPi.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#define IR_PIN 7
#define SETBIT(X,Y) ((X)|=(1<<(Y)))
#define CLRBIT(X,Y) ((X)&=~(1<<(Y)))
#define REVBIT(X,Y) ((X)^=(1<<(Y)))
void main()
{
wiringPiSetup();
pinMode(IR_PIN, INPUT);
 pullUpDnControl(IR_PIN, PUD_OFF);
uint32_t i;
uint32_t header1;
uint32_t header2;
uint32_t data[65];
while(1)
 {
restart:
while(!digitalRead(IR_PIN))
{
header1=0;
while(!digitalRead(IR_PIN) && header1<65535)
header1++;
if(header1>=65535) goto restart;
header2=0;
while(digitalRead(IR_PIN) && header2<65535)
header2++;
if(header2>=65535) goto restart;
for(i=64;i>0;i--)
{
data[i]=0;
while(!digitalRead(IR_PIN)&&data[i]<10000) data[i]++;
if(data[i]>=10000) goto restart;
i--;
data[i]=0;
while(digitalRead(IR_PIN)&&data[i]<10000) data[i]++;
if(data[i]>=10000) goto restart;
}
uint32_t keymin=0xffff;
uint32_t keymax=0x0000;
uint32_t keymin_pos = 0;
uint32_t keymax_pos = 0;
for(i=1;i<64;i+=2)
{
if(data[i]>keymax)
{
keymax=data[i];
keymax_pos=i;
}
if(data[i]<keymin)
{
keymin_pos=i;
keymin=data[i];
}
}
//printf("keymin = %d,%d, keymax = %d,%d\n", keymin, keymin_pos,keymax, keymax_pos);
uint32_t kj=0;
uint32_t uj=0;
uint32_t usercode=0x0000;
uint32_t keycode=0x0000;
for(i=1;i<64;i+=2)
{
if((data[i]>=keymin) && (data[i]<=(keymin+1000)))
{
if(i<=31)
kj++;
else
uj++;
}
else if((data[i]<=keymax) && (data[i]>=(keymax-1000)))
{
if(i<=31)
{
SETBIT(keycode,15-kj);
kj++;
}
else
{
SETBIT(usercode,15-uj);
uj++;
}
}
else
goto restart;
}
if((((keycode>>8)&0xff)+ (keycode&0xff)) != 0xff)
{
printf("sum of keycode is not 0xff\n");
goto restart;
}
else
{
printf("usercode=0x%04x,keycode=0x%04x\n",usercode,keycode);
}
}
}
}
