#include <Arduino.h>
//#include "D:\\software\\Arduino\\libraries\\Servo\\src\\Servo.h"
#include "Servo.h"
#include "wifi.h"
#include "steergear.h"

void wifiControl(String mes);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    while(!Serial){
        Serial.print(".");
        delay(500);
    }
    Serial.println("start");
    WiFiInit();
    pinMode(LED_BUILTIN, OUTPUT);
    steergearInite();


}

void loop() {
    centerPoint();
    // if((char)Serial.read()=='y')
    // {
    //     while (true)
    //     {
    //         /* code */
    //         orderControl();
    //     }
        
    // }
    
    // put your main code here, to run repeatedly:
    String mes;
    //connect_client("data",'s');
    mes=WiFiReceive();
    wifiControl(mes);
    //Serial.print(mes);
    //所有的运行程序在下面if的程序模块内
    //
    //mes=Serial.read();
    if(mes.length()<=1){
        //Serial.println(mes.length());
        //Serial.println(mes);
        //Serial.println("无数据");
    }
    else{
        
        Serial.println(mes);
        Serial.println("有数据");
        if(mes=="WW"){
            steergear_control('w');
        }
        else if(mes=="SS"){
            steergear_control('s');
        }
        else if(mes=="AA"){
            steergear_control('a');
        }
        else if(mes=="DD"){
            steergear_control('d');
        }
    }
}

void wifiControl(String mes){
    if(mes.length()<=1){
        //Serial.println(mes.length());
        //Serial.println(mes);
        //Serial.println("无数据");
    }
    else{
        
        Serial.println(mes);
        Serial.println("有数据");
        if(mes=="WW"){
            steergear_control('w');
        }
        else if(mes=="SS"){
            steergear_control('s');
        }
        else if(mes=="AA"){
            steergear_control('a');
        }
        else if(mes=="DD"){
            steergear_control('d');
        }
    }
}

