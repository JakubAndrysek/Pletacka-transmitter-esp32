# pragma once

#include <Arduino.h>

#include "Pletacka_config.hpp"
#include "Pletacka_display.hpp"
#include "Pletacka_wifi.hpp"
#include "Pletacka_debug.hpp"
#include "Pletacka_status.hpp"


#include "EEPROM.h"

class Pletacka: public Pletacka_display
{
private:
	PletackaConfig cfg;
	Pletacka_wifi pletacka_wifi;
	Pletacka_debug pletacka_debug;
	Pletacka_status pletacka_status;
	EEPROMClass pletacka_eeprom;
	
	
	

	



public:
	Pletacka();
	~Pletacka();
	void config(const PletackaConfig config);
	String isChange();

	void debug(String message);
	void debugln(String message);
	void print(String message);
	void println(String message);
	
	
};

extern Pletacka pletacka;




