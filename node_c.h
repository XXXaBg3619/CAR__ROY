/***************************************************************************/
// File			  [node.h]
// Author		  [Erik Kuo, Joshua Lin]
// Synopsis		[Code for managing car movement when encounter a node]
// Functions  [/* add on yout own! */]
// Modify		  [2020/03/027 Erik Kuo]
/***************************************************************************/

#include <SoftwareSerial.h>
#include <Wire.h>
#include "track.h"
/*===========================import variable===========================*/
int extern r1, l1, r2, l2, r3, l3;
int extern _Tp;
/*===========================import variable===========================*/

// TODO: add some function to control your car when encounter a node
// here are something you can try: left_turn, right_turn... etc.

void Advance(int L3_value, int L2_value, int M_value, int R2_value, int R3_value){

  
  while(L2_value*M_value*R2_value*R3_value != 0 or L3_value*L2_value*M_value*R2_value != 0){

    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
    MotorWriting(85, 103);
    delay(15);
  }
  
}

void U_Turn(){
// 指定題參數
//  MotorWriting(-180, 150);
//  delay(845);
  MotorWriting(-130, 100);
  delay(1000);

  
}

void Left_Turn(int L3_value, int L2_value, int M_value, int R2_value, int R3_value){

    

    while(L2_value*M_value*R2_value*R3_value != 0 or L3_value*L2_value*M_value*R2_value != 0){

    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
    MotorWriting(75, 75);
    delay(15);
    
  }

  MotorWriting(0,0);
  delay(30);
  MotorWriting(-150,180);
  delay(185);

  
  while(L3_value + L2_value + M_value + R2_value + R3_value != 0){
    MotorWriting(-150,180);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);

  }
  
  while(L3_value + L2_value + M_value + R2_value + R3_value == 0){
    MotorWriting(-150,180);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
  }

}

void Right_Turn(int L3_value, int L2_value, int M_value, int R2_value, int R3_value){

    while(L2_value*M_value*R2_value*R3_value != 0 or L3_value*L2_value*M_value*R2_value != 0){

    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
    MotorWriting(75,75);
    delay(20);

    
  }
  MotorWriting(0,0);
  delay(30);
  MotorWriting(130,-210);
  delay(150);

  while(L3_value + L2_value + M_value + R2_value + R3_value != 0){
    MotorWriting(130,-210);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);

  }
  
  while(L3_value + L2_value + M_value + R2_value + R3_value == 0){
    MotorWriting(130,-210);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
  }

}
//
//void Back(int L3_value, int L2_value, int M_value, int R2_value, int R3_value){
//
//
//}
