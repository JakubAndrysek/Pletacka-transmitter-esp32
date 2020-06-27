# pragma once

#include <Arduino.h>

#include "Pletacka_config.hpp"
#include "Pletacka_wifi.hpp"
#include "Pletacka_debug.hpp"
#include "Pletacka_eeprom.hpp"

class Pletacka
{
private:
	pletackaConfig cfg;
	Pletacka_wifi pletacka_wifi;
	Pletacka_debug pletacka_debug;
	Pletacka_eeprom pletacka_eeprom;
	



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




