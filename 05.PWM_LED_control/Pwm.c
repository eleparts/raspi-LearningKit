/* 05. Pwm.c
*
* PWM 기능을 이용해 LED의 밝기를 조절해 줍니다.
*
* 필요 소자
* LED : 1ea, 저항 220옴 1ea(색띠 : 빨빨검검갈)
* 
* LED : Wpi : 1 | BCM : #18
* 
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
/*
 * pwm.c:
 *	This tests the hardware PWM channel.
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
    int bright;

    printf ("Raspberry Pi wiringPi PWM test program\n");

    if (wiringPiSetup() == -1)
        exit(1);

    pinMode (1,  PWM_OUTPUT);               // LED 핀 PWM 설정

    while (1)                               // 무한 반복 - PWM 밝기 제어
    {
        for (bright = 0 ; bright < 1024 ; ++bright)
        {
            pwmWrite(1, bright);
            delay(1);
        }

        for (bright = 1023 ; bright >= 0 ; --bright)
        {
            pwmWrite(1, bright);
            delay(1);
        }
    }

    return 0;
}
