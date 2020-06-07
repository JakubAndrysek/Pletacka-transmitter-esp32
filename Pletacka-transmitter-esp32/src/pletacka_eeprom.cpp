#include "pletacka_eeprom.hpp"
#include "pletacka.hpp"

#include <EEPROM.h>

void pletacka_eeprom::init(pletackaConfig config)
{
    if (!EEPROM.begin(eepromCfg.eepromSize))
    {
        pletac.println("Dailed to initialise EEPROM");
        delay(500);
    }
}
