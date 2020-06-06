#include <Arduino.h>

class pletacka_wifi
{
private:
    struct wifiConfig
    {
        wifiConfig()
            : wifiName("")
            , wifiPassword("")
            , wifiDefaulAp(false)
            , apName("")
            , apPassword("") {
        }
            
        String wifiName;    //WiFi name
        String wifiPassword;//WoFi password
        bool wifiDefaulAp;  //Run AP on startup
        String apName;      //AP name
        String apPassword;  //AP password
    };

    wifiConfig wifiCfg;
    
public:
    pletacka_wifi();
    ~pletacka_wifi();
    void init(const pletackaConfig& config);
    void configConnection();
    void connectWifi();
    void startAP();
};


