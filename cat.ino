#include<SoftwareSerial.h>


SoftwareSerial BT(9,10);   // TX,RX on bluetooth module

void setup() {
  
  BT.begin(9600);
  Serial.begin(9600);

}

#include"bluetooth.h"
#include"buzzer.h"

#include"teaser.h"

BT_CMD _cmd = NOTHING;


unsigned long timer;
bool teaser1 = false;
bool teaser2 = false;
bool teaser3 = false;

void loop() {

  timer = millis();
  
  _cmd = ask_BT();
  if(_cmd != 0)
    Serial.println(_cmd);
  
  switch(_cmd){

    case ADVANCE:
      Advance();
      
    case BACK:
      Back();

    case TURN_LEFT:
      Left_Turn();
      
    case TURN_RIGHT:
      Right_Turn();
      
    case BUZZ:
      Buzz(melody3, tempo3);
      
    default:
      MotorWriting(0, 0);
      
  }


  if(_cmd == TEASE1){
    timer = millis();
    teaser1 = true;
  }
  Teaser1(timer, teaser1);

}
