
#include <DS3232RTC.h>      // https://github.com/JChristensen/DS3232RTC

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(RTC.get());
    delay(1000);
}
