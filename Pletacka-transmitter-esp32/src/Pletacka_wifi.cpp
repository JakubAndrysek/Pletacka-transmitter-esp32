#include "Pletacka_wifi.hpp"
#include "Pletacka.hpp"

/**
 * @brief Construct a new Pletacka_wifi::Pletacka_wifi object
 * 
 */
Pletacka_wifi::Pletacka_wifi()
{
 
}

Pletacka_wifi::~Pletacka_wifi()
{
}

void Pletacka_wifi::init(PletackaConfig config)
{
    wifiCfg.wifiName = config.wifiName;
    wifiCfg.wifiPassword = config.wifiPassword;
    wifiCfg.wifiChanel = config.wifiChenel;
    wifiCfg.wifiDefaulAp = config.wifiDefaulAp;
    wifiCfg.apName = config.apName;
    wifiCfg.apPassword = config.apPassword;

    configConnection();
}

void Pletacka_wifi::configConnection()
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


void Pletacka_wifi::connectWifi()
{
    pletacka.println("Connecting to " + wifiCfg.wifiName);
    WiFi.begin(wifiCfg.wifiName.c_str(), wifiCfg.wifiPassword.c_str());

    int counter = 0;

    while (WiFi.status() != WL_CONNECTED) {
        counter++;
        delay(500);
        pletacka.print(".");
        pletacka.showMsg("Connecting WiFi"); 

        if(counter> 10)
        {
            pletacka.showError("Not connected to WiFi");            
        }
    }

    
    pletacka.showMsg("WiFi " + wifiCfg.wifiName);
    pletacka.hideError();

    pletacka.println("\nWiFi connected");
    pletacka.print("IP address: ");
    pletacka.print(String(WiFi.localIP()));
    pletacka.print("    MAC address: ");
    pletacka.println(String(WiFi.macAddress()));    
    
}

void Pletacka_wifi::startAP()
{
    pletacka.showMsg("AP: "+wifiCfg.apName);
    pletacka.println("Starting **" + wifiCfg.apName + "** AP");
    WiFi.softAP(wifiCfg.apName.c_str(), wifiCfg.apPassword.c_str(), wifiCfg.apChanel );
}



