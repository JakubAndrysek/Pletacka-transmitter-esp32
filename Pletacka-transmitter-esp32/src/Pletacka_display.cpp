#include "Pletacka_display.hpp"
#include "Pletacka.hpp"



void Pletacka_display::displayInit(PletackaConfig config)
{
    tft.init();
    tft.fontHeight(2);
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(textColour);
}

void Pletacka_display::showId(int id)
{
    tft.fillCircle(12, 12,  12, TFT_DARKGREEN);
    tft.drawCentreString(String(id), 12, 5 , 2);  //string,start x,start y, font weight {1;2;4;6;7;8}
}

void Pletacka_display::showTime()
{
    tft.fillRoundRect(30, 0,  70, 24, radius, blockColour);
    tft.drawString("12:30:47", 35, 5 , 2);  //string,start x,start y, font weight {1;2;4;6;7;8}
}

void Pletacka_display::showError(String msg, int colour )
{
    tft.fillRoundRect(0, tft.height()- 15,  tft.width(), 15, radius, colour);
    tft.drawString(msg, 5,tft.height()-12, 1);  //string,start x,start y, font weight {1;2;4;6;7;8}
    // int x = TFT_RED
}

void Pletacka_display::hideError()
{
    tft.fillRoundRect(0, tft.height()- 15,  tft.width(), 15, radius, bcgColour);
}



void Pletacka_display::showMsg(String msg)
{
    tft.fillRoundRect(105, 0,  135, 24, radius, blockColour);
    tft.drawString(msg, 108, 5, 2);  //string,start x,start y, font weight {1;2;4;6;7;8}
}
