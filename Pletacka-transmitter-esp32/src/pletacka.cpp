#include "pletacka.hpp"

pletacka::pletacka()
{
    Serial.begin(115200);
}

pletacka::~pletacka()
{
}

void pletacka::config(const pletackaConfig config)
{
    cfg = config;
    Serial.begin(115200);
    pWifi.init(config);
    pDebug.init(config); 
	pEeprom.init(config);
	pletac.println("Sensor "+cfg.sensorName+ " is configured");   
}

void pletacka::debug(String message)
{
	if(cfg.remoteDebugOn)
	{
		pDebug.Debug.print(message);
	}

	if(cfg.serialDebugOn)
	{
		Serial.print(message);
	}
	
}

void pletacka::debugln(String message)
{
	if(cfg.remoteDebugOn)
	{
		pDebug.Debug.println(message);
	}

	if(cfg.serialDebugOn)
	{
		Serial.println(message);
	}
}

void pletacka::print(String message)
{
	if(cfg.remoteDataOn)
	{
		pDebug.Data.print(message);
	}

	if(cfg.serialDebugOn)
	{
		Serial.print(message);
	}
	
}

void pletacka::println(String message)
{
	if(cfg.remoteDataOn)
	{
		pDebug.Data.println(message);
	}

	if(cfg.serialDataOn)
	{
		Serial.println(message);
	}
	
}

pletacka pletac;