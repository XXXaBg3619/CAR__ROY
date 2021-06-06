#include<SoftwareSerial.h>
enum BT_CMD {
  
  NOTHING,
  ADVANCE,
  BACK,
  TURN_LEFT,
  TURN_RIGHT,
  BUZZ,
  TEASE1,
  TEASE2,
  TEASE3,
  HALT

};

BT_CMD ask_BT(){
  
    BT_CMD message = NOTHING;
    char cmd;
    if(BT.available()){
      
      cmd = BT.read();
      message = cmd - 48;
    }
    return message;
    
}
