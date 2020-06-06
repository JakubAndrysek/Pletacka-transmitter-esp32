# pragma once

#include <Arduino.h>

#include "pletacka_config.hpp"
#include "pletacka_wifi.hpp"
#include "pletacka_debug.hpp"

class pletacka
{
private:
	pletackaConfig cfg;
	pletacka_wifi pWifi;
	pletacka_debug pDebug;
	



public:
	pletacka();
	~pletacka();
	void config(const pletackaConfig config);
	void debug(String message);
	void debugln(String message);
	void print(String message);
	void println(String message);
	
};

extern pletacka pletac;




