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
	ArduinoMetronome aliveMetronome(10000);

	
	
	// delay(2000);

	Serial.println("Start");
	// config.sensorNumber = 14; //Number from 1 to 254
	// config.serverUrl = "http://192.168.0.172/api/v1/thisSensor/add-event";
	// config.serverUrl = "http://192.168.0.113/Pletacka-website/api/v1/thisSensor/add-event";
	config.serverUrl = "http://192.168.0.2/api/v1/thisSensor/add-event";
	// config.wifiName = "Pletacka-IoT";
	// config.wifiPassword = "PletackaPlete";
	config.wifiName = "WLRotex";
	config.wifiPassword = "$BlueC6r&R06D";	
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
	config.udpIP = "192.168.0.2";
	config.udpPort = 2727;

	
	pletacka.config(&config);
	

	statusMetronome.startupDelayMs(15000);
	aliveMetronome.startupDelayMs(1000);
	timeMetronome.startupDelayMs(1000);
	wifiTester.startupDelayMs(3000);

	// Board_tester tester;
	// tester.test();

	

	
	// ota.begin();
	
	
	pletacka.println("println");
	pletacka.debugln("debugln");


	int ledSend = 0;
	bool ledWifiState = false;
	int startAlive = 0;

	//Main loop
	while (true)
	{
		// ota.handle();

		
		//	Status loop
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

		//	Show time loop
		if(timeMetronome.loopMs())
		{			
			pletacka.showTime();
		}

		//	Send alive loop
		if(aliveMetronome.loopMs())
		{			
			startAlive = millis();
			pletacka.sendAlive(config.sensorNumber);
			digitalWrite(LED_ON, true);
		}


		if(millis()-startAlive > 800)
		{
			digitalWrite(LED_ON, false);
		}
		
		//	WiFi connection test loop
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



		//	 Custom loop
		if(customMetronome.loopMs())
		{			
			// Serial.println("START: " + String(start));
		}		
		
	}
	
	
	
}



void setup() {
	mainPrograme();
}











void loop() {}