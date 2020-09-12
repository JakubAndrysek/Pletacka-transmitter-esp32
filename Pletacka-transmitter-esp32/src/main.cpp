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
#include "Board_tester.hpp"






void mainPrograme()
{
	//Main setup

	// BasicOTA ota;
	PletackaConfig config;
	ArduinoMetronome statusMetronome(10);
	ArduinoMetronome customMetronome(1000);
	ArduinoMetronome timeMetronome(1000);
	ArduinoMetronome wifiTester(500);


	

	
	
	// delay(2000);

	Serial.println("Start");
	config.sensorNumber = 30;
	config.serverUrl = "http://192.168.0.172/api/v1/thisSensor/add-event";
	config.wifiName = "Pletacka-IoT";
	config.wifiPassword = "PletackaPlete";
	// config.wifiName = "Technika";
	// config.wifiPassword = "materidouska";
	config.wifiDefaulAp = false;
	config.apName = "AP-Pletacka-" + config.sensorNumber;
	config.apPassword = "PletackaPlete";
	config.remoteDataOn = false;
	config.remoteDebugOn = false;
	config.serialDebugOn = true;
	config.debugIP = "192.168.0.113";
	config.debugPort = 12346;
	config.dataPort = 12345;
	
	pletacka.config(config);

	statusMetronome.startupDelayMs(3000);
	wifiTester.startupDelayMs(3000);

	// Board_tester tester;
	// tester.test();

	

	
	// ota.begin();
	
	
	pletacka.println("println");
	pletacka.debugln("debugln");


	int ledSend = 0;
	bool ledWifiState = false;

	//Main loop
	while (true)
	{
		// ota.handle();

		

		if(statusMetronome.loopMs())
		{
			
			String status = "";
			if((status = pletacka.isChange())!= "")
			{
				ledSend = millis();
				digitalWrite(LED_SEND, true);
				pletacka.println("Status: " + status);
				pletacka.showStatus(status);
				pletacka.sendState(status);
				
			}

			if(millis()-ledSend > 700)
			{
				digitalWrite(LED_SEND, false);
			}

			
		}

		if(timeMetronome.loopMs())
		{			
			pletacka.showTime();
		}


		if(customMetronome.loopMs())
		{			
			// Serial.println("START: " + String(start));
		}
		
		if(wifiTester.loopMs())
		{			
			if(WiFi.status() != WL_CONNECTED)
			{
				digitalWrite(LED_WIFI, ledWifiState);
				ledWifiState = !ledWifiState;
				pletacka.showError("Not connected to WiFi"); 
				pletacka.showMsg("WiFi ERROR");
				delay(2000);
				pletacka.showStatus("RESTART...");
				delay(3000);
				ESP.restart(); 
			}
		}
		
	}
	
	
	
}



void setup() {
	mainPrograme();
}











void loop() {}