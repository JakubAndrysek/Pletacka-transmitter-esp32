#pragma once

#include <Arduino.h>
#include "Pletacka_config.hpp"
#include <EEPROM.h>

class Pletacka_eeprom : public EEPROMClass
{
private:
    struct eepromConfig
    {
        eepromConfig()
        : eepromSize(20) {

        }
        size_t eepromSize; //number of bytes you want to access
    };

    eepromConfig eepromCfg;
    
public:
    void init(pletackaConfig config);
};

