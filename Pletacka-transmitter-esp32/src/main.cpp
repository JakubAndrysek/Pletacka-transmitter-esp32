#include <Arduino.h>
#include "pletacka.hpp"

void mainPrograme()
{
	pletackaConfig config;

	config.sensorName = "TestESP";
	config.sensorNumber = 1;
	pletac.config(config);
	
}


void setup() {
	mainPrograme();
}
































void loop() {}