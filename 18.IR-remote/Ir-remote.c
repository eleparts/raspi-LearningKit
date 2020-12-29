/* 18. Ir-remote.c
*
* 적외선 수신기와 리모컨으로 데이터를 수신해 줍니다.
*
* 필요 소자
* 리모컨, 적외선 수신기(1838b)
* 
* 적외선 수신기(1838b)
* Vcc(V) : 5V | GND(G) : GND
* Signal(S) : Wpi : 1 | BCM : #18
* ┌─────────┐
* │    X    │ (앞면 X 모양 부분)
* └─┬──┬──┬─┘
*   │  │  │
*   S  G  V
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
* ※ 적외선 리모컨의 출력은 us(마이크로 초) 단위의 매우 빠른 HIGH/LOW신호의 반복으로 비트값에 따른 HIGH 신호 대비 LOW 신호의 길이가 다르므로 
*  LOW신호의 길이를 HIGH 신호와 비교하여 1 혹은 0으로 변환해 데이터로 만들어 줄 수 있습니다.
*/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNT_DEBUG 0       // COUNT 값 확인용 DEBUG 옵션

#define MAX_DATA	  256     // Total data length : [head 2 + data 64 + end 2] + hode time [t x 4] 
                              // 너무 키를 오래 눌러 이 범위 초과 시 다음 출력에서 헤더 에러 발생

#define END_DELAY   300000  // 종료 확인용 대기시간 (us)  / COUNT_DEBUG에서 표시되는 최대 값보다 높아야 함 

#define DATA_PIN     1      //  Wpi : 1 | BCM : #18


int read_KEYES_Remote_data(){

    uint8_t laststate = LOW;
    uint8_t get_data  = 0;
    unsigned int counter   = 0;
    int data_cnt[MAX_DATA] = {0,};
    int get_data_cnt = 0;
    int key_hold_time = 0;
    int one_bit = 0;
 
    int data[5] = {0,};
 
    /* Data 핀을 READ로 변경해 데이터 수신 */
    pinMode( DATA_PIN, INPUT );


    /* 데이터가 들어올 때까지 무한 대기상태*/
    while(1){

        /* 입력 핀 HIGH 상태로 대기, LOW로 시작신호가 전달되면 데이터 읽기 시작 */
        if(!digitalRead(DATA_PIN)){ 


            /* 데이터 입력(H/L펄스 폭), 최대 MAX_DATA까지  */
            for(int i=0;i<MAX_DATA;i++){

                counter = 0;
                while ( digitalRead( DATA_PIN ) == laststate ){     // 신호가 반전되는지 검사(H->L / L->H)

                    counter++;                   
                    delayMicroseconds( 1 );                         // H/L 신호가 유지되는 동안 1us (1 마이크로 초)마다 counter를 올려줍니다.

                    if ( counter >= END_DELAY ){
                     break;
                    }
                }
                laststate = digitalRead( DATA_PIN ); 
                get_data_cnt++;

                data_cnt[i] =  counter;

                if ( counter >= END_DELAY ){                        // END_DELAY 시간동안 H/L변환 없는 경우 데이터 수신 종료 (300,000us = 0.3초)
                    break;
                }
            }

            /* 입력받은 값을 데이터 , 2개의 입력 값 [pulse(HIGH) : space(LOW)] 의 크기(펄스 폭)를 비교하여 결정*/
            /* 데이터 수신은 68 : 헤더 2 + 데이터 64 (4(4자리)*8(byte)*2(H+L)) + 종료 2 */
            for ( int i = 0; i < 68; i++ ){   // data leanth 68 + key hold

                /* 처음 2개 데이터는 HEAD 신호로 무시 */
                if ( (i > 1) && (i % 2 == 0) ){

                    data[get_data / 8] <<= 1;

                    /* 각 2개 데이터의 pulse(HIGH) : space(LOW) 길이를 비교하여 데이터(HIGH/LOW)로 작성, DATA배열에 입력 */
                    if ( (data_cnt[i]*2) < (data_cnt[i+1]) ){
                        data[get_data / 8] |= 1;
                    }

                    get_data++;
                }
            }

            /* 헤더 검사 / 데이터 정상여부 판단 */
            one_bit = data_cnt[2] + data_cnt[3];

            if(!((data_cnt[0] > one_bit) && (data_cnt[1] > one_bit) && (data_cnt[0] > data_cnt[1]))){
                printf("Header Data error\n");
                break;
            }
            
            /* Key HOLD 검사 (오래 누르고 있으면 일정한 데이터가 출력됨) */
            /* 68 이후부터 4 씩 (57x : 96xxx / 90xx : 22xx) hold 지연값 반복 출력됨 */ 
            for(int i = 68; i<get_data_cnt; i++){

                if((i-68)%4==0){

                    if ((data_cnt[i]+data_cnt[i+1] < data_cnt[i+3]) && (data_cnt[1] < data_cnt[i])){

                        key_hold_time++;

                    }else{
                        break;
                    }
                }
            }


            #if COUNT_DEBUG
            /* COUNT_DEBUG의 flag 를 1로 변경해 컴파일하면 저장된 counter 데이터 값을 확인할 수 있습니다. */
            printf("\ncounter data :\r\n>> pulse : space\n");
            for(int i=0; i<get_data_cnt; i++)
            {
                if((i%2) == 0)
                    printf("%d >> %d : %d \n", i, (data_cnt[i]), data_cnt[i+1] );
            }
            printf("Data length : %d \r\n",get_data_cnt);
            #endif


            /* 데이터 출력 및 키 누르고 있는 시간에 따라 '+'기호 추가로 출력 */
            printf("DATA : [0x%x][0x%x][0x%x][0x%x]", data[0],data[1], data[2],data[3]);
            for(int i = 0; i< key_hold_time; i++){
                printf("+");
            }
            printf("\n");

            return 0;
        }
    }
}
 

int main(void)
{

    printf( "IR TEST >> PUSH Remote control button\n" );

    if (wiringPiSetup() == -1)
    {
        return 1;
    }

    while(1)
    {
        read_KEYES_Remote_data();
    }
 
    return(0);
}