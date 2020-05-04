#include <Arduino.h>
#include "NetteApi.hpp"
#include <WiFi.h>



#define SSID       "SSID"
#define PASSWORD   "PASSWORD"
#include "credentials.h"

NetteApi addSensor("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/sensors/create");
NetteApi addEvent("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/thisSensor/add-event");

void setup() {
  Serial.begin(115200);

  WiFi.begin(SSID, PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Start");
  auto postReturn = addSensor.PostReqest("{\"number\": \"2\",\"name\": \"Pletacka2\",\"description\": \"Created by ESP32\"}");
  Serial.println("POST return : "+String(postReturn.code)+" ->\""+String(postReturn.main));

}

void loop() {
  auto getReturn = addEvent.GetReqest("Pletacka2/work");
  Serial.println("GET return : "+String(getReturn.code)+" ->\""+String(getReturn.main));

  delay(2000);

  auto getReturn2 = addEvent.GetReqest("Pletacka2/stop");
  Serial.println("GET return : "+String(getReturn2.code)+" ->\""+String(getReturn2.main));

  delay(2000);
}