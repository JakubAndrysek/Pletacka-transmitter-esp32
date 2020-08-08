#pragma once

#include <Arduino.h>
#include "pletacka_config.hpp"
#include <TFT_eSPI.h>



class Pletacka_display
{
    private:
        int bcgColour = TFT_BLUE;
        int textColour = TFT_WHITE;
        int radius = 4;
        
        

    public:
        TFT_eSPI tft = TFT_eSPI(135, 240);
        void displayInit(pletackaConfig config);
        void showId(int id);
        void showTime();
        void showError(String msg, int colour = TFT_RED);
        void showMsg(String msg);
        
};




