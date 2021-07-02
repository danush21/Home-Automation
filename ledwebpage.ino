#include<ESP8266WebServer.h>
#define username "project"
#define password "12345678"
ESP8266WebServer server;

String ledwebpage="<!DOCTYPE html><html><head><title>LED Controller</title><h1><center>LED Controller</center></h1></head><body><form><center><button type=\"submit\" name=\"state\" value=\"0\"><b>LED ON</b><br><br></button><button type=\"submit\" name=\"state\" value=\"1\"><b>LED OFF</b></button></center></form></body></html>";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  WiFi.softAP(username,password);
  Serial.println(" ");
  Serial.println("IP Address ");
  Serial.println("||");
  Serial.println("\\/");
  Serial.println(WiFi.softAPIP());
  server.begin();
  server.on("/led",led);
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void led(){
  server.send(200,"text/html",ledwebpage);
  if((server.arg("state")=="0"))
  {
    digitalWrite(LED_BUILTIN,LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }
}
