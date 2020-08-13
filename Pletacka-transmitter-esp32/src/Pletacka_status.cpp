#include "Pletacka_status.hpp"
#include "Pletacka.hpp"



void Pletacka_status::init(PletackaConfig config)
{
    opto.finish = optoFinish.state();
    opto.stop = optoStop.state();
}

String Pletacka_status::getStatus()
{
    // stati
}