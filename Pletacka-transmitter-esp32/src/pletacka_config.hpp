#pragma once

#include <Arduino.h>

struct pletackaConfig
{
	pletackaConfig()
		: sensorName("")
		, sensorNumber(1)
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
		, remoteDebugOn(false) {

	}

	String sensorName;  //Sensor name
	int sensorNumber;   //Sensor number
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
	
	
};