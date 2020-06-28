# pragma once

#include <Arduino.h>

#include "Pletacka_config.hpp"
#include "Pletacka_wifi.hpp"
#include "Pletacka_debug.hpp"

#include "EEPROM.h"
#include <TFT_eSPI.h>

class Pletacka
{
private:
	pletackaConfig cfg;
	Pletacka_wifi pletacka_wifi;
	Pletacka_debug pletacka_debug;
	EEPROMClass pletacka_eeprom;
	TFT_eSPI tft = TFT_eSPI(135, 240); // Invoke custom library

	



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




