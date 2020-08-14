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

	pinMode(BUTTON_1, INPUT);
	
	

	pletacka_wifi.init(config);
	if(config.remoteDataOn || config.remoteDebugOn || !digitalRead(BUTTON_1))
	{
			println("STARTING DEBUG MODE");
			showError("DEBUG MODE", TFT_ORANGE);
			pletacka_debug.init(config);
	}
	
	pletacka_eeprom.begin(50);
	pletacka_status.init(config);

	delay(200); //required for succes behavour
	timeInit();

	println("Sensor " + cfg.sensorName + " is configured");
	
	
}

/**
 * @brief Is pletacka status changed
 * 
 * @return String status or false
 */
String Pletacka::isChange()
{
	static String lastStatus = "";
	String nowStatus = pletacka_status.getStatus();

	// Serial.println("NowS:"+nowStatus);

	if(nowStatus != lastStatus)
	{
		lastStatus = nowStatus;
		return nowStatus;
	}

	return "";
}


void Pletacka::debug(String message, String prefix)
{
	if (cfg.remoteDebugOn)
	{
		pletacka_debug.Debug.print(prefix + message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.print(prefix + message);
	}
}

void Pletacka::debugln(String message, String prefix)
{
	if (cfg.remoteDebugOn)
	{
		pletacka_debug.Debug.println(prefix + message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.println(prefix + message);
	}
}

void Pletacka::print(String message, String prefix)
{
	if (cfg.remoteDataOn)
	{
		pletacka_debug.Data.print(prefix + message);
	}

	if (cfg.serialDebugOn)
	{
		Serial.print(prefix + message);
	}
}

void Pletacka::println(String message, String prefix)
{
	if (cfg.remoteDataOn)
	{
		pletacka_debug.Data.println(prefix + message);
	}

	if (cfg.serialDataOn)
	{
		Serial.println(prefix + message);
	}
}

Pletacka pletacka;
