#include "pletacka_debug.hpp"
#include "WiFi.h"
#include "WiFiClient.h"


void pletacka_debug::init(pletackaConfig config)
{
    if(WiFi.getMode() != WIFI_MODE_STA) 
    {
        Serial.println("Debug mode does not work with AP, use WiFi mode");
    }
    
    Debug_IP.fromString(debugCfg.Debug_IPs); // Convert String IP to IP Class
    
    
    if(WiFi.status() == WL_CONNECTED)   // WiFi connection is required
    {
        Serial.println("Connecting debug to proxy IP:"+Debug_IP.toString());
        if (!Debug.connect(Debug_IP, debugCfg.Debug_port)) {
            Serial.println("Can not connect to the debug server");
            delay(500);
        }
        if (!Data.connect(Debug_IP, debugCfg.Data_port)) {
            Debug.println("Can not connect to the data server");
            delay(500);
        }
    }
    else
    {
        Serial.println("ESP is not conested to the WiFi");
    }
    Debug.println("Connected succesfly to DEBUG\n");
    Data.println("Connected succesfly to DATA\n");
    Serial.println("Connected succesfly to DEBUG and DATA\n");   

}




