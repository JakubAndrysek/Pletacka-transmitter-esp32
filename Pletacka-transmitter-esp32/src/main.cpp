#include <Arduino.h>
#include "pletacka.hpp"

void mainPrograme()
{
	pletackaConfig config;
	delay(500);

	Serial.println("Start");
	config.sensorName = "TestESP";
	config.sensorNumber = 1;
	config.wifiName = "WLOffice";
	config.wifiPassword = "$BlueC6r&R06D";
	pletac.config(config);
	Serial.println("GR");
	
}


void setup() {
	mainPrograme();
}
































void loop() {}