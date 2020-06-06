# pragma once

#include <Arduino.h>

#include "default_config.hpp"
#include "pletacka_wifi.hpp"

class pletacka
{
private:
    pletackaConfig cfg;
    pletacka_wifi wifi;


    
public:
    pletacka();
    ~pletacka();
    void config(const pletackaConfig config);
    
};

extern pletacka pletac;



