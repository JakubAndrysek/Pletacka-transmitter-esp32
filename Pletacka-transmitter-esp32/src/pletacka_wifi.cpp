#include "pletacka_wifi.hpp"
#include "pletacka.hpp"

pletacka_wifi::pletacka_wifi()
{
 
}

pletacka_wifi::~pletacka_wifi()
{
}

void pletacka_wifi::init(pletackaConfig config)
{
    wifiCfg.wifiName = config.wifiName;
    wifiCfg.wifiPassword = config.wifiPassword;
    wifiCfg.wifiChanel = config.wifiChenel;
    wifiCfg.wifiDefaulAp = config.wifiDefaulAp;
    wifiCfg.apName = config.apName;
    wifiCfg.apPassword = config.apPassword;

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
    WiFi.begin(wifiCfg.wifiName.c_str(), wifiCfg.wifiPassword.c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void pletacka_wifi::startAP()
{
    Serial.println("Starting " + wifiCfg.apName + " AP");
    WiFi.softAP(wifiCfg.apName.c_str(), wifiCfg.apPassword.c_str(), wifiCfg.apChanel );
}