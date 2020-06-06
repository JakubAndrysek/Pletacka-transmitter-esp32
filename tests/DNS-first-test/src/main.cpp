#include <Arduino.h>
#include <WiFi.h>
#include "BasicOTA.hpp"
#include <ESPmDNS.h>
#include <WiFiClient.h>


#define SSID       "SSID"
#define PASSWORD   "PASSWORD"
#include "credentials.h"

BasicOTA OTA;
WiFiServer server(80);


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

  if (!MDNS.begin("esp32")) {
  Serial.println("Error setting up MDNS responder!");
  while(1) {
  delay(500);
   Serial.print(".");
  }
  }
  MDNS.addService("http", "tcp", 80); 

  Serial.println("Start - 1");

  OTA.begin();
}

void loop() {

  OTA.handle();
}





/*
  ESP32 mDNS responder sample
  This is an example of an HTTP server that is accessible
  via http://esp32.local URL thanks to mDNS responder.
  Instructions:
  - Update WiFi SSID and password as necessary.
  - Flash the sketch to the ESP32 board
  - Install host software:
    - For Linux, install Avahi (http://avahi.org/).
    - For Windows, install Bonjour (http://www.apple.com/support/bonjour/).
    - For Mac OSX and iOS support is built in through Bonjour already.
  - Point your browser to http://esp32.local, you should see a response.
//  */

// #include <Arduino.h>

// #include <WiFi.h>
// #include <ESPmDNS.h>
// #include <WiFiClient.h>

// #define SSID       "Technika"
// #define PASSWORD   "materidouska"


// // // TCP server at port 80 will respond to HTTP requests
// // WiFiServer server(80);

// void setup(void)
// {  
//     Serial.begin(115200);

//     // Connect to WiFi network
//     WiFi.begin(SSID, PASSWORD);
//     Serial.println("");

//     // Wait for connection
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(500);
//         Serial.print(".");
//     }
//     Serial.println("");
//     Serial.print("Connected to ");
//     Serial.println(SSID);
//     Serial.print("IP address: ");
//     Serial.println(WiFi.localIP());

//     if (!MDNS.begin("esp32")) {
//         Serial.println("Error setting up MDNS responder!");
//         while(1) {
//             delay(1000);
//         }
//     }
//     MDNS.addService("http", "tcp", 80);
// }

// void loop(void)
// {
//     // // Check if a client has connected
//     // WiFiClient client = server.available();
//     // if (!client) {
//     //     return;
//     // }
//     // Serial.println("");
//     // Serial.println("New client");

//     // // Wait for data from client to become available
//     // while(client.connected() && !client.available()){
//     //     delay(1);
//     // }

//     // // Read the first line of HTTP request
//     // String req = client.readStringUntil('\r');

//     // // First line of HTTP request looks like "GET /path HTTP/1.1"
//     // // Retrieve the "/path" part by finding the spaces
//     // int addr_start = req.indexOf(' ');
//     // int addr_end = req.indexOf(' ', addr_start + 1);
//     // if (addr_start == -1 || addr_end == -1) {
//     //     Serial.print("Invalid request: ");
//     //     Serial.println(req);
//     //     return;
//     // }
//     // req = req.substring(addr_start + 1, addr_end);
//     // Serial.print("Request: ");
//     // Serial.println(req);

//     // String s;
//     // if (req == "/")
//     // {
//     //     IPAddress ip = WiFi.localIP();
//     //     String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
//     //     s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>Hello from ESP32 at ";
//     //     s += ipStr;
//     //     s += "</html>\r\n\r\n";
//     //     Serial.println("Sending 200");
//     // }
//     // else
//     // {
//     //     s = "HTTP/1.1 404 Not Found\r\n\r\n";
//     //     Serial.println("Sending 404");
//     // }
//     // client.print(s);

//     // client.stop();
//     // Serial.println("Done with client");
// }