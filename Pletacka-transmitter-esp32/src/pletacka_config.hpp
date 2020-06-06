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
		, remoteDataOn(false)
		, remoteDebugOn(false)
		, serialDebugOn(false) {

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
	bool remoteDataOn;	//Send data into Sarial ana TCP Data
	bool remoteDebugOn; //Startup into debug mode - TCP Debug
	bool serialDebugOn;	//Startup into debug mode - Serial Debug
	
};