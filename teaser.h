#include "motor.h"
AF_DCMotor teaser(3);
void Teaser1(unsigned long t, bool tease){

  static bool start = true;

  static unsigned long start_time = 0;
  static unsigned long now_time = 0;
  
  if(tease or start_time != now_time){
    
    if(start){
      start_time = t;
      now_time = t;
      start = false;
    }
  
    teaser.run(RELEASE);
    teaser.setSpeed(150);
  
    const int T = 3000;
    
    if(start_time - now_time <= T)
        teaser.run(FORWARD);
        
    else{
        teaser.run(BACKWARD);
        if(now_time - start_time <= T)
          start_time = now_time;
    }
  
    now_time = millis();
  }

  else{

    teaser.setSpeed(0);
    start = true;
    
  }
}
