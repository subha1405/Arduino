#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#include <MD_MAX72xx.h>
#include <SPI.h>

// #include <MD_Parola.h>
// #include <MD_MAX72XX.h>
// #include <SPI.h>
 #include <DS3231.h>
  #include <Wire.h>
// #include "Font7Seg.h"


DS3231 Clock;

bool Century=false;
bool h12;
bool PM;
byte  dd,mm,yyy;
uint16_t  h, m, s;

#define MAX_DEVICES 4
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW 
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10
MD_Parola P = MD_Parola(HARDWARE_TYPE,CS_PIN, MAX_DEVICES);

#define SPEED_TIME 75 
#define PAUSE_TIME  0  

#define MAX_MESG  20

char szTime[9];    
char szMesg[MAX_MESG+1] = "";

uint8_t degC[] = { 6, 3, 3, 56, 68, 68, 68 }; 
uint8_t degF[] = { 6, 3, 3, 124, 20, 20, 4 }; 

char *mon2str(uint8_t mon, char *psz, uint8_t len)


{
  static const __FlashStringHelper* str[] =
  {
    F("Jan"), F("Feb"), F("Mar"), F("Apr"),
    F("May"), F("Jun"), F("Jul"), F("Aug"),
    F("Sep"), F("Oct"), F("Nov"), F("Dec")
  };

  strncpy_P(psz, (const char PROGMEM *)str[mon-1], len);
  psz[len] = '\0';

  return(psz);
}

char *dow2str(uint8_t code, char *psz, uint8_t len)
{
  static const __FlashStringHelper*  str[] =
  {
  F("Sunday"), F("Monday"), F("Tuesday"),
  F("Wednesday"), F("Thursday"), F("Friday"),
  F("Saturday"), F("Sunday")
  };

  strncpy_P(psz, (const char PROGMEM *)str[code-1], len);
  psz[len] = '\0';

  return(psz);
}
void getTime(char *psz, bool f = true)
{
  s = Clock.getSecond();
  m = Clock.getMinute();
    sprintf(psz, "%02d%c%02d", h, (f ? ':' : ' '), m);
    if (Clock.getHour(h12,PM)>=13 || Clock.getHour(h12,PM)==0)
  {
    h = Clock.getHour(h12,PM) - 12;
  }
  else
  {
    h = Clock.getHour(h12,PM);
  }
 
}

void getDate(char *psz)
{
   char  szBuf[10];
 
  
   dd=Clock.getDate();
   mm=Clock.getMonth(Century); 
   yyy=Clock.getYear();
   sprintf(psz, "%d %s %04d",dd , mon2str(mm, szBuf, sizeof(szBuf)-1),(yyy + 2000));
}

void setup()
{
  P.begin();
  P.setInvert(false); 
  Wire.begin();
  
  P.setZone(0,  MAX_DEVICES-4, MAX_DEVICES-1);
  
  P.setZone(1, MAX_DEVICES-4, MAX_DEVICES-1);
  P.displayZoneText(1, szTime, PA_CENTER, SPEED_TIME, PAUSE_TIME, PA_PRINT, PA_NO_EFFECT);

  P.displayZoneText(0, szMesg, PA_CENTER, SPEED_TIME, 0,PA_PRINT , PA_NO_EFFECT);

  P.addChar('$', degC);
  P.addChar('&', degF);

}

void loop()
{
  static uint32_t lastTime = 0; 
  static uint8_t  display = 0;  
  static bool flasher = false;  

  P.displayAnimate();

   if (P.getZoneStatus(0))
  {
    switch (display)
    {
      case 0:   
      P.setPause(0,1000);
      P.setTextEffect(0, PA_MESH, PA_BLINDS);
      display++;    
      dtostrf(Clock.getTemperature(), 3, 1, szMesg);
      strcat(szMesg, "$");
          

        break;

      case 1: 
        P.setTextEffect(0, PA_OPENING, PA_GROW_DOWN);
        display++;
        dtostrf((1.8 *Clock.getTemperature() )+32, 3, 1, szMesg);
        strcat(szMesg, "&");
   
   
 
        break;

      case 2:
      
      P.setFont(0, 4);
      P.setTextEffect(0, PA_PRINT, PA_NO_EFFECT);
      P.setPause(0,0);
      if (millis() - lastTime >= 1000)
      {
        lastTime = millis();
        getTime(szMesg, flasher);
        flasher = !flasher;
        }
    if(s==00&& s<=30){
    display++;
    P.setTextEffect(0, PA_PRINT, PA_SCROLL_UP);
    }

            
    
        break;
      
      case 3: 
       
        P.setFont(0,nullptr);
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        display++;
        dow2str(Clock.getDoW()+1, szMesg, MAX_MESG); // Added +1 or +2 to get correct Day of Week

       
        break;
      default:  
        
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        display = 0;
        getDate(szMesg);
        break;
    }

    P.displayReset(0);  
  }

} 