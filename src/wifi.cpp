#include "wifi.h"

char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
WiFiServer server(100);
WiFiClient client;
int status=WL_IDLE_STATUS;
void showstring(char* buffer,int countnum);
void WiFiInit(){
    Serial.println("Ready to connect...");
    WiFi.begin(ssid,pass);
    
    while (WiFi.status()!=WL_CONNECTED)
    {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("wifi has connected");
    Serial.print("ssid:");
    Serial.println(WiFi.SSID());
    Serial.print("ip:");
    Serial.println(WiFi.localIP());
    server.begin();
    return;
}

String WiFiReceive(){
    char message;
    char buffer[99];
    int countnum=0;
    String mes;
    String s;
    // if (status != WiFi.status()) {
    // // it has changed update the variable
    //     status = WiFi.status();
    //     if (status == WL_CONNECTED) {
    //   // a device has connected to the AP
    //         Serial.println("Device connected to AP");
    //     } 
    //     else {
    //     // a device has disconnected from the AP, and we are back in listening mode
    //         Serial.println("Device disconnected from AP");
    //         return mes;
    //     }
    // }
    
    client=server.available();
    //Serial.println(client);
    // if(!client){
    //     Serial.println("client is not available");
    //     return mes;
    // }
    while(client.connected()){
        if(client.available()){
            message=client.read();
            
            //*(buffer+countnum)=message;
            buffer[countnum]=message;
            
            if(message=='\n'){
                break;
            }
            countnum++;
            delayMicroseconds(100);
        }
    }
    char* string_buffer=new char[countnum];
    for(int j=0;j<countnum;j++){
        *(string_buffer+j)=buffer[j];
    }
    showstring(string_buffer,countnum);
    mes=string_buffer;
    delete[] string_buffer;
    return mes;
}

void showstring(char* buffer,int countnum){
    for(int i=0;i<countnum;i++){
        Serial.print(*(buffer+i));
        if(i==countnum-1){
            Serial.print("\n");
        }
    }
}