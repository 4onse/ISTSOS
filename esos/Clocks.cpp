#include "Clocks.h"

RTC_DS1307 rtc;  
String localDateTime;

// begin RTC 
void initRTC(){
    if(!rtc.begin())
    printError(F("RTC_NOT_CONNECTED"));
    else if(! rtc.isrunning()){
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        printError(F("RTC_FAILED"));
    }
    
    else
    printStr(F("RTC_INIT_DONE ")); 
}

// void set Time from PC
void setTimeFromPC(){
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

// get the local time

String getLocalTime(){
   DateTime now = rtc.now();
   
   localDateTime=String(now.year(),DEC);
   localDateTime.concat('-');
   if(now.month()<10)localDateTime.concat("0");
   localDateTime.concat(String(now.month(), DEC));
   localDateTime.concat('-');
   if(now.day()<10)localDateTime.concat("0");
   localDateTime.concat(String(now.day(), DEC));
   localDateTime.concat('-');
   if(now.hour()<10)localDateTime.concat("0");
   localDateTime.concat(String(now.hour(), DEC));
   localDateTime.concat(':');
   if(now.minute()<10)localDateTime.concat("0");
   localDateTime.concat(String(now.minute(), DEC));
   localDateTime.concat(':');
   if(now.second()<10)localDateTime.concat("0");
   localDateTime.concat(String(now.second(), DEC));

   return localDateTime;
}

DateTime getCurruntRTCDate(){
    return rtc.now();
}

unsigned long getUnixTime(){
    DateTime now = rtc.now();
    return now.unixtime();
}