#include "motor.h"

AF_DCMotor teaser(1);
void Teaser1(unsigned long t, bool tease1, bool tease2, bool tease3){

  static bool start = true;
  const int T = 1500;
  
  static unsigned long start_time = 0;
  static unsigned long now_time = T;
  
  if(tease1 or now_time - start_time < T){
    
    if(start){
      start_time = t;
      now_time = t;
      start = false;
    }
  
    teaser.run(RELEASE);
    teaser.setSpeed(250);
    
    if(now_time - start_time <= T/4)
        teaser.run(FORWARD);
        
    else if(now_time - start_time >= T/4 and now_time - start_time <= 3*T/4)
        teaser.run(BACKWARD);
    else{
        teaser.run(FORWARD);
        if(now_time - start_time >= T)
          start_time = now_time;
    }
  
    now_time = millis();
  }

  else if (tease2 or tease3){
    start = true;
  }
  else{
    teaser.setSpeed(0);
    start = true;
  }
}

void Teaser2(unsigned long t, bool tease1, bool tease2, bool tease3){

  static bool start = true;
  static int T = 300;

  static unsigned long start_time = 0;
  static unsigned long now_time = T;
  
  if(tease2 or now_time - start_time < T){
    
    if(start){
      start_time = t;
      now_time = t;
      start = false;
    }
  
    teaser.run(RELEASE);
    teaser.setSpeed(250);
    
    if(now_time - start_time <= T/4)
        teaser.run(FORWARD);
        
    else if(now_time - start_time >= T/4 and now_time - start_time <= 3*T/4) 
        teaser.run(BACKWARD);
    else{
      teaser.run(FORWARD);
        if(now_time - start_time >= T){
          start_time = now_time;
          T += 180;

          if(T >= 1400)
            T = 300;
        }
    }

    now_time = millis();
      
  }

  else if(tease1 or tease3){
    start = true;
  }
  else{
    teaser.setSpeed(0);
    start = true;
  }
}


void Teaser3(unsigned long t, bool tease1, bool tease2, bool tease3){

  static bool start = true;
  const int T = 1500;
  
  static unsigned long start_time = 0;
  static unsigned long now_time = T;
  
  if(tease3 or now_time - start_time < T){
    
    if(start){
      start_time = t;
      now_time = t;
      start = false;
    }
  
    teaser.run(RELEASE);
    
    
    if(now_time - start_time <= T/4){
      if(now_time - start_time >= T/16 and now_time - start_time <= 3*T/16)
        teaser.setSpeed(0);
      else{
        teaser.setSpeed(250);
        teaser.run(FORWARD);
      }
      
    }
        
        
    else if(now_time - start_time >= T/4 and now_time - start_time <= 3*T/4)
      if(now_time - start_time >= 5*T/16 and now_time - start_time <= 7*T/16)
        teaser.setSpeed(0);
      else if(now_time - start_time >= 9*T/16 and now_time - start_time <= 11*T/16)
        teaser.setSpeed(0);
      else{
        teaser.setSpeed(250);
        teaser.run(BACKWARD);
      }
    else{
      if(now_time - start_time >= 13*T/16 and now_time - start_time <= 15*T/16)
        teaser.setSpeed(0);
      else{
        teaser.setSpeed(250);
        teaser.run(FORWARD);
      }
      if(now_time - start_time >= T)
          start_time = now_time;
    }
  
    now_time = millis();
  }

  else if (tease2 or tease3){
    start = true;
  }
  else{
    teaser.setSpeed(0);
    start = true;
  }
}
