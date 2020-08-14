# pragma once

#include <Arduino.h>

#include "Pletacka_config.hpp"
#include "Pletacka_display.hpp"
#include "Pletacka_wifi.hpp"
#include "Pletacka_debug.hpp"
#include "Pletacka_status.hpp"

#include "EEPROM.h"

#define ADC_EN          14
#define ADC_PIN         34
#define BUTTON_1        35
#define BUTTON_2        0 

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

	void debug(String message, String prefix = "D:");
	void debugln(String message, String prefix = "D:");
	void print(String message, String prefix = "P:");
	void println(String message, String prefix = "P:");
	
	
};

extern Pletacka pletacka;




