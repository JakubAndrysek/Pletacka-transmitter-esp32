#pragma once

#include <Arduino.h>
#include "pletacka_config.hpp"
#include "Optocoupler.hpp"


class Pletacka_status
{
private:
    
    Optocoupler optoStop; 
	Optocoupler optoFinish; 
	// Optocoupler optocoupler1; 
	// Optocoupler optocoupler2;

    struct optoStatus
    {
        bool stop;
        bool finish;
    }opto;
    
    

public:

    void init(pletackaConfig config);
    
};




