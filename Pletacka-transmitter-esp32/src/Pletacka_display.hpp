#pragma once

#include <Arduino.h>
#include "pletacka_config.hpp"
#include <TFT_eSPI.h>
#include "time.h"



class Pletacka_display
{
    private:
        int bcgColour = TFT_BLACK;
        int blockColour = TFT_BLUE;
        int textColour = TFT_WHITE;
        int errorColour = TFT_RED;
        int radius = 4;

        struct tm tm;
        
        
        

    public:
        TFT_eSPI tft = TFT_eSPI(135, 240);
        void displayInit(PletackaConfig config);
        void timeInit();
        void showId(int id);
        void showTime();
        void showError(String msg, int colour = TFT_RED);
        void hideError();
        void showMsg(String msg);
        void showStatus(String status);
        void showStatusX(String status, int x);
        
};




