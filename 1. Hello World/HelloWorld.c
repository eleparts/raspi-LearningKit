#include <wiringPi.h>
#include <stdio.h>

int main(void)
{

  wiringPiSetup();

  printf("Hello World!!!\n");
  delay(1000);

  return 0;
}
