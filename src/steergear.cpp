#include "steergear.h"
#include<string.h>
#define INIT_1 90
#define INIT_2 90
int pos_1=0;//前后
int pos_2=0;//左右
Servo myservo_1;
Servo myservo_2;
void steergearInite(){
    myservo_1.attach(9);//D8
    myservo_2.attach(10);//D9
    //myservo_1.write(INIT_1);
    //myservo_2.write(INIT_2);
    Serial.println("steergear has init");
    pos_1 = myservo_1.read();
    pos_2 = myservo_2.read();
    Serial.print("x: ");
    Serial.println(pos_1);
    Serial.print("y: ");
    Serial.println(pos_2);
}

void steergear_control(char state){
    if(state=='w'){
        if(pos_1==180){
            pos_1=180;
            myservo_1.write(pos_1);
        }
        else{
            pos_1++;
            myservo_1.write(pos_1);
        }
    }
    else if(state=='s'){
        if(pos_1==0){
            pos_1=0;
            myservo_1.write(pos_1);
        }
        else{
            pos_1--;
            myservo_1.write(pos_1);
        }
    }
    else if(state=='a'){
        if(pos_2==180){
            pos_2=180;
            myservo_2.write(pos_2);
        }
        else{
            pos_2++;
            myservo_2.write(pos_2);
        }
    }
    else if(state=='d'){
        if(pos_2==0){
            pos_2=0;
            myservo_2.write(pos_2);
        }
        else{
            pos_2--;
            myservo_1.write(pos_2);
        }
    }
    std::string pos_1_str=std::to_string(pos_1);
    Serial.print("pos_1:");
    Serial.println(pos_1);
    Serial.print("pos_2:");
    Serial.println(pos_2);

    //char* steergear_Data=char(pos_1)+" "+char(pos_2);
    //connect_client(steergear_Data,'s');
}

void orderControl(){
    myservo_1.write(INIT_1+10);
    delay(500);
    myservo_2.write(INIT_2+10);
    delay(500);
    myservo_1.write(INIT_1-10);
    delay(500);
    myservo_2.write(INIT_2-10);
    delay(500);
    myservo_1.write(INIT_1-10);
    delay(500);
    myservo_2.write(INIT_2-10);
    delay(500);
    myservo_1.write(INIT_1+10);
    delay(500);
    myservo_2.write(INIT_2+10);
    delay(500);
}

void centerPoint(){
    myservo_1.write(INIT_1);
    myservo_2.write(INIT_2);
}