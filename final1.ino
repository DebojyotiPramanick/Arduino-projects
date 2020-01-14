#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


String str;
const char* ssid = "SANJOY WIFI";
const char* pass = "sanj1972";
int relayInput1= D0;
int relayInput2= D1;
int relayInput3= D2;
int relayInput4= D3;
int relayInput5= D4;
int relayInput6= D5;


ESP8266WebServer server(80);

void handleRoot() {
  char temp[400];
  snprintf(temp, 400,
    "<html>\\
  <head>\
  </head>\
    <body>\
    <h1><b>HOME AUTOMATION</b></h1>\
    <h4>led1</h4>\
    <a href =\"/1\"> <button> Turn ON</button> </a>\
    <a href =\"/0\"> <button> Turn OFF</button> </a>\
    <h4>led2</h4>\
    <a href =\"/2\"> <button> Turn ON</button> </a>\
    <a href =\"/3\"> <button> Turn OFF</button> </a>\
    <h4>led3</h4>\
    <a href =\"/4\"> <button> Turn ON</button> </a>\
    <a href =\"/5\"> <button> Turn OFF</button> </a>\
  </body>\
</html>");
  server.send(200, "text/html", temp);

}


void ledOn() {
  server.send(200,"text/plain", "led 1 turned on");
  pinMode(relayInput1, OUTPUT);
  digitalWrite(relayInput1, LOW);
  pinMode(relayInput4,OUTPUT);
  digitalWrite(relayInput4,HIGH);
  }
void ledOff() {
  server.send(200,"text/plain", "led 1 turned off");
  pinMode(relayInput1, OUTPUT);
  digitalWrite(relayInput1, HIGH);
  pinMode(relayInput4,OUTPUT);
  digitalWrite(relayInput4,HIGH);
}
void ledOn2() {
  server.send(200,"text/plain", "led 2 turned on");
  pinMode(relayInput2, OUTPUT);
  digitalWrite(relayInput2, LOW);
  pinMode(relayInput5,OUTPUT);
  digitalWrite(relayInput5,HIGH);
  
}
void ledOff2() {
  server.send(200,"text/plain", "led 2 turned off");
  pinMode(relayInput2, OUTPUT);
  digitalWrite(relayInput2, HIGH);
  pinMode(relayInput5,OUTPUT);
  digitalWrite(relayInput5,HIGH);
  
}
void ledOn3() {
  server.send(200,"text/plain", "led 3 turned on");
  pinMode(relayInput3, OUTPUT);
  digitalWrite(relayInput3, LOW);
  pinMode(relayInput6,OUTPUT);
  digitalWrite(relayInput6,HIGH);
  
}
void ledOff3() {
  server.send(200,"text/plain", "led 3 turned off");
  pinMode(relayInput3, OUTPUT);
  digitalWrite(relayInput3, HIGH);
  pinMode(relayInput6,OUTPUT);
  digitalWrite(relayInput6,HIGH);
  
  }


void setup() {
  pinMode(relayInput4, OUTPUT);
  digitalWrite(relayInput4,LOW);
  pinMode(relayInput5, OUTPUT);
  digitalWrite(relayInput5,LOW);
  pinMode(relayInput6, OUTPUT);
  digitalWrite(relayInput6,LOW);
  pinMode(relayInput1, OUTPUT);
  digitalWrite(relayInput1,HIGH);
  pinMode(relayInput2, OUTPUT);
  digitalWrite(relayInput2,HIGH);
  pinMode(relayInput3, OUTPUT);
  digitalWrite(relayInput3,HIGH);
   Serial.begin(9600);
    Serial.print("Connecting to network");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);   // Connect to WiFi network

  while (WiFi.status() != WL_CONNECTED) {    // Wait for connection
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/0", ledOff);
  server.on("/1", ledOn);
    server.on("/3", ledOff2);
  server.on("/2", ledOn2);
    server.on("/5", ledOff3);
  server.on("/4", ledOn3);

  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
   server.handleClient();
   WiFiClient client;
   HTTPClient http;  
    
}
