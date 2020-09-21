/* 01. HelloWorld.c
*
* 회로 연결은 따로 필요하지 않으며, 터미널 창에 Hello World!!! 를 출력해 줍니다.
*
*/
#include <wiringPi.h>
#include <stdio.h>

int main(void)
{

  wiringPiSetup();

  printf("Hello World!!!\n");
  delay(1000);

  return 0;
}
