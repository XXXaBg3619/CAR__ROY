#include<SoftwareSerial.h>
enum BT_CMD {
  
  NOTHING,
  ADVANCE,
  BACK,
  TURN_LEFT,
  TURN_RIGHT,
  BUZZ1,
  BUZZ2,
  BUZZ3,
  TEASE1,
  TEASE2,
  TEASE3,
  STOP_TEASE,
  CAMERA,
  HALT

};

BT_CMD ask_BT(){
  
    BT_CMD message = NOTHING;
    byte cmd;
    if(BT.available()){
      
      cmd = BT.read();
      message = cmd;
      
    }
    return message;
    
}
