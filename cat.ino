#include<SoftwareSerial.h>


SoftwareSerial BT(9,10);   // TX,RX on bluetooth module

void setup() {
  
  BT.begin(9600);
  Serial.begin(9600);

}

#include"bluetooth.h"
#include"teaser.h"
#include"camera.h"

BT_CMD _cmd = NOTHING;


unsigned long timer;
bool teaser1 = false;
bool teaser2 = false;
bool teaser3 = false;

void loop() {

  timer = millis();
  
  _cmd = ask_BT();
  switch(_cmd){

    case ADVANCE:
      Advance();
      break;
      
    case BACK:
      Back();
      break;

    case TURN_LEFT:
      Left_Turn();
      break;
      
    case TURN_RIGHT:
      Right_Turn();
      break;
      
    case BUZZ1:
      Serial.println("BUZZ1");
      Serial.println("1");
      delay(1000);
      break;

    case BUZZ2:
      Serial.println("BUZZ2");
      break;
      
    case BUZZ3: 
      Serial.println("BUZZ3");
      break;

    case CAMERA:
      Serial.println("CAMERA");
      Serial.println("2");
      delay(1000);
      String photo = readSerialPort();
      BT.println(photo);
      Serial.println("SENT");
      break;

    case HALT:
      Serial.println("SHUT DOWN");
      Serial.println("0");
      delay(1000);
      break;
      
    default:
      MotorWriting(0, 0);
      
}


  if(_cmd == TEASE1){
    timer = millis();
    teaser1 = true;
    teaser2 = false;
    teaser3 = false;
  }

  if(_cmd == TEASE2){
    timer = millis();
    teaser1 = false;
    teaser2 = true;
    teaser3 = false;
  }

  if(_cmd == TEASE3){
    timer = millis();
    teaser1 = false;
    teaser2 = false;
    teaser3 = true;
  }

  if(_cmd == STOP_TEASE){

    teaser1 = false;
    teaser2 = false;
    teaser3 = false;
  }
  
  Teaser1(timer, teaser1, teaser2, teaser3);
  Teaser2(timer, teaser1, teaser2, teaser3);

}
