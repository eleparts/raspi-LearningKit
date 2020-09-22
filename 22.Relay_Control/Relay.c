/* 22. Relay.c
*
* GPIO 신호로 릴레이를 이용/제어하여 별도의 전원을 사용하는 회로를 제어해 줍니다.
*
* 필요 소자 : 릴레이 모듈, LED 2ea, 저항 220옴 2ea(빨빨검검갈)
* 
* 릴레이 모듈 
* VCC : 5V, GND : GND
* DAT : Wpi : 7 | BCM : #4
* 
* 릴레이 모듈의 전원(VCC,GND)/제어(DAT)핀의 반대쪽 터미널은 앞단과 분리된 접점(스위치) 회로입니다.
* 가운데 단자(COM)는 (5V or 3.3V) 전원을 입력, 나머지 두 단자(NO/NC)는 릴레이 상태에 따라 COM 핀과 연결되는 스위치 단자 이므로 각 단자 뒤로 LED,저항을 연결해 주시면 됩니다.
* > 릴레이는 전자석을 이용해 스위치를 제어하는 부품으로 입력부와 제어부가 독립되어 있기 때문에 별도의 전원회로(고전압, 교류전원 등)을 제어하는 동작이 가능합니다. 
* (단, 릴레이의 스펙에 주의)
*
* ※ 릴레이 접점(NO,NC,COM)에 대하여 : https://blog.naver.com/elepartsblog/221470372661
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
#include <stdio.h>
#include <wiringPi.h>

#define RELAY    7  // #4


int main(void){

  if(wiringPiSetup()==-1){
    return 1;
  }
  
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY,LOW);


  while(1){

    digitalWrite(RELAY,HIGH);
    delay(1000);

    digitalWrite(RELAY,LOW);
    delay(1000);

  }
}