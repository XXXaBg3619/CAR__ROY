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
    MotorWriting(160, 160);
    delay(35);
  }
  
}

void U_Turn(){
//  MotorWriting(80, 80);
//  delay(90);
  MotorWriting(-200, 200);
  delay(845);
  
}

void Left_Turn(int L3_value, int L2_value, int M_value, int R2_value, int R3_value){

    while(L2_value*M_value*R2_value*R3_value != 0 or L3_value*L2_value*M_value*R2_value != 0){

    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
    MotorWriting(90, 90);
    delay(25);
    
  }
  MotorWriting(0,0);
  delay(30);

  while(L3_value + L2_value + M_value + R2_value + R3_value != 0){
    MotorWriting(-130,200);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);

  }
  
  while(L3_value + L2_value + M_value + R2_value + R3_value == 0){
    MotorWriting(-130,200);
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
    MotorWriting(80,80);
    delay(20);

    
  }
  MotorWriting(0,0);
  delay(30);

  while(L3_value + L2_value + M_value + R2_value + R3_value != 0){
    MotorWriting(140,-203);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);

  }
  
  while(L3_value + L2_value + M_value + R2_value + R3_value == 0){
    MotorWriting(140,-203);
    delay(25);
    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
  }

}

void Back(int L3_value, int L2_value, int M_value, int R2_value, int R3_value){
  MotorWriting(-90,-135);
  delay(1200);
  
  
  while(L2_value*M_value*R2_value*R3_value == 0 or L3_value*L2_value*M_value*R2_value == 0){

    L3_value = digitalRead(A5);
    L2_value = digitalRead(A4);
    M_value = digitalRead(A3);
    R2_value = digitalRead(A2);
    R3_value = digitalRead(A1);
    MotorWriting(90,90);
    delay(20);
  }

}
