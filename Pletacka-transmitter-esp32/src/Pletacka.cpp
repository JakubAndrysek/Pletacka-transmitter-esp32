#include "Pletacka.hpp"

Pletacka::Pletacka()
{
	Serial.begin(115200);
}

Pletacka::~Pletacka()
{
}

void Pletacka::config(const PletackaConfig config)
{
	cfg = config;
	Serial.begin(115200);

	displayInit(config);
	showId(2);
	showTime();

	pletacka_wifi.init(config);
	if(config.remoteDataOn || config.remoteDebugOn)
	{
		pletacka_debug.init(config);
	}
	
	pletacka_eeprom.begin(50);
	pletacka_status.init(config);

	println("Sensor " + cfg.sensorName + " is configured");
	showMsg("Configured");
}


String Pletacka::isChange()
{
	pletacka_status.getStatus()
}


void Pletacka::debug(String message)
{
	if (cfg.remoteDebugOn)
	{
		pletacka_debug.Debug.print(message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.print("D:"+message);
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
		Serial.println("D:"+message);
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
