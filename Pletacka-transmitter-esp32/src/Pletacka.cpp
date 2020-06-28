#include "Pletacka.hpp"

Pletacka::Pletacka()
{
	Serial.begin(115200);
}

Pletacka::~Pletacka()
{
}

void Pletacka::config(const pletackaConfig config)
{
	cfg = config;
	Serial.begin(115200);
		tft.init();
    tft.fontHeight(2);
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
	

	pletacka_wifi.init(config);
	pletacka_debug.init(config);
	pletacka_eeprom.begin(50);
	


	println("Sensor " + cfg.sensorName + " is configured");
	tft.drawString("Configured", tft.width()/4, tft.height() / 2, 4);  //string,start x,start y, font weight {1;2;4;6;7;8}
}

void Pletacka::debug(String message)
{
	if (cfg.remoteDebugOn)
	{
		pletacka_debug.Debug.print(message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.print(message);
	}
}

void Pletacka::debugln(String message)
{
	if (cfg.remoteDebugOn)
	{
		pletacka_debug.Debug.println(message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.println(message);
	}
}

void Pletacka::print(String message)
{
	if (cfg.remoteDataOn)
	{
		pletacka_debug.Data.print(message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.print(message);
	}
}

void Pletacka::println(String message)
{
	if (cfg.remoteDataOn)
	{
		pletacka_debug.Data.println(message);
	}

	if (cfg.serialDataOn)
	{
		Serial.println(message);
	}
}

Pletacka pletacka;
