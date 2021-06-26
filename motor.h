#include <SoftwareSerial.h>
#include <Wire.h>
#include <AFMotor.h>

AF_DCMotor motor_L(4);
AF_DCMotor motor_R(3);

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
    MotorWriting(240, 255);
    delay(100);
    MotorWriting(0, 0);
}

void Back(){
    MotorWriting(-240,-255);
    delay(100);
    MotorWriting(0, 0);
}

void Left_Turn(){
    MotorWriting(-255,255);
    delay(100);
    MotorWriting(0, 0);
}

void Right_Turn(){
    MotorWriting(255,-255);
    delay(100);
    MotorWriting(0, 0);
}
