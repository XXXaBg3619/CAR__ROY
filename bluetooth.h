enum RPI_CMD {
  
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

RPI_CMD ask_RPI(){
  
    RPI_CMD message = NOTHING;

    String cmd;
    if(Serial.available()){
      
      cmd = Serial.readString();
      message = cmd.toInt();

      
    }
    return message;
    
}
