///***************************************************************************/
//// File       [final_project.ino]
//// Author     [Erik Kuo]
//// Synopsis   [Code for managing main process]
//// Functions  [setup, loop, Search_Mode, Hault_Mode, SetState]
//// Modify     [2020/03/27 Erik Kuo]
///***************************************************************************/
//
//#define DEBUG // debug flag
//
//// for BlueTooth
//#include<SoftwareSerial.h>
//// for RFID
//#include <SPI.h>
//#include <MFRC522.h>
//
///*===========================define pin & create module object================================*/
//// BlueTooth
//SoftwareSerial BT(9,8);   // TX,RX on bluetooth module, 請按照自己車上的接線寫入腳位
//// L298N, 請按照自己車上的接線寫入腳位(左右不一定要跟註解寫的一樣)
//#define MotorR_I1     2  //定義 I1 接腳（右）
//#define MotorR_I2     4  //定義 I2 接腳（右）
//#define MotorL_I3     6  //定義 I3 接腳（左）
//#define MotorL_I4     7  //定義 I4 接腳（左）
//#define MotorL_PWML   3  //定義 ENA (PWM調速) 接腳
//#define MotorR_PWMR   5  //定義 ENB (PWM調速) 接腳
//// 循線模組, 請按照自己車上的接線寫入腳位
//#define L3   A5  // Define Left Most Sensor Pin
//#define L2   A4  // Define Left Middle Sensor Pin
//#define M    A3  // Define Middle Sensor Pin
//#define R2   A2  // Define Right Middle Sensor Pin
//#define R3   A1  // Define Right Most Sensor Pin
//
//// RFID, 請按照自己車上的接線寫入腳位
//#define RST_PIN      10        // 讀卡機的重置腳位
//#define SS_PIN       A0        // 晶片選擇腳位
//MFRC522 mfrc522(SS_PIN, RST_PIN);  // 建立MFRC522物件
///*===========================define pin & create module object===========================*/
//
///*============setup============*/
//void setup()
//{
//   //bluetooth initialization
//   BT.begin(9600);
//   //Serial window
//   Serial.begin(9600);
//   //RFID initial
//   SPI.begin();
//   mfrc522.PCD_Init();
//   //L298N pin
//   pinMode(MotorR_I1,   OUTPUT);
//   pinMode(MotorR_I2,   OUTPUT);
//   pinMode(MotorL_I3,   OUTPUT);
//   pinMode(MotorL_I4,   OUTPUT);
//   pinMode(MotorL_PWML, OUTPUT);
//   pinMode(MotorR_PWMR, OUTPUT);
//   //tracking pin
//   pinMode(R2, INPUT);
//   pinMode(R3, INPUT);
//   pinMode(M, INPUT);
//   pinMode(L2, INPUT);
//   pinMode(L3, INPUT);
//#ifdef DEBUG
//  Serial.println("Start!");
//#endif
//}
///*============setup============*/
//
///*=====Import header files=====*/
//#include "RFID.h"
////#include "track.h"
//#include "bluetooth.h"
//#include "node.h"
///*=====Import header files=====*/
//
///*===========================initialize variables===========================*/
//int r2=0, r3=0, m=0, l3=0, l2=0; //紅外線模組的讀值(0->white,1->black)
//int _Tp=90; //set your own value for motor power
//bool start = false, state=false; //set state to false to halt the car, set state to true to activate the car
//BT_CMD _cmd = NOTHING; //enum for bluetooth message, reference in bluetooth.h line 2
///*===========================initialize variables===========================*/
//
///*===========================declare function prototypes===========================*/
//void Search();// search graph
//void SetState();// switch the state
///*===========================declare function prototypes===========================*/
//
///*===========================define function===========================*/
//void loop()
//{
//   if(!state or !start) {
//    Serial.println("HALT");
//    delay(5000);
//    MotorWriting(0,0);
//   }
//
//   else Search();
//   SetState();
//}
//
//void SetState()
//{
//  // TODO:
//  // 1. Get command from bluetooth 
//  _cmd = ask_BT();
//  // 2. Change state if need
//  if(_cmd == HALT or !start) {
//    //Serial.print("HH");
//    state = false;
//  }
//
//    state = false;
//  if(_cmd == 67){
//    Serial.println("start = true");
//    start = true;
//    state = true;
//  }
//  else
//    state = true;
//  
//}
//
//bool at_node = false;
//void Search()
//{
//  // TODO: let your car search graph(maze) according to bluetooth command from computer(python code)
//   
//  if(_cmd == ADVANCE);
//    //MotorWriting(1,1);
//      
//  else if(_cmd == U_TURN);
//    //U_Turn();
//     
//  else if(_cmd == TURN_LEFT);
//    //Left_Turn();
//      
//  else if(_cmd == TURN_RIGHT);
//    //Right_Turn();
//
//
//  l3 = digitalRead(L3);
//  l2 = digitalRead(L2);
//  m = digitalRead(M);
//  r2 = digitalRead(R2);
//  r3 = digitalRead(R3);
//  tracking(l3, l2, m, r2, r3);
// 
//    
//  byte idSize;
//  //Serial.println("ID");
//  delay(5000);
//  byte* id = rfid(idSize);
//  if(id != 0){
//    send_msg('2');
//    send_byte(id, idSize);
//    at_node = true;
//  }
//
//   
//  else if(r2*r3*m*l2*l3 != 0 and !at_node){
//    send_msg('1');
//    at_node = true;
//    MotorWriting(0, 0);
//  }
//  else
//    at_node = false;
//  
//}
///*===========================define function===========================*/




/***************************************************************************/
// File       [final_project.ino]
// Author     [Erik Kuo]
// Synopsis   [Code for managing main process]
// Functions  [setup, loop, Search_Mode, Hault_Mode, SetState]
// Modify     [2020/03/27 Erik Kuo]
/***************************************************************************/

#define DEBUG // debug flag

// for BlueTooth
#include<SoftwareSerial.h>
//// for RFID
//#include <SPI.h>
//#include <MFRC522.h>

/*===========================define pin & create module object================================*/
// BlueTooth
SoftwareSerial BT(9,8);   // TX,RX on bluetooth module, 請按照自己車上的接線寫入腳位
// L298N, 請按照自己車上的接線寫入腳位(左右不一定要跟註解寫的一樣)
#define MotorR_I1     2  //定義 I1 接腳（右）
#define MotorR_I2     4  //定義 I2 接腳（右）
#define MotorL_I3     6  //定義 I3 接腳（左）
#define MotorL_I4     7  //定義 I4 接腳（左）
#define MotorL_PWML   3  //定義 ENA (PWM調速) 接腳
#define MotorR_PWMR   5  //定義 ENB (PWM調速) 接腳
// 循線模組, 請按照自己車上的接線寫入腳位
#define L3   A5  // Define Left Most Sensor Pin
#define L2   A4  // Define Left Middle Sensor Pin
#define M    A3  // Define Middle Sensor Pin
#define R2   A2  // Define Right Middle Sensor Pin
#define R3   A1  // Define Right Most Sensor Pin

// RFID, 請按照自己車上的接線寫入腳位
//#define RST_PIN      10        // 讀卡機的重置腳位
//#define SS_PIN       A0        // 晶片選擇腳位
//MFRC522 mfrc522(SS_PIN, RST_PIN);  // 建立MFRC522物件
/*===========================define pin & create module object===========================*/

/*============setup============*/
void setup()
{
   BT.begin(9600);
   //Serial window
   Serial.begin(9600);
   //RFID initial
//   SPI.begin();
//   mfrc522.PCD_Init();
   //L298N pin
   pinMode(MotorR_I1,   OUTPUT);
   pinMode(MotorR_I2,   OUTPUT);
   pinMode(MotorL_I3,   OUTPUT);
   pinMode(MotorL_I4,   OUTPUT);
   pinMode(MotorL_PWML, OUTPUT);
   pinMode(MotorR_PWMR, OUTPUT);
   //tracking pin
   pinMode(R2, INPUT);
   pinMode(R3, INPUT);
   pinMode(M, INPUT);
   pinMode(L2, INPUT);
   pinMode(L3, INPUT);
#ifdef DEBUG
  Serial.println("Start!");
#endif
}
/*============setup============*/

/*=====Import header files=====*/

//#include "track.h"
#include "bluetooth.h"
#include "node.h"

/*=====Import header files=====*/

/*===========================initialize variables===========================*/
//int r2=0, r3=0, m=0, l3=0, l2=0; //紅外線模組的讀值(0->white,1->black)
int _Tp = 100; //set your own value for motor power
bool start = false, state=false; //set state to false to halt the car, set state to true to activate the car
BT_CMD _cmd = NOTHING; //enum for bluetooth message, reference in bluetooth.h line 2
/*===========================initialize variables===========================*/

/*===========================declare function prototypes===========================*/
void Search();// search graph
void SetState();// switch the state
/*===========================declare function prototypes===========================*/

/*===========================define function===========================*/
void loop()
{
   if(!state or !start) {
    Serial.println("HALT");
    delay(5000);
    MotorWriting(0,0);
    delay(5000);
   }

   else Search();
   SetState();
 
    
}

void SetState()
{
  // TODO:
  // 1. Get command from bluetooth 
  _cmd = ask_BT();
  // 2. Change state if need
  if(_cmd == HALT or !start) {
    //Serial.print("HH");
    state = false;
  }

    state = false;
  if(_cmd == 67){
    Serial.println("start = true");
    start = true;
    state = true;
  }
  else if(_cmd == 53){

    start = false;
    state = false;
  }
  else
    state = true;
  
}

bool at_node = false;
bool all_black = false;
int L3_value;
int L2_value;
int M_value;
int R2_value;
int R3_value;

void Search(){

  L3_value = digitalRead(L3);
  L2_value = digitalRead(L2);
  M_value = digitalRead(M);
  R2_value = digitalRead(R2);
  R3_value = digitalRead(R3);

  if(_cmd == ADVANCE){
    MotorWriting(180,180);
    delay(300);
  }

     
  else if(_cmd == U_TURN)
    U_Turn();
     
  else if(_cmd == TURN_LEFT)
    Left_Turn(L3_value, L2_value, M_value, R2_value, R3_value);
      
  else if(_cmd == TURN_RIGHT)
    Right_Turn(L3_value, L2_value, M_value, R2_value, R3_value);


  L3_value = digitalRead(L3);
  L2_value = digitalRead(L2);
  M_value = digitalRead(M);
  R2_value = digitalRead(R2);
  R3_value = digitalRead(R3);
  tracking(L3_value,L2_value,M_value,R2_value, R3_value);

  all_black = L2_value*M_value*R2_value*R3_value != 0 or L3_value*L2_value*M_value*R2_value != 0;

  if(!all_black)
    at_node = false;
    
  else if(all_black and !at_node){
    
    send_msg('1');
    at_node = true;
    MotorWriting(0, 0);
    
  }

  
  
 

  
}
