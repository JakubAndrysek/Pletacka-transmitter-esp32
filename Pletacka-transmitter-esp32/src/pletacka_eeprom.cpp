#include "Pletacka_eeprom.hpp"
#include "Pletacka.hpp"



void Pletacka_eeprom::init(pletackaConfig config)
{
    if (!EEPROM.begin(eepromCfg.eepromSize))
    {
        pletacka.println("Dailed to initialise EEPROM");
        delay(500);
    }
}
