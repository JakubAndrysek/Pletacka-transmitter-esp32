#include "Pletacka_status.hpp"
#include "Pletacka.hpp"



void Pletacka_status::init(pletackaConfig config)
{
    opto.finish = optoFinish.state();
    opto.stop = optoStop.state();
}