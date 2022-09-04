#include <curl/curl.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/common.h"

int main(int argc, char** argv) {
    
    CURL *curl;
    CURLcode res;
    curl=curl_easy_init();
	

    using namespace std;
    using namespace HX711;

    const char* const err = "Usage: [DATA PIN] [CLOCK PIN] [REFERENCE UNIT] [OFFSET]";

    if(argc != 5) {
        cerr << err << endl;
        return EXIT_FAILURE;
    }


    const int dataPin = stoi(argv[1]);
    const int clockPin = stoi(argv[2]);
    const int refUnit = stoi(argv[3]);
    const int offset = stoi(argv[4]);

    SimpleHX711 hx(dataPin, clockPin, refUnit, offset);
       //위에까진 전부 로드셀 작동 부분
       // 텍스트로 100그램 마다 추가해서 %별로 텍스트 보내기 추가
  
       
        const Mass m = hx.weight(3); 
         cout << "\t" << m.toString(Mass::Unit::KG) << '\n' << endl;
        if(m.getValue() > 1000){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"full\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        }
        else  if(m.getValue() < 100 && m.getValue() >0){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"empty\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 200 && m.getValue() >101){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"empty\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 300 && m.getValue() >201){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"20%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 400 && m.getValue() >301){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"30%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        }else if(m.getValue() < 500 && m.getValue() >401){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"40%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 600 && m.getValue() >501){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"50%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        }else if(m.getValue() < 700 && m.getValue() >601){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"60%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 800 && m.getValue() >701){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"70%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 900 && m.getValue() >801){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"80%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        } else if(m.getValue() < 999 && m.getValue() >901){
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_URL, "http://203.253.128.177:7579/Mobius/svm/loadcell");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
            struct curl_slist *headers=NULL;
            headers=curl_slist_append(headers, "Accept: application/json");
            headers=curl_slist_append(headers, "X-M2M-RI: 12345");
            headers=curl_slist_append(headers, "X-M2M-Origin: SRbNvHJ_Hzz");
            headers=curl_slist_append(headers, "Content-Type: application/vnd.onem2m-res+json; ty=4");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            const char *data="{\n    \"m2m:cin\": {\n        \"con\": \"90%\"\n    }\n}";
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            res=curl_easy_perform(curl);
            
        }
       
         

    

    return EXIT_SUCCESS;

}
// 코드 실행방법
 // g++ -Wall -o prog SimpleHX711Test.cpp -lhx711 -llgpio -lcurl

 // ./prog 13 19 -370 -367471