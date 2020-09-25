# raspi-LearningKit  

[라즈베리파이 LearningKit](https://www.eleparts.co.kr/EPXMF7TM)의 예제코드(C언어)가 정리되어 있습니다.  

## C언어 예제 사용을 위한 Wpi설치 및 예제 다운로드/실행 방법  


### C언어 예제 사용을 위한 wirringPi 설치  

라즈베리파이 업데이트  

```bash
sudo apt-get update && sudo apt-get upgrade  
```

예제 실행을 위해서는 wirringPi 라이브러리 설치가 필요합니다.  

소스 관리 툴(git)다운로드 및 WiringPi 설치  

```bash
sudo apt-get install git-core  

git clone https://github.com/WiringPi/WiringPi  
cd WiringPi  
./build  
```

wirringPi 설치 확인 및 GPIO 번호 출력  

```bash
gpio readall  
```

- WiringPi가 공식적으로 지원을 중단함으로 인해 비공식 미러 페이지를 사용합니다.  [(관련 공지 URL)](http://wiringpi.com/wiringpi-deprecated/)  


### 예제파일 다운로드 및 실행  

본 예제 코드는 라즈베리파이의 터미널 환경에서 간단하게 다운로드 및 실행해볼 수 있습니다.  

단, 배선 방법은 각 예제 디렉토리에 있는 이미지 파일(.png)을 참고해 주시면 됩니다.  

```bash
# 예제 저장소 다운로드
git clone https://github.com/eleparts/raspi-LearningKit  
 
cd raspi-LearningKit/  

# 예제 파일 리스트 확인
ls -l  
```  

각 예제 코드는 해당 예제 디렉토리로 이동 후 아래와 같이 컴파일/실행 가능합니다.  

```bash  
# 각 예제 디렉토리로 이동 후 아래 명령어로 컴파일 후 실행해 주시면 됩니다.
gcc -o main [예제 파일명.c] -lwiringPi

sudo ./main
```  

## 참고 사항

PCF8591 ADC 모듈은 외부 ADC신호 입력 외에도 보드 자체에 ADC 입력 소자가 내장되어 있습니다.  

이 입력 신호는 보드에 있는 점퍼를 이용해 연결/제거할 수 있습니다.  
 
PCF8591 입력 채널별로 내장되어있는 소자는 아래와 같습니다.  

| 채널 |   소자   |
|-----|----------|
| 0   | CDS      |
| 1   | 써미스터  | 
| 2   | NC       |
| 3   | 가변저항  |
