# MAX7219 driver 8x8 dot matrix

## 7219matrix.c

C 언어로 구성된 예제 코드입니다.  

실행 전 라즈베리파이 설정 메뉴에서 SPI를 Enable 해 주셔야 합니다.

```bash
gcc -o main 7219matrix.c -lwiringPi  

sudo ./main  
```

위 명령어로 바로 실행 가능합니다.

## GPIO pin-outs

The breakout board has an two headers to allow daisy-chaining:  

| Board Pin | Name | Remarks | RPi Pin | RPi Function (#BCM) |
|--------:|:-----|:--------|--------:|--------------|
| 1 | VCC | +5V Power | 2, 4 | 5V0 |
| 2 | GND | Ground | 6 | GND |
| 3 | DIN | Data In | 19 | GPIO 10 (MOSI) |
| 4 | CS | Chip Select | 24 | GPIO 8 (SPI CS0) |
| 5 | CLK | Clock | 23 | GPIO 11 (SPI CLK) |
  
  
## 추가 python 예제  

luma.led_matrix 라이브러리를 이용해 제어해 줍니다.  


```bash
git clone https://github.com/rm-hull/luma.led_matrix  

cd luma.led_matrix  

sudo python3 setup.py install  

sudo python3 examples/matrix_demo.py  
```

만약 아래와 같은 에러 메세지가 출력되는 경우  

```
  File "/usr/local/lib/python3.7/dist-packages/luma.core-1.16.1-py3.7.egg/luma/core/interface/serial.py", line 289, in __init__  
    self._spi.cshigh = cs_high
```
위 에러 메세지 경로의 serial.py 파일의 line 번호(=289)를 주석처리 해 준 뒤 실행해 주시면 됩니다.  

```bash
sudo nano /usr/local/lib/python3.7/dist-packages/luma.core-1.16.1-py3.7.egg/luma/core/interface/serial.py

> line 289
#  self._spi.cshigh = cs_high

```