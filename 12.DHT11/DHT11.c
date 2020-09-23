/* 12.DHT11
*
* 온습도 센서에서 수신된 데이터를 터미널 창으로 반복해 출력하는 동작을 합니다.
*
* 필요 소자
* 온습도 센서 (DHT11) 
*
* 온습도 센서 (DHT11) 
* VCC 핀 : 3.3V
* GND 핀 : GND
* S(signal) : Wpi : 29 | BCM : #21
*
* ※ Wpi번호는 wiringPi 라이브러리가 사용하는 핀 번호이며, BCM 번호는 GPIO Cobbler Plus V2 보드에 적혀있는 번호입니다.
*/
/*
* dht.c:
*	read temperature and humidity from DHT11 or DHT22 sensor
* http://www.uugear.com/portfolio/read-dht1122-temperature-humidity-sensor-from-raspberry-pi/
*/

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COUNT_DEBUG 0       // COUNT 값 확인용 DEBUG 옵션

#define MAX_TIMINGS	85
#define DHT_PIN     29

int data[5] = {0,};

void read_dht_data()
{

  uint8_t laststate = HIGH;
  uint8_t counter   = 0;
  uint8_t get_data  = 0;
  int data_cnt[MAX_TIMINGS] = {0,};
 
  data[0] = data[1] = data[2] = data[3] = data[4] = 0;
 
  /* DHT Data 핀을 18ms 동안 LOW로 변경해 센서에 데이터 송신 시작 요청 */
  pinMode( DHT_PIN, OUTPUT );
  digitalWrite( DHT_PIN, LOW );
  delay(18);
 
  /* DHT Data 핀을 READ로 변경해 데이터 수신 준비 */
  pinMode( DHT_PIN, INPUT );
 
  /* 응답 준비, ready 신호(0~3) 및 DATA 신호(40*2) 길이(counter 이용) 저장 */
  for ( int i = 0; i < MAX_TIMINGS; i++ )
  {
    counter = 0;
    while ( digitalRead( DHT_PIN ) == laststate )
    {

      counter++;
      delayMicroseconds( 1 );
      if ( counter >= 255 )
      {
        break;
      }
    }
    laststate = digitalRead( DHT_PIN );
 
    if ( counter >= 255 )
    {
      break;
    }

    data_cnt[i] =  counter;
  }

  /* 
  * 저장된 데이터 가공처리 
  * DHT 11의 데이터는 50us의 LOW 신호 이후 HIGH의 신호 길이에 따라 데이터를 LOW / HIGH로 구별합니다. (28us : LOW, 70us : HIGH)
  * 이를 이용하여 앞의 LOW 신호 길이를 기준으로 뒤의 HIGH 신호의 길이를 비교해 HIGH/LOW 데이터로 구분할 수 있습니다.
  */
  for ( int i = 0; i < MAX_TIMINGS; i++ )
  {

    /* 처음 3개 데이터는 응답 준비 신호로 무시 */
    if ( (i >= 4) && (i % 2 == 0) )
    {

      /* 온&습도 데이터 저장 */
      data[get_data / 8] <<= 1;

      /* 뒤의 HIGH 신호의 길이가 앞의 LOW 신호보다 짧으면 LOW, 길면 HIGH 로 분류, 저장 */
      if ( data_cnt[i] > data_cnt[i-1] ){
        data[get_data / 8] |= 1;
      }

      get_data++;
    }
  }

  #if COUNT_DEBUG
  /* COUNT_DEBUG의 flag 를 1로 변경해 컴파일하면 저장된 counter 값을 확인할 수 있습니다. */
  printf("\r\ncounter :");
  for(int i=0; i<MAX_TIMINGS; i++)
  {
    if ( (i >= 4) && (i % 2 == 0) )
    {
      printf(":(%d)",data_cnt[i]);    // HIGH/LOW data
    }else{
      printf(" %d",data_cnt[i]);      // other data (start + Reference)
    }
  }
  printf("\r\n");
  #endif

  /* 총 40 bits (8bit x 5 ) 데이터가 정상적으로 들어왔는지 확인 및 체크섬 검사(CRC), 온습도 데아터 출력 */
  if ( (get_data >= 40) && (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) )
  {

    float h = (float)((data[0] << 8) + data[1]) / 10;

    if ( h > 100 ){

      h = data[0];	// for DHT11
    }
    float c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;

    if ( c > 125 ){

      c = data[2];	// for DHT11
    }

    if ( data[2] & 0x80 ){

      c = -c;
    }

    float f = c * 1.8f + 32;

    printf( "Humidity = %.1f %% Temperature = %.1f *C (%.1f *F)\n", h, c, f );

  }else{
    printf( "CRC  %d:%d | Get data(>40) : %d | ",data[4], ( (data[0] + data[1] + data[2] + data[3]) & 0xFF), get_data );
    printf( "Data not good, skip\n" );
    
  }
}
 
int main(void)
{
  printf( "Raspberry Pi DHT11 temperature/humidity test\n" );

  if (wiringPiSetup() == -1)
  {
    return 1;
  }

  while(1)
  {
    read_dht_data();  // DHT 온습도 센서 데이터 읽기 함수 호출
    delay(2000);    // 다음 읽기까지 2초 지연
  }
 
  return(0);
}