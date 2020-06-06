#include <Arduino.h>
#include "pletacka.hpp"

void mainPrograme()
{
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
	pletac.config(config);
	
	
}


void setup() {
	mainPrograme();
}
































void loop() {}