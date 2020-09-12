#include <Arduino.h>
#include <WiFi.h>
#include "debug.h"
#include "NetteApi.hpp"
#include "Optocoupler.hpp"
#include "credentials.h"
#include "time.h"
#include "BasicOTA.hpp"




void program()
{
  const String SENSOR_NAME1 = "Pletacka12";
  const String SENSOR_NAME2 = "Pletacka11";

  const char* ntpServer = "pool.ntp.org";
  const long  gmtOffset_sec = 3600;
  const int   daylightOffset_sec = 3600;  
  
  enum setups
  {
    WAIT_FOR_START = 0,
    RUN = 1,
  };

  enum pins
  {
    PL1_FINISHED = 26,
    PL1_STOP = 27,    
    PL2_FINISHED = 14,
    PL2_STOP= 13,
  };

  enum states
  {
    SSTOP = 1,
    SFINISHED = 0,
  };

  enum pletac_run
  {
    DEF = -1,
    ON = 0,
    STOP = 1, 
    FINISHED = 2,
  };

  
  struct pletac
  {
    bool Fin;
    bool Stop;
  }pletac1, pletac2;

  struct  send
  {
    String now;
    String last;
  }message1, message2;

  

  

  int Spletac1_start = WAIT_FOR_START;
  int Spletac1_run = ON;
  
  int Spletac2_start = WAIT_FOR_START;
  int Spletac2_run = ON;

  Optocoupler pl1Fin(PL1_FINISHED);
  Optocoupler pl1Stop(PL1_STOP);
  Optocoupler pl2Fin(PL2_FINISHED);
  Optocoupler pl2Stop(PL2_STOP);

  BasicOTA OTA;

  NetteApi addEvent("http://192.168.0.148/Nette/pletacka-website-nette/api/v1/thisSensor/add-event"); //http://192.168.0.148/Nette/pletacka-website-nette/api/v1/thisSensor/add-event


  Serial.begin(115200);

  WiFi.begin(SSID, PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  struct tm tm;
  getLocalTime(&tm);
  OTA.begin();

  Serial.println("Start");


  

  while (1)
  {
    OTA.handle();
    getLocalTime(&tm);
    
    pletac1.Fin = pl1Fin.state();
    pletac1.Stop = pl1Stop.state();
    pletac2.Fin = pl2Fin.state();
    pletac2.Stop = pl2Stop.state();
    // pl1Fin.printState();
    // pl1Stop.printState();
    // pl2Fin.printState();
    // pl2Stop.printState();
    // tm.tm_hour
    // Serial.printf("Time: %d:%d:%d%\r", tm.tm_hour, tm.tm_min, tm.tm_sec);

    if(tm.tm_hour == 23 && tm.tm_min == 59 && tm.tm_sec == 0)
    {
      Serial.println("Restarting...");
      delay(2000);
      ESP.restart();
    }
    
    switch (Spletac1_start)
    {
    case WAIT_FOR_START:
      if((pl1Fin.state()==1)&&(pl1Stop.state()==1))
      {
        Spletac1_start = RUN;
        Serial.println("Pletacka1 - Start");
      }
      break;


    case RUN:
      switch (Spletac1_run)
      {
      case ON:
        dprintf("ON");
        Spletac1_run = DEF;
        message1.now = "ON";
        break;
      case STOP:
        dprintf("STOP");
        message1.now = "STOP";

        if (pletac1.Stop!=SSTOP) //END STOP
        {
          dprintf("REWORK---FIRST");
          Spletac1_run = DEF;
          message1.now = "REWORK";
        }
        break;
      
      default:
        dprintf("DEF");
        if(pletac1.Stop==SSTOP)
        {
          Spletac1_run = STOP;
        }
        else
        {
          if(pletac1.Fin==SFINISHED)
          {
            message1.now = "FINISHED";
          }
          else
          {
            message1.now = "";
          }
          
        }
        break;
      }
      
      break;
    }  
  

    ////////////////////

    switch (Spletac2_start)
    {
    case WAIT_FOR_START:
      if((pl2Fin.state()==1)&&(pl2Stop.state()==1))
      {
        Spletac2_start = RUN;
        Serial.println("Pletacka2 - Start");
      }
      break;


    case RUN:
      switch (Spletac2_run)
      {
      case ON:
        dprintf("ON");
        Spletac2_run = DEF;
        message2.now = "ON";
        break;
      case STOP:
        dprintf("STOP");
        message2.now = "STOP";

        if (pletac2.Stop!=SSTOP) //END STOP
        {
          dprintf("REWORK---FIRST");
          Spletac2_run = DEF;
          message2.now = "REWORK";
        }
        break;
      
      default:
        dprintf("DEF");
        if(pletac2.Stop==SSTOP)
        {
          Spletac2_run = STOP;
        }
        else
        {
          if(pletac2.Fin==SFINISHED)
          {
            message2.now = "FINISHED";
          }
          else
          {
            message2.now = "";
          }
          
        }
        break;
      }
      
      break;
    }  
    delay(10);


    if((message1.last != message1.now)&&(message1.now != ""))
    {
      Serial.println("            ++MSG1: "+message1.now);
      addEvent.GetReqest(SENSOR_NAME1+"/"+message1.now);


    }
    message1.last = message1.now;


    if((message2.last != message2.now)&&(message2.now != ""))
    {
      Serial.println("            --MSG2: "+message2.now);
      addEvent.GetReqest(SENSOR_NAME2+"/"+message2.now);


    }
    message2.last = message2.now;    
  }




  
}






void setup() {
  program();
}

void loop() {
  
}

