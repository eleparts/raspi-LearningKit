/* 24. Keypad.c
*
* 키패드로 입력받은 문자를 터미널로 출력해 줍니다.
*
* 필요 소자
* 키패드 모듈
*
* 키패드 모듈 / 키패드를 글자가 바로 보이게 두고 왼쪽 아래 핀부터 Pin1 -> Pin8 입니다.
* P1 : Wpi : 26 | BCM : #12     // P1~P4 : ROW (행)
* P2 : Wpi : 27 | BCM : #16
* P3 : Wpi : 28 | BCM : #20
* P4 : Wpi : 29 | BCM : #21
* P5 : Wpi : 22 | BCM : #6      // P5~P8 : COL (열)
* P6 : Wpi : 23 | BCM : #13
* P7 : Wpi : 24 | BCM : #19
* P8 : Wpi : 25 | BCM : #26
*
* ※ 키패드 예제는 하나의 행만 HIGH 상태로 변경해 각 열의 값을 읽는 것을 행 수만큼 반복, 특정 행/열의 키가 눌린것을 감지해 줍니다.
*   다만, 키패드의 구조적 한계로 동일 열의 키(ex. 1,4,7,*)가 동시에 눌린 경우 출력(ROW 1~4) 신호가 합쳐져(쇼트) 키 값을 읽지 못하게 될 수 있습니다.
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
#include <stdio.h>
#include <wiringPi.h>

#define KEY_PAD_ROWS  4
#define KEY_PAD_COLS  4

#define ROW_1   26    // #12
#define ROW_2   27    // #16
#define ROW_3   28    // #20
#define ROW_4   29    // #21

#define COL_1   22    // #6
#define COL_2   23    // #13
#define COL_3   24    // #19
#define COL_4   25    // #26

int keyPadRowPin[4] = {ROW_1, ROW_2, ROW_3, ROW_4};
int keyPadColPin[4] = {COL_1, COL_2, COL_3, COL_4};

char keyPadsMap[KEY_PAD_ROWS][KEY_PAD_COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};


/* 키패드의 입력받은 한 행의 0~4열을 스캔해 입력값이 있는 경우 해당 문자를 반환 */
char keyPadScan(int row){
    
    /* 키패드의 스캔할 행만 HIGH로, 나머지 행은 LOW로 설정해 줍니다 */
    for(int i=0;i<KEY_PAD_ROWS;i++){
        
        if( i == row ) {
            digitalWrite(keyPadRowPin[i], HIGH);
        }else{
            digitalWrite(keyPadRowPin[i], LOW);
        }
    }

    /* 4열의 값을 차례대로 입력받아 줍니다 */
    for(int i=0;i<KEY_PAD_COLS;i++){
        
        if(digitalRead(keyPadColPin[i])){

            return keyPadsMap[row][i];   // 처음 인식되는 키 하나 반환 (다중 키입력 X)
        }
    
    }

    return 0;
}

/* 키패드를 한 행씩 스캔(함수 호출)합니다 */
char getKeyPad(){
    
    char getKeyPad = 0;

    for(int i=0; i<KEY_PAD_ROWS; i++)
    {
        getKeyPad = keyPadScan(i);

        if(getKeyPad != 0){
            return getKeyPad;       // 입력된 값이 있는 경우 문자를 반환하고 종료 (다중 키입력 X)
        }
    }

    return 0;
}



int main(void){

    char keyValue = 0;

    wiringPiSetup();

    /* ROW(행) OUTPUT 설정 */
    pinMode(ROW_1,OUTPUT);
    pinMode(ROW_2,OUTPUT);
    pinMode(ROW_3,OUTPUT);
    pinMode(ROW_4,OUTPUT);

    /* COL(열) INPUT 설정 */
    pinMode(COL_1,INPUT);
    pinMode(COL_2,INPUT);
    pinMode(COL_3,INPUT);
    pinMode(COL_4,INPUT);

    /* 풀'다운': 신호가 입력되지 않을 때 'LOW'가 입력 되도록 해 줍니다. <-> 풀업 */
    pullUpDnControl (COL_1, PUD_DOWN);
    pullUpDnControl (COL_2, PUD_DOWN);
    pullUpDnControl (COL_3, PUD_DOWN);
    pullUpDnControl (COL_4, PUD_DOWN);


    while(1){

        keyValue =  getKeyPad();

        if(keyValue != 0){
            printf("get key : %c \n", keyValue);
            delay(400);   // 키가 연속입력되지 않도록 누른 후 지연
        }
        delay(100);

    }

    return 0;
}