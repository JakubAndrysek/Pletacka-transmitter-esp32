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
	config.wifiName = "WLOffice";
	config.wifiPassword = "$BlueC6r&R06D";
	config.apName = "Pletacka-ESP";
	config.apPassword = "PletackaPlete";
	config.wifiDefaulAp = false;
	config.remoteDataOn = true;
	config.remoteDebugOn = true;
	config.serialDebugOn = true;
	
	pletac.config(config);
	
	ota.begin();
	
	
	pletac.println("println");
	pletac.debugln("debugln");

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