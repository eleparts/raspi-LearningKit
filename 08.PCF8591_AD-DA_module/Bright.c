/* 08. bright.c
*
* PCF8591 8bit ADC/DAC 모듈로 아날로그 데이터를 받아 라즈베리파이로 전달해 줍니다.
*
* 필요 소자
* PCF8591 모듈, 가변저항 1ea, LED, 저항 220옴 (빨빨검검갈) 
* 
* > PCF8591 모듈 (0,1,3 채널 사용 시 사용 전 점퍼를 제거해 주어야 합니다.
* 모듈의 전원은 각각 3.3V, GND 연결, SDA, SCL 핀은 라즈베리파이의 동일한 SDA(#2), SCL(#3) 에 연결합니다.
* > LED  : Wpi : 1 | BCM : #18
* > 가변저항 : 가변저항의 양 끝은 각각 Vcc(3.3V), GND에 연결해 주고, 가운데 핀은 PCF8591 모듈의 AIN 2에 연결해 줍니다.
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 라즈베리파이 설정에서 I2C를 Enable 해 주어야 PCF8591 모듈과 I2C 통신을 할 수 있습니다.
*/
/*
 * bright.c:
 *	Vary the Q2W LED brightness with the analog card
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

#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define	LED             1
#define Q2W_ABASE       120
#define ADC_CH          2       // ADC 0~3 channel

int main (void)
{
    int value ;

// Enable the on-goard GPIO

    wiringPiSetup () ;

// Add in the pcf8591 on the q2w board

    pcf8591Setup (Q2W_ABASE, 0x48) ;

    printf ("Raspberry Pi - Quick2Wire Analog Test\n") ;

// Setup the LED

    pinMode  (LED, PWM_OUTPUT) ;
    pwmWrite (LED, 0) ;

    while(1)
    {
        value = analogRead(Q2W_ABASE + ADC_CH) ;
        pwmWrite (LED, value * 4) ;
        printf("value=%d\n",value);
        delay (100) ;
    }

    return 0 ;
}
