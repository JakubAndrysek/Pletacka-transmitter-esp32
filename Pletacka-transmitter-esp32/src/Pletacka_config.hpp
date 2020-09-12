#pragma once

#include <Arduino.h>

#define LED_SEND 27
#define LED_WIFI 26
#define LED_ON 25
#define OP_1_FINISH 39
#define OP_2_STOP 38
#define OP_3 37
#define OP_4 36
#define BTN_ENTER 21
#define BTN_B1 12
#define BTN_UP 0
#define BTN_DOWN 35
#define TMP_SDA 22
#define TMP_SCL 17
#define TMP_OS 2
#define PWR_VOLTAGE 32
#define GPIO_13 13
#define GPIO_15 15
#define GPIO_33 33

struct PletackaConfig
{
	PletackaConfig()
		: sensorNumber(1)
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

		{

	}

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

};

// struct PletackaPinout
// {
// 	PletackaPinout()
// 		: LED_SEND(27)
// 		, LED_WIFI(26)
// 		, LED_ON(25)
// 		, OP_FINISH(36)
// 		, OP_STOP(37)
// 		, OP_3(38)
// 		, OP_4(39)
// 		, BTN_ENTER(21)
// 		, BTN_B1(12)
// 		, TMP_SDA(22)
// 		, TMP_SCL(17)
// 		, TMP_OS(2)
// 		, PWR_VOLTAGE(32)
// 		, GPIO_13(13)
// 		, GPIO_15(15)
// 		, GPIO_33(33)
// 		{

// 	}

// 	int LED_SEND;
// 	int LED_WIFI;
// 	int LED_ON;	
// 	int OP_FINISH;
// 	int OP_STOP;
// 	int OP_3;
// 	int OP_4;
// 	int BTN_ENTER;
// 	int BTN_B1;
// 	int TMP_SDA;
// 	int TMP_SCL;
// 	int TMP_OS;
// 	int PWR_VOLTAGE;
// 	int GPIO_13;
// 	int GPIO_15;
// 	int GPIO_33;	
// };



enum eepromConfig
{
	WIFI_NAME,
	WIFI_PWD,

};


