#include <Wire.h>                               //We need the wire library for the I2C display
#include <Adafruit_SSD1306.h>                   //We need the driver for the display
#include <Adafruit_GFX.h>                       // Core graphics library
#include <Adafruit_TFTLCD.h>                    // Hardware-specific library
#include <Fonts/FreeMono9pt7b.h>


#define OLED_RESET 4                            //display reset is on digital 4 but not used




Adafruit_SSD1306 display(OLED_RESET);           //create instance of the SSD306 called display




unsigned long start, finished, elapsed;         //create unsigned long integer variables for start finished elapsed
unsigned int seconds;



void setup()
{
  // Setup Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);    //begin the display @ hex address 0x3c
  display.setFont(&FreeMono9pt7b);
  display.display();                            //show splash screen
  display.clearDisplay();                       //clear display
  display.setTextColor(WHITE);                  //set display params

  pinMode(2, INPUT);                             // the start button
  pinMode(3, INPUT);                             // the stop button

  display.setCursor(0,10);                      //set display params
  display.println("Green to Start");            //send initial message to display buffer
//  display.println("Red to Stop");               //send initial message to display buffer
  display.display();                            //showbuffer

}
//void displayResult()                            //create a function called displayResult
//{
//  display.setTextSize(1);                       //set display params
//  display.setTextColor(WHITE);                  //set display params
//  display.setCursor(0, 0);                      //set display params
//  display.clearDisplay();                        //clear display & buffer
//  float h, m, s, ms;                             //create float variables (numbers with dec point)
//  unsigned long over;                            //create unsigned long integer variable over
//  elapsed = finished - start;                    //elapsed time is finished minus start
//  h = int(elapsed / 3600000);                    //h is the integer created by dividing elapsed by 360000
//  over = elapsed % 3600000;                      //over is created by elapsed modulo 360000
//  m = int(over / 60000);                         //m is the integer created by dividing over (seconds over 60) by 60000
//  over = over % 60000;                           //new over is over modulo 60000
//  s = int(over / 1000);                          //seconds is the integer created by dividing over by 1000
//  ms = over % 1000;                              //ms is created by new over modulo 1000
//  display.print("Elapsed time: ");               //send a title for elapsed to display buffer
//  display.println(elapsed);                      //send the raw elapsed time (miliseconds) to display buffer
//  display.println("Stop time: ");                //send title for h,m,s,ms to display buffer
//  display.print(h, 0);                           //send value to display buffer, no decimals
//  display.print("h ");
//  display.print(m, 0);                           //send value to display buffer, no decimals
//  display.print("m ");
//  display.print(s, 0);                           //send value to display buffer, no decimals
//  display.print("s ");
//  display.print(ms, 0);                          //send value to display buffer, no decimals
//  display.println("ms");
//  display.println();                             //send blank line to display buffer
//  display.display();                             //show buffer data on display
//}
void loop()
{
  ////  display.clearDisplay();                        //set display params
  //  display.setTextSize(1);                        //set display params
  //  display.setTextColor(WHITE);                  //set display params
  //  display.setCursor(25, 25);                      //set display params
  ////  display.clearDisplay();                        //clear display & buffer
  //
  //  display.print(millis()/1000);
  //  display.display();


  //  if (digitalRead(2) == HIGH)                    //if you pressed the green button
  //  {
  //    start = millis();                              //start = current millis
  //    delay(200);                                    // for debounce
  //    display.println("Started...");                 //send started to display buffer
  //    display.display();                             //show buffer data on display
  //  }
  //  if (digitalRead(3) == HIGH)                    //if you pressed the red buton
  //  {
  //    finished = millis();                           //finished = curent millis
  //    delay(200);                                    // for debounce
  //    displayResult();                               //call function displayResult
  //  }
}
