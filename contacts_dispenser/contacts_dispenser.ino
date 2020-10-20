
#include <Wire.h>                               //We need the wire library for the I2C display
#include <Adafruit_SSD1306.h>                   //We need the driver for the display
#include <Adafruit_GFX.h>                       // Core graphics library
#include <Adafruit_TFTLCD.h>                    // Hardware-specific library
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <DS3232RTC.h>                          // https://github.com/JChristensen/DS3232RTC

#define OLED_RESET 4                            //display reset is on digital 4 but not used

//create instance of the SSD306 called display
Adafruit_SSD1306 display(OLED_RESET);


////////////////////////
//  GLOBAL VARIABLES  //
////////////////////////
unsigned int init_L, init_R, currentTime;
unsigned short Ldays=0, Lhours=0, Lminutes=0, Lseconds=0;
unsigned short Rdays=0, Rhours=0, Rminutes=0, Rseconds=0;


/////////////////
//  FUNCTIONS  //
/////////////////

void getTime(){
  currentTime = RTC.get();
  Lseconds = currentTime-init_L;
  Rseconds = currentTime-init_R;

  if(Lseconds>59){
    Lminutes=Lseconds/60;
    Lseconds%=60;
    if(Lminutes>59){
      Lhours=Lminutes/60;
      Lminutes%=60;
      if(Lhours>23){
        Ldays=Lhours/24;
        Lhours%=24;
      }
    }
  }

  if(Rseconds>59){
    Rminutes=Rseconds/60;
    Rseconds%=60;
    if(Rminutes>59){
      Rhours=Rminutes/60;
      Rminutes%=60;
      if(Rhours>23){
        Rdays=Rhours/24;
        Rhours%=24;
      }
    }
  }
}


String doubledigit(String s){
  // function makes sure time variable has two digits
  if(s.length()<2){
    return "0"+s;
  }
  if(s.length()>2){
    return "99";
  }
  return s;
}


void reset()
{
  if(digitalRead(2) == HIGH)
  {
    // Reset Time Variables
    init_L = RTC.get();

    // Display Reset
    display.fillRect(0, 13, 62, 64, BLACK);
    display.setCursor(13,40);
    display.print("RESET");
    display.display();

    // While-loop for debounce
    while(digitalRead(2) == HIGH)
    {
      delay(100);
    }
  }
  else if(digitalRead(3) == HIGH)
  {
    // Reset Time Variables
    init_R = RTC.get();

    // Display Reset
    display.fillRect(65, 13, 128, 64, BLACK);
    display.setCursor(69+13,40);
    display.print("RESET");
    display.display();

    // While-loop for debounce
    while(digitalRead(3) == HIGH)
    {
      delay(100);
    }
  }
}


////////////////////
//  MAIN PROGRAM  //
////////////////////

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);    //begin the display @ hex address 0x3c
  display.display();                          //show splash screen
  display.clearDisplay();                       //clear display
  display.setTextColor(WHITE);                  //set display params

  pinMode(2, INPUT);  // Left Dispense/Reset
  pinMode(3, INPUT);  // Right Dispense/Reset

  // Set equal to current epoch time in seconds
  currentTime = RTC.get();
  init_L = currentTime;
  init_R = currentTime;
}


void loop()
{
  display.clearDisplay();

  // Setup
  display.drawFastVLine(63, 0, 64, WHITE);
  display.drawFastVLine(64, 0, 64, WHITE);
  display.drawFastHLine(0, 12, 128, WHITE);
  display.setFont(&FreeMono9pt7b);
  display.setCursor(8,9);
  display.print("LEFT");
  display.setCursor(72,9);
  display.print("RIGHT");

  // Set days, hours, mins, secs since init time
  getTime();
  
  // Days
  display.setFont(&FreeMonoBold18pt7b);
  display.setCursor(8,38);
  display.print(doubledigit(String(Ldays)));
  display.setCursor(69+8,38);
  display.print(doubledigit(String(Rdays)));
  display.setFont(&FreeMono9pt7b);
  display.setCursor(7,50);
  display.print("Days");
  display.setCursor(69+7,50);
  display.print("Days");

  // Hours, Minutes, Seconds
  display.setFont(NULL);
  display.setCursor(5,57);
  display.print(doubledigit(String(Lhours)) + ":" + doubledigit(String(Lminutes)) + ":" + doubledigit(String(Lseconds)));
  display.setCursor(69+5,57);
  display.print(doubledigit(String(Rhours)) + ":" + doubledigit(String(Rminutes)) + ":" + doubledigit(String(Rseconds)));
  

  // Show Buffer
  display.display();

  // Check if reset button is pushed
  reset();

}
