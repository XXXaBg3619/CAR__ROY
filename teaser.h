#include "motor.h"
AF_DCMotor teaser(1);
void Teaser1(unsigned long t, bool tease1, bool tease2, bool tease3){

  static unsigned long start_time = 0;
  static unsigned long now_time = 0;
  
  static bool start = true;

  
  const int T = 1300;
    
  if(tease1 or now_time - start_time < T){
    
    if(start){
      start_time = t;
      now_time = t;
      start = false;
    }
  
    teaser.run(RELEASE);
    teaser.setSpeed(150);
    
    if(now_time - start_time <= T/2)
        teaser.run(FORWARD);
        
    else{
        teaser.run(BACKWARD);
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

  static unsigned long start_time = 0;
  static unsigned long now_time = 0;
  
  static bool start = true;
  static int T = 300;

  if(tease2 or now_time - start_time < T){
    
    if(start){
      start_time = t;
      now_time = t;
      start = false;
    }
  
    teaser.run(RELEASE);
    teaser.setSpeed(150);
  
    
    if(now_time - start_time <= T/2)
        teaser.run(FORWARD);
        
    else{
        teaser.run(BACKWARD);
        if(now_time - start_time >= T){
          start_time = now_time;
          T += 180;

          if(T >= 1000)
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
