# 18. IR-remote  

IR 리모컨은 적외선 파장을 송신, IR 수신기에서 해당 파장을 받아 데이터 화 해 줍니다.  

IR수신기에서 받는 입력 신호는 us(마이크로 초) 단위의 매우 빠른 HIGH/LOW신호의 반복으로 HIGH신호 대비 LOW 신호의 길이에 따라 데이터를 1 혹은 0으로 결정해 줄 수 있습니다.  

## ir-remote.c  

아래 명령어로 바로 실행 가능합니다.  

```bash
gcc -o main ir-remote.c -lwiringPi

sudo ./main 
```
출력 데이터는 4byte 값이며, 버튼 입력 시간에 따라 '+' 기호가 추가로 출력됩니다.


※ 본래 아래 lirc 사용을 권장하나 lirc가 최신 라즈베리파이 커널에서 문제가 있어 대신 사용 가능한 예제입니다.  

## lirc 사용하기

LIRC = [Linux Infrared Remote Control](https://www.lirc.org/)  

lirc 설치  
```bash
sudo apt-get install lirc liblircclient-dev
```

사용 전 설정 (각 디렉토리의 파일에 내용을 추가)  

```bash
sudo nano /boot/config.txt
# 아래 내용을 추가해 줍니다. - BCM GPIO 18 (#18) 핀을 입력으로 사용
dtoverlay=gpio-ir,gpio_pin=18


sudo nano /etc/lirc/lirc_options.conf
# 아래 내용으로 수정해 줍니다.
driver = default
device = /dev/lirc0
```

실행 테스트 (리모컨 데이터 수신)  
```bash
sudo mode2 -d /dev/lirc0
```
위 mode2 실행 시 입력되는 HIGH 및 LOW 의 길이가 출력됩니다.  
(pulse : HIGH 시간, space : LOW 시간)  

※ 참조 : 데이터 사용 라이브러리 사용불가 문제  
irrecord 문제(lirc_dev -> gpio-ir 변경 및 사용법 변경으로 인한 문제 등.)  
https://www.raspberrypi.org/forums/viewtopic.php?f=28&t=235256
