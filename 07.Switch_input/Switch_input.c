/* 07. Switch input
*
* 텍트 스위치와 틸트(볼) 스위치의 상태를 입력받아 LED를 ON/OFF 해 줍니다.
*
* 필요 소자
* 텍트스위치, 틸트 스위치, LED 2ea, 저항 220옴 2ea, 10k옴 2ea
* 
* LED : Wpi : 4 | BCM : #23
* LED : Wpi : 5 | BCM : #24
* 텍트 스위치 : Wpi : 0 | BCM : #17
* 틸트 스위치 : Wpi : 2 | BCM : #27  -> 틸트(볼) 스위치는 본체를 기울여 주면 동작합니다.
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 스위치는 두종류 다 10k옴 저항을 이용하여 풀업회로를 구성해 줍니다. 
*/
#include <stdio.h>
#include <wiringPi.h>

#define	LED1    4  // #23
#define	LED2    5  // #24
#define	TACTSW  0  // #17
#define	TILTSW  2  // #27
 
int main (void)
{
    int tactsw, tiltsw;

    wiringPiSetup();

    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

    pinMode(TACTSW, INPUT);
    pinMode(TILTSW, INPUT);

    while(1)
    {
        tactsw = digitalRead(TACTSW);
        tiltsw = digitalRead(TILTSW);

        if(tactsw == 0)
        {
            digitalWrite(LED1, 1);
        }else{
            digitalWrite(LED1, 0);
        }
        
        if(tiltsw != 0)
        {
            digitalWrite(LED2, 1);
        }else{
            digitalWrite(LED2, 0);
        }

        delay(100);
    }

    return 0;
}
