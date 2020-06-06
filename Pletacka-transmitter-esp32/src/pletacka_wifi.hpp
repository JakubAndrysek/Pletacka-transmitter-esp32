#pragma once

#include <Arduino.h>
#include "default_config.hpp"
#include <WiFi.h>

class pletacka_wifi
{
private:
    struct wifiConfig
    {
        wifiConfig()
            : wifiName("")
            , wifiPassword("")
            , wifiChanel(1)
            , wifiDefaulAp(false)
            , apName("")
            , apPassword("")
            , apChanel(1) {
        }
            
        String wifiName;    //WiFi name
        String wifiPassword;//WiFi password
        int wifiChanel;     //WiFi chanel
        bool wifiDefaulAp;  //Run AP on startup
        String apName;      //AP name
        String apPassword;  //AP password
        int apChanel;        //AP chanel
    };

    wifiConfig wifiCfg;
    
public:
    pletacka_wifi();
    ~pletacka_wifi();
    void init(pletackaConfig config);
    void configConnection();
    void connectWifi();
    void startAP();
};


