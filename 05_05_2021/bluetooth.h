/***************************************************************************/
// File        [bluetooth.h]
// Author     [Erik Kuo]
// Synopsis   [Code for bluetooth communication]
// Functions  [ask_BT, send_msg, send_byte]
// Modify     [2020/03/27 Erik Kuo]
/***************************************************************************/

/*if you have no idea how to start*/
/*check out what you have learned from week 2*/

#include<SoftwareSerial.h>
enum BT_CMD {
  NOTHING,
  ADVANCE,
  U_TURN,
  TURN_RIGHT,
  TURN_LEFT,
  HALT,
  BACK,
  // TODO: add your own command type here
};

BT_CMD ask_BT(){
    BT_CMD message=NOTHING;
    char cmd;
    if(BT.available()){
      // TODO:
      // 1. get cmd from SoftwareSerial object: BT
      cmd = BT.read();
      // 2. link bluetooth message to your own command type
      message = cmd - 48;
      #ifdef DEBUG
//      Serial.print("cmd : ");
//      Serial.println(cmd);
      #endif
    }
//    Serial.print("msg : ");
//    Serial.println(message);
    return message;
}// ask_BT

// send msg back through SoftwareSerial object: BT
// can use send_byte alternatively to send msg back
// (but need to convert to byte type)
void send_msg(const char& msg)
{
     // TODO:
     byte b_msg = (byte)msg;
     Serial.print("message sent : ");
     Serial.println(b_msg);
     BT.write(b_msg);
      
}// send_msg

// send UID back through SoftwareSerial object: BT
void send_byte(byte *id, byte& idSize) {
  for (byte i = 0; i < idSize; i++) {  // Send UID consequently.
    BT.write(id[i]);
  }
  #ifdef DEBUG
  Serial.print("Sent id: ");
  for (byte i = 0; i < idSize; i++) {  // Show UID consequently.
    Serial.print(id[i], HEX);
  }
  Serial.println();
  #endif
}// send_byte
