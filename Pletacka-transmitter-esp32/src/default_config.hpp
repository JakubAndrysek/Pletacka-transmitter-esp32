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
        , debugOn(true){

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
    bool debugOn;       //Startup into debug mode - TCP Debug
    
};