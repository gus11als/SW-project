#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<iomanip>
#include<unistd.h>
#include<wiringPi.h>
using namespace std;
int input_second = 10;
double current_second = 0;


int main() {
    while(1) {
        for(current_second; current_second < input_second; current_second+=0.1) {    //10초 카운트다운 반복문
            cout << input_second - current_second << endl;
            delay(100);

        }

        system("raspistill -o test%04d.jpg -q 70 -w 320 -h 240"); //위 10초가 지나면 사진촬영
        cout << "내부 사진 촬영 완료"<< endl;
        current_second=0;
        
    }
    return 0;
}