#include<curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include<unistd.h>
#include<wiringPi.h>
#define PWM 18
#include <softPwm.h>    // software 로 PWM 제어를 할 수 있는 API 사용하기 위함
#define GAP 4900
#define quake_pin 23

int main() {

    CURL *curl;
    CURLcode res;
    curl=curl_easy_init();

    wiringPiSetupGpio();
    if(wiringPiSetup()==-1) // wiringPi 초기화 

        {

        return 0;
    }

    softPwmCreate(PWM, 0, 1024);
    // 위까지 모터부분
    // 밑은 진동센서부분
    unsigned int quake_count=0;
    pinMode (quake_pin, INPUT);
    unsigned int prev_time;
    unsigned int cur_time;
    prev_time=millis();
    cur_time=millis();

    for(;;) {
         cur_time=millis();

      if(digitalRead(quake_pin)==0) {           // 진동 감지시 카운트 1증가
         quake_count++;
      }
        if(cur_time-prev_time > GAP){
            printf("현재 진동수 : %d\n",quake_count);
            if(quake_count <4) {
            
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/vibration");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"0\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);

            }
            if(quake_count >4) {
                printf ("진동이 많이 감지되었습니다 사진을 촬영합니다.\n");
                softPwmWrite(PWM, 13); //  duty 5ms 로 PWM 발생
        
                delay(30);
                system("raspistill -vf -q 20 -o 1.jpeg -w 1920  -h 1080"); //침입자 사진 촬영
                printf ("촬영 완료.\n");
                softPwmWrite(PWM, 25); //  duty 25ms 로 PWM 발생
                delay(50);


                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
                curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/vibration");
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
                struct curl_slist *headers=NULL;
                headers=curl_slist_append(headers, "Accept: application/json");
                headers=curl_slist_append(headers, "X-M2M-RI: 12345");
                headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
                headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
                const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"1\"\n    }\n}";
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
                res=curl_easy_perform(curl);
            
            

        }
         prev_time=millis();
         quake_count=0;
        
        }
        delay(2);


    }

    return 0;

}
// gcc testnode.c -o project -lcurl -lwiringPi 
// ./project
