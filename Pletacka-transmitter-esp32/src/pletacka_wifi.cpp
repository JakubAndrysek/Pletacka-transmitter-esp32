#include "pletacka_wifi.hpp"
#include "pletacka.hpp"

pletacka_wifi::pletacka_wifi()
{
 
}

pletacka_wifi::~pletacka_wifi()
{
}

void pletacka_wifi::init(pletackaConfig &config)
{
    // wifiCfg.wifiName = config.wifiName;
    // wifiCfg.wifiPassword = config.wifiPassword;
    // wifiCfg.wifiDefaulAp = config.wifiDefaulAp;
    // wifiCfg.apName = config.apName;
    // wifiCfg.apPassword = config.apPassword;

    configConnection();
}

void pletacka_wifi::configConnection()
{
    if(wifiCfg.wifiDefaulAp)
    {
        startAP();
    }
    else
    {
        connectWifi();
    }
    
}


void pletacka_wifi::connectWifi()
{
    Serial.println("Connecting to " + wifiCfg.wifiName);
}

void pletacka_wifi::startAP()
{
    Serial.println("Starting " + wifiCfg.apName + " AP");
}