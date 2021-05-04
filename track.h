/***************************************************************************/
// File     [track.h]
// Author    [Erik Kuo]
// Synopsis  [Code used for tracking]
// Functions  [MotorWriting, MotorInverter, tracking]
// Modify    [2020/03/27 Erik Kuo]
/***************************************************************************/

#include <SoftwareSerial.h>
#include <Wire.h>

/*if you have no idea how to start*/
/*check out what you have learned from week 1 & 6*/
/*feel free to add your own function for convenience*/

/*===========================import variable===========================*/
extern int _Tp;

/*===========================import variable===========================*/

// Write the voltage to motor.




void MotorWriting(double vL, double vR) {
  // TODO: use L298N to control motor voltage & direction
  if(vL > 0){
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  }
  else{
    vL = -vL;
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  }
  if(vR > 0){
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else{
    vR = -vR;
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
  analogWrite(3, vL);
  analogWrite(5, vR);
}// MotorWriting

// Handle negative motor_PWMR value. 
void MotorInverter(int motor, bool& dir) {
  //Hint: the value of motor_PWMR must between 0~255, cannot write negative value.
}// MotorInverter

// P/PID control Tracking
void tracking(int L3_value,int L2_value,int M,int R2_value, int R3_value){
  // find your own parameters!
  double _Kp = 73; // p term parameter 
  double _Kd = 115; // d term parameter (optional) 
  static double _Ki = 0.1; // i term parameter (optional) (Hint: 不要調太大)
  static double error = 0;
  double vR, vL; // 馬達左右轉速原始值(從PID control 計算出來)。Between -255 to 255.
  double adj_R=1, adj_L=1; // 馬達轉速修正係數。MotorWriting(_Tp,_Tp)如果歪掉就要用參數修正。
  static double d_error = 0, power_correction = 0;
  static bool saturated = false;
  static bool integrate = true;
  static double sum_error = 0;
  static double last_error = 0;
  static int t = 0;
    
  // TODO: complete your P/PID tracking code
  if (L3_value + L2_value +M + R2_value + R3_value != 0){
  error = ((-2)*L3_value + (-1)*L2_value + R2_value + 2*R3_value)/(L3_value + L2_value + R2_value + R3_value);
  }
  else{
    error  = 2*(last_error/abs(last_error));
  }
  d_error = error - last_error;
  power_correction = _Kp*error + _Kd*d_error + _Ki*sum_error;
  if (saturated && error * power_correction > 0)
    {
      integrate = false;
      _Ki = 0;
    }
   else{
    //integrate = true;
    _Ki = 0.1;
   }
    
  vL = _Tp + power_correction;
  vR = _Tp - power_correction;
  
  
  if (vL > 255 || vL < -255 || vR > 255 || vR < -255)
    saturated = true;
  else
    saturated = false;
    
  last_error = error;
  
  if(integrate)
    sum_error += error;
  
  ++t;
  
  if (t>800){
    t = 0;
    sum_error = 0;
  }
  
  if (vL >255)
    vL = 255;
  if (vL > 10 && vL < 80)
    vL = 80;
  if (vL < 0 && vL > -90)
    vL = -90;
  else if (vL < -255)
    vL = -255;
    
  if (vR > 255)
    vR = 255;
  if (vR > 10 && vR < 90)
    vR = 90;
  if (vR < 0 && vR > -100)
    vR = -100 ;
  else if (vR < -255)
    vR = -255;
  
  MotorWriting(adj_L*vL, adj_R*vR);
}// tracking
