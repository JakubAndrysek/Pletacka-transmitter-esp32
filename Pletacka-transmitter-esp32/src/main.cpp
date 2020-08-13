








#include <Arduino.h>
#include "pletacka.hpp"
#include "BasicOTA.hpp"
#include <SPI.h>
#include "WiFi.h"


// #ifndef TFT_DISPOFF
// #define TFT_DISPOFF 0x28
// #endif

// #ifndef TFT_SLPIN
// #define TFT_SLPIN   0x10
// #endif

#define ADC_EN          14
#define ADC_PIN         34
#define BUTTON_1        35
#define BUTTON_2        0 



void mainPrograme()
{
	//Main setup

	BasicOTA ota;
	PletackaConfig config;	
	
	// delay(2000);

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
	config.debugIP = "192.168.0.113";
	config.debugPort = 12345;
	config.dataPort = 12346;

	config.pinFinish = 26;
	config.pinStop = 27;
	
	pletacka.config(config);

	
	ota.begin();
	
	
	pletacka.println("println");
	pletacka.debugln("debugln");

    Serial.begin(115200);
    Serial.println("Start");


	//Main loop
	while (true)
	{
		ota.handle();
		// pletacka.debugln(String(millis()/1000));
		pletacka.println(pletacka.isChange());
		delay(10);
	}
	
	
	
}



void setup() {
	mainPrograme();
	
}











void loop() {}