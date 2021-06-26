
String readSerialPort(){
  Serial.setTimeout(5000);
  String msg = "";
  char rx_byte;
  while(!Serial.available()){
    delay(100);
  }
//  msg += (char)Serial.read();
//  delay(10);
  while(true) {
    if(Serial.available()){
      rx_byte = Serial.read();
      if(rx_byte != '*'){
        msg += rx_byte;
      }
      else{
        Serial.println("msg returned");
        Serial.println(msg);
        return msg;
      }
     
    }
    
  }
  
//  char end_char = '\n';
//  msg = Serial.readStringUntil(end_char);
//  Serial.flush();

    
  
  
  
}
