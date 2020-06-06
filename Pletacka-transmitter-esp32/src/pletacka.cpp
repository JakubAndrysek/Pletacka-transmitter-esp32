#include "pletacka.hpp"

pletacka::pletacka()
{
    Serial.begin(115200);
}

pletacka::~pletacka()
{
}

void pletacka::config(const pletackaConfig& config)
{
    cfg = config;
    Serial.begin(115200);
    Serial.println("Sensor "+cfg.sensorName+ " is configuring");

    
    
}


pletacka pletac;