#include "Pletacka_debug.hpp"
#include "WiFi.h"
#include "WiFiClient.h"


void Pletacka_debug::init(pletackaConfig config)
{
    debugCfg.debug_IP = config.debugIP;
    debugCfg.debug_port = config.debugPort;
    debugCfg.data_port = config.dataPort;
    
    
    if(WiFi.getMode() != WIFI_MODE_STA) 
    {
        Serial.println("Debug mode does not work with AP, use WiFi mode");
    }
    
    debug_ip.fromString(debugCfg.debug_IP); // Convert String IP to IP Class
    
    
    if(WiFi.status() == WL_CONNECTED)   // WiFi connection is required
    {
        Serial.println("Connecting debug to proxy IP:"+debug_ip.toString());
        if (!Debug.connect(debug_ip, debugCfg.debug_port)) {
            Serial.println("Can not connect to the debug server");
            delay(500);
        }
        if (!Data.connect(debug_ip, debugCfg.data_port)) {
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




