#pragma once

#include <Arduino.h>
#include "pletacka_config.hpp"
#include <WiFi.h>
#include <WiFiClient.h>


class pletacka_debug
{
private:
    struct debugConfig
    {
        debugConfig()
            : Debug_IPs("192.168.0.112")
            , Debug_port(12345)
            , Data_port(12346) {       
        }
        String Debug_IPs;    //IP adress of your PC with Lorris
        int Debug_port;               //Proxy debug port
        int Data_port;                //Proxy data port
    };

    debugConfig debugCfg;

    IPAddress Debug_IP;



    
public:
	WiFiClient Debug;
    WiFiClient Data;
    void init(pletackaConfig config);
	// void send(String message);
	
};















