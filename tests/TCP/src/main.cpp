#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "Technika";
const char* password = "materidouska";

// pokud se nepovede neco inicializovat (WiFi, RGB senzor), program se zasekne v teto funkci
void trap()
{
    Serial.println("trap\n");
    while(1);
}


// kam se ma pripojit WiFi; jmeno site a heslo je v souboru credentials.hpp
WiFiClient debug;
WiFiClient data;
static const IPAddress Debug_IP { 192, 168, 0, 13 };
static const uint16_t Debug_port = 12345;
static const uint16_t Data_port = 12346;


void setup() {
    Serial.begin(115200);

    // Connect to WiFi network
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());



    Serial.println("RBC_sensor_demo\n");
    // inicializace WiFi
    if (!debug.connect(Debug_IP, Debug_port)) {
        Serial.println("Can not connect to the debug server");
        trap();
    }
    if (!data.connect(Debug_IP, Data_port)) {
        debug.println("Can not connect to the data server");
        trap();
    }


    debug.println("Starting main loop\n");
}

int incomingByte = 0; // for incoming serial data

void loop() {
    debug.println(millis()/1000);
    delay(1000);
    data.println("Run");
    if (debug.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}