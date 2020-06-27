#pragma once

#include <Arduino.h>
#include "pletacka_config.hpp"
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
            , data_port(12346) {       
        }
        String debug_IP;    //IP adress of your PC with Lorris
        int debug_port;      //Proxy debug port
        int data_port;       //Proxy data port
    };

    debugConfig debugCfg;

    IPAddress debug_ip;



    
public:
	WiFiClient Debug;
    WiFiClient Data;
    void init(pletackaConfig config);
	// void send(String message);
	
};















