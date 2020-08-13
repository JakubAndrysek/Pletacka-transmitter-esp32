#pragma once

#include <Arduino.h>
#include "Pletacka_config.hpp"
#include <WiFi.h>
#include <WiFiClient.h>


class Pletacka_debug
{
private:
    struct debugConfig
    {
        debugConfig()
            : debug_IP("192.168.0.111")
            , debug_port(12345)
            , data_port(12346)
            , remoteDebugOn(false)
            , remoteDataOn(false) {       
        }
        String debug_IP;    //IP adress of your PC with Lorris
        int debug_port;      //Proxy debug port
        int data_port;       //Proxy data port
        bool remoteDebugOn;
        bool remoteDataOn;
    };

    debugConfig debugCfg;

    IPAddress debug_ip;



    
public:
	WiFiClient Debug;
    WiFiClient Data;
    void init(PletackaConfig config);
	// void send(String message);
	
};















