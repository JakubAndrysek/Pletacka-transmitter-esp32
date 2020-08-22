#pragma once

#include <Arduino.h>

struct PletackaConfig
{
	PletackaConfig()
		: sensorName("")
		, sensorNumber(1)
		, serverUrl("")
		, wifiName("")
		, wifiPassword("")
		, wifiChenel(1)
		, wifiDefaulAp(false)
		, apName("")
		, apPassword("")
		, apChanel(1) 
		, serialDataOn(true)
		, serialDebugOn(false)
		, remoteDataOn(false)
		, remoteDebugOn(false)
		, debugIP("192.168.0.111")
		, debugPort(12345)
		, dataPort(12346)

		, pinFinish(26)
		, pinStop(27)
		{

	}

	String sensorName;  //Sensor name
	int sensorNumber;   //Sensor number
	String serverUrl; 	//Server URL address
	String wifiName;    //WiFi name
	String wifiPassword;//WiFi password
	int wifiChenel;     //WiFi chanel
	bool wifiDefaulAp;  //Run AP on startup
	String apName;      //AP name
	String apPassword;  //AP password
	int apChanel;       //AP chanel
	bool serialDataOn; 	//Enable serial comunication - default on
	bool serialDebugOn;	//Startup into debug mode - Serial Debug
	bool remoteDataOn;	//Enable remote "serial" comunicaton - proxy
	bool remoteDebugOn; //Startup into debug mode - Proxy Debug
	String debugIP;		//IP adress of your PC with Lorris
	int debugPort;		//Proxy debug port
	int dataPort;		//Proxy data port

	int pinFinish;		//
	int pinStop;		//
	
	
};



enum eepromConfig
{
	WIFI_NAME,
	WIFI_PWD,

};


