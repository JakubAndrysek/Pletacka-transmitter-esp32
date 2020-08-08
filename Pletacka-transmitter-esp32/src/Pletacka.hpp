# pragma once

#include <Arduino.h>

#include "Pletacka_config.hpp"
#include "Pletacka_display.hpp"
#include "Pletacka_wifi.hpp"
#include "Pletacka_debug.hpp"


#include "EEPROM.h"

class Pletacka: public Pletacka_display
{
private:
	pletackaConfig cfg;
	// Pletacka_display pletacka_display;
	Pletacka_wifi pletacka_wifi;
	Pletacka_debug pletacka_debug;
	EEPROMClass pletacka_eeprom;
	
	

	



public:
	Pletacka();
	~Pletacka();
	void config(const pletackaConfig config);
	void debug(String message);
	void debugln(String message);
	void print(String message);
	void println(String message);
	
};

extern Pletacka pletacka;




