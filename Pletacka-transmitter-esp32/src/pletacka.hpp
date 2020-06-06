# pragma once

#include <Arduino.h>
#include "pletacka_wifi.hpp"

struct pletackaConfig
{
    pletackaConfig()
        : sensorName("")
        , sensorNumber(1)
        , wifiName("")
        , wifiPassword("")
        , wifiDefaulAp(false)
        , apName("")
        , apPassword("") {

    }

    String sensorName;  //Sensor name
    int sensorNumber;   //Sensor number
    String wifiName;    //WiFi name
    String wifiPassword;//WoFi password
    bool wifiDefaulAp;  //Run AP on startup
    String apName;      //AP name
    String apPassword;  //AP password
    
};

class pletacka
{
private:
    pletackaConfig cfg;
    // pletacka_wifi wifi;


    
public:
    pletacka();
    ~pletacka();
    void config(const pletackaConfig& config);
};

extern pletacka pletac;



