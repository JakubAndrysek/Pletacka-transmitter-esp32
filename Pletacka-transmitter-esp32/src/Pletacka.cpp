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


	pinMode(LED_SEND, OUTPUT);
    pinMode(LED_WIFI, OUTPUT);
    pinMode(LED_ON, OUTPUT);
    
    pinMode(BTN_ENTER, INPUT);
    pinMode(BTN_B1, INPUT);
    pinMode(BTN_UP, INPUT);
    pinMode(BTN_DOWN, INPUT);

    pinMode(PWR_VOLTAGE, INPUT);

	digitalWrite(LED_ON, true);
	
	

	pletacka_wifi.init(config);
	if(config.remoteDataOn || config.remoteDebugOn || !digitalRead(BTN_DOWN))
	{
			println("STARTING DEBUG MODE");
			showError("DEBUG MODE", TFT_ORANGE);
			pletacka_debug.init(config);
	}
	
	pletacka_eeprom.begin(50);

	if(pletacka_eeprom.read(EEPROM_SNUMBER_A) == 255)
	{
		pletacka_eeprom.write(EEPROM_SNUMBER_A, 15);
	}

	pletacka_status.init(config);
	pletacka_alive.init(config);


	MDNS.begin("pletac-" + cfg.sensorNumber);

	apiState.setServerName(cfg.serverUrl + "/" + cfg.sensorNumber);
	println("Server:" + apiState.getServerName());
	// Serial.println();

	delay(200); //required for succes behavour
	timeInit();

	println("Sensor number " + String(cfg.sensorNumber) + " is configured");
	
	
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

void Pletacka::sendState(String state)
{
	static int counter = 0;
	counter++;

	auto request = apiState.GetReqest(state);

	Serial.println("\nGET\n  Req:" + request.request + "\n  Code : "+String(request.code)+" ->\""+String(request.main) + "\"");

	if(request.code == 200)
	{
		showMsg(String(counter) + " -> OK");
		hideError();
	}
	else
	{
		showError(request.code + "->"+ request.main);
		hideMsg();
	}
	
}

void Pletacka::sendAlive(int sensorNumber)
{
	pletacka_alive.sendAlive(sensorNumber);
}



int Pletacka::editSensorNumber(int actualNumber)
{
	int newNumber = actualNumber;
	pletacka.showMsg("Setup s. number");

	while(!digitalRead(BTN_ENTER))
	{

		if(!digitalRead(BTN_UP))
		{
			newNumber++;
			pletacka.showId(newNumber);
		}
		else if (!digitalRead(BTN_DOWN))
		{
			newNumber--;
			pletacka.showId(newNumber);
		}
		delay(300);
		
	}

	return newNumber;
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
