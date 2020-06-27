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
	pletacka_wifi.init(config);
	pletacka_debug.init(config);
	pletacka_eeprom.init(config);
	pletacka.println("Sensor " + cfg.sensorName + " is configured");
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