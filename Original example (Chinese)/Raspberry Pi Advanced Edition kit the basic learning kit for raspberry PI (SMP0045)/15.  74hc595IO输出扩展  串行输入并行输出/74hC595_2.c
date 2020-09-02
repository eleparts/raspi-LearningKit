#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
int SER   = 4;
int RCLK  = 6;
int SRCLK = 5;
unsigned char LED[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
void SIPO(unsigned char byte);
void pulse(int pin);
void init() {
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
    if (-1 == wiringPiSetup()) {
        printf("Setup wiringPi failed!");
        return 1;
    }    
    init();
    int i;
    while(1) {  
      for(i = 0; i < 8; i++)
      {
       SIPO(LED[i]);
       pulse(RCLK);
       delayMS(50);
       printf(" i = %d", i);
      }
      printf("\n");
      delayMS(500); // 500 ms
      
      for(i = 7; i >= 0; i--)
      {
       SIPO(LED[i]);
       pulse(RCLK);
       delayMS(50);
       printf(" i = %d", i);
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
    digitalWrite(pin, 0);
}







