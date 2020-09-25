# 25.PCD8544_shield  
  
PCD8544_shild는 라즈베리파이 쉴드 보드로 브레드 보드와 연결된 케이블을 제거 후 라즈베리파이의 GPIO에 바로 연결해 주면 돱니다.  

이때, 보드가 GPIO 1번, 2번 핀(3.3V핀/ 5V핀)위치에서 라즈베리파이를 덮는 방향으로 연결해 주어야 합니다. (반대로 연결하지 않도록 주의)  

## 예제코드 다운로드 및 실행방법  

본 예제는 같이 제공되지 않고 GITHUB에 업로드 되어있는 예제를 다운로드 해 사용합니다.  

[※ 예제 안내 페이지](https://binerry.de/post/25787954149/pcd8544-library-for-raspberry-pi)  

다운로드 및 예제 실행은 아래 명령어를 차례대로 입력 하시면 됩니다.  

```bash  
// 다운로드  
git clone https://github.com/binerry/RaspberryPi  

cd RaspberryPi/libraries/c/PCD8544/samples/  

// 컴파일 (samples의 상위 디렉토리에 있는 PCD8544.c, 헤더(.h)파일 포함 컴파일)  
gcc -o main [예제 파일명.c] ../PCD8544.c -I../ -lwiringPi  

sudo ./main  
```

예제 파일은 총 3개이므로 실제 컴파일 명령어는 아래와 같습니다.  

```bash
gcc -o main1 pcd8544_rpi.c ../PCD8544.c -I../ -lwiringPi  
gcc -o main2 pcd8544_test.c ../PCD8544.c -I../ -lwiringPi  
gcc -o main3 pcd8544_test2.c ../PCD8544.c -I../ -lwiringPi  

// pcd8544_rpi.c 예쩨 실행  
sudo ./main1  

// pcd8544_test.c 예쩨 실행  
sudo ./main2  

// pcd8544_test2.c 예쩨 실행  
sudo ./main3  
```

## PIN map

PCD8544_shield는 라즈베리파이의 GPIO 위에 장착되지만, 실제로 GPIO를 전부 사용하는 것은 아닙니다.  

실제로 사용하는 핀은 아래와 같습니다.  


|   핀 이름   | GPIO 핀 순서 |    BCM 번호    |    Wpi 번호    |
|------------|--------------|----------------|----------------|
| VCC(3.3V)  |       1      |        -       |       -        |
|    GND     |       6      |        -       |       -        |
|    CLK     |      11      |       17       |       0        |
|    DIN     |      12      |       18       |       1        |
|    D/C     |      13      |       27       |       2        |
|    CS      |      15      |       22       |       3        |
|    RST     |      16      |       23       |       4        |


