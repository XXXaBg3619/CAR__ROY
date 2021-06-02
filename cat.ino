#include<SoftwareSerial.h>


SoftwareSerial BT(9,8);   // TX,RX on bluetooth module

void setup() {
  
  BT.begin(9600);
  Serial.begin(9600);

}

#include"bluetooth.h"
#include"motor.h"
#include"buzzer.h"

BT_CMD _cmd = NOTHING;


void loop() {
  
  _cmd = ask_BT();
  //Serial.println(_cmd);
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

}
