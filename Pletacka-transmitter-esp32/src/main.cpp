/**
 * @file main.cpp
 * @author Jakub Andrýsek (email@kubaandrysek.cz)
 * @brief 
 * @version 0.1
 * @date 2020-08-14
 * 
 * @copyright Copyright (c) 2020 Jakub Andrýsek
 * 
 * @link https://kubaandrysek.cz
 */
#include <Arduino.h>
#include "pletacka.hpp"
#include "BasicOTA.hpp"
#include <SPI.h>
#include "WiFi.h"
#include "ArduinoMetronome.hpp"


#define ADC_EN          14
#define ADC_PIN         34
#define BUTTON_1        35
#define BUTTON_2        0 



void mainPrograme()
{
	//Main setup

	BasicOTA ota;
	PletackaConfig config;
	ArduinoMetronome statusMetronome(1000);

	
	
	// delay(2000);

	Serial.println("Start");
	config.sensorName = "TestESP";
	config.sensorNumber = 1;
	config.wifiName = "Pletacka-IoT";
	config.wifiPassword = "PletackaPlete";
	config.wifiDefaulAp = false;
	config.apName = "AP-Pletacka-ESP";
	config.apPassword = "PletackaPlete";
	config.remoteDataOn = true;
	config.remoteDebugOn = true;
	config.serialDebugOn = true;
	config.debugIP = "192.168.0.113";
	config.debugPort = 12346;
	config.dataPort = 12345;

	config.pinFinish = 26;
	config.pinStop = 27;
	
	pletacka.config(config);

	

	
	ota.begin();
	
	
	pletacka.println("println");
	pletacka.debugln("debugln");

    
    Serial.println("Start");
	pletacka.debug("DEBUG");
	Serial.println("SNL");
	pletacka.debugln("DEBUGLN");
	pletacka.debugln("DEBUGLN2");
	Serial.println("SNL2");
	


	//Main loop
	while (true)
	{
		ota.handle();

		if(statusMetronome.loopMs())
		{
			pletacka.println(pletacka.isChange());
		}
		
	}
	
	
	
}



void setup() {
	mainPrograme();
}











void loop() {}