#define BTNPIN 6

#include "Arduino.h"
#include "checkBtnPressed.h"
#include "LEDControl.h"
#include "uploadData.h" //coming soon

extern int seatStatus;
extern int timeRemained;

void checkBtnPressed(){

  pinMode(BTNPIN, INPUT);
  int buttonState = digitalRead(BTNPIN);
  
  if (buttonState == HIGH) {    
    
    if(seatStatus == -1 || seatStatus == 0){
      //if seat avaliable or temporarily out, do nothing, 
      return;
    }else if(seatStatus == 1){
      //if occupied...
      seatStatus = 0;       //1. set seatStatus temporarily out, 
      LEDControl(0,2);      //2. turn on blue LED, 
      LEDControl(1,0);      //3. turn off red LED!
      timeRemained = 1800;  //4. start counting down 30 mins
      uploadData();         //5. report to RPi
    }
  }
}

