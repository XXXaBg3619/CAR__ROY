#include <SoftwareSerial.h>
#include <Wire.h>
#include <AFMotor.h>

AF_DCMotor motor_L(3);
AF_DCMotor motor_R(4);

void MotorWriting(double vL, double vR) {
  motor_L.run(RELEASE);
  motor_R.run(RELEASE);
  
  if(vL >= 0 and vR >= 0){
    motor_L.run(FORWARD);
    motor_R.run(FORWARD);
    motor_L.setSpeed(vL);
    motor_R.setSpeed(vR);
  }
  else if(vL < 0 and vR >= 0){
    motor_L.run(BACKWARD);
    motor_R.run(FORWARD);
    motor_L.setSpeed(-vL);
    motor_R.setSpeed(vR);
  }
  else if(vL >= 0 and vR < 0){
    motor_L.run(FORWARD);
    motor_R.run(BACKWARD);
    motor_L.setSpeed(vL);
    motor_R.setSpeed(-vR);
  }
  else{
    motor_L.run(BACKWARD);
    motor_R.run(BACKWARD);
    motor_L.setSpeed(-vL);
    motor_R.setSpeed(-vR);
  }
}

void Advance(){
    MotorWriting(200, 200);
    delay(15);
}

void Back(){
    MotorWriting(-200,-200);
    delay(15);
}

void Left_Turn(){
    MotorWriting(-200,200);
    delay(15);
}

void Right_Turn(){
    MotorWriting(200,-200);
    delay(15);
}
