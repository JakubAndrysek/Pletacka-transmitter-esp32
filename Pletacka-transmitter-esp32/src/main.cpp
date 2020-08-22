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
#include "Pletacka.hpp"
#include "BasicOTA.hpp"
#include <SPI.h>
#include "WiFi.h"
#include "ArduinoMetronome.hpp"






void mainPrograme()
{
	//Main setup

	// BasicOTA ota;
	PletackaConfig config;
	ArduinoMetronome statusMetronome(10);
	ArduinoMetronome customMetronome(5000);
	ArduinoMetronome timeMetronome(1000);

	
	
	// delay(2000);

	Serial.println("Start");
	config.sensorName = "TestESP";
	config.sensorNumber = 30;
	config.serverUrl = "http://192.168.0.172/api/v1/thisSensor/add-event";
	config.wifiName = "Pletacka-IoT";
	config.wifiPassword = "PletackaPlete";
	config.wifiDefaulAp = false;
	config.apName = "AP-Pletacka-ESP";
	config.apPassword = "PletackaPlete";
	config.remoteDataOn = false;
	config.remoteDebugOn = false;
	config.serialDebugOn = true;
	config.debugIP = "192.168.0.113";
	config.debugPort = 12346;
	config.dataPort = 12345;

	config.pinFinish = 26;
	config.pinStop = 27;
	
	pletacka.config(config);

	

	
	// ota.begin();
	
	
	pletacka.println("println");
	pletacka.debugln("debugln");



	//Main loop
	while (true)
	{
		// ota.handle();

		int start = 0;

		if(statusMetronome.loopMs())
		{
			String status = "";
			if((status = pletacka.isChange())!= "")
			{
				start = millis();
				pletacka.println("Status: " + status);
				pletacka.showStatus(status);
				pletacka.sendState(status);
				// pletacka.showSend();
			}

			// if(millis()-start > 1000)
			// {
			// 	pletacka.tft.fillCircle(195, 55, 15, TFT_TRANSPARENT);
			// }
			
		}

		if(timeMetronome.loopMs())
		{			
			pletacka.showTime();
		}


		if(customMetronome.loopMs())
		{			
			
		}
		
	}
	
	
	
}



void setup() {
	mainPrograme();
}











void loop() {}