#include <Arduino.h>
#include "pletacka.hpp"
#include "BasicOTA.hpp"

void mainPrograme()
{
	//Main setup

	BasicOTA ota;
	pletackaConfig config;
	delay(2000);

	Serial.println("Start");
	config.sensorName = "TestESP";
	config.sensorNumber = 1;
	config.wifiName = "Pletacka-IoT";
	config.wifiPassword = "PletackaPlete";
	config.apName = "Pletacka-ESP";
	config.apPassword = "PletackaPlete";
	config.wifiDefaulAp = false;
	config.remoteDataOn = true;
	config.remoteDebugOn = true;
	config.serialDebugOn = true;
	config.debugIP = "192.168.0.23";
	config.debugPort = 12345;
	config.dataPort = 12346;
	
	pletacka.config(config);
	
	ota.begin();
	
	
	pletacka.println("println");
	pletacka.debugln("debugln");

	//Main loop
	while (true)
	{
		ota.handle();
		// pletac.debugln(String(millis()/1000));
		// delay(1000);
	}
	
	
	
}


void setup() {
	mainPrograme();
}


















void loop() {}