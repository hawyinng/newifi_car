#include "Arduino.h"

int PIN_CAR_IN1 = 4;  
int PIN_CAR_IN2 = 5; 
int PIN_CAR_IN3 = 6;  
int PIN_CAR_IN4 = 7;

char incomingByte;

void doForward() {  
  //Serial.println("doForward\n");
  //front motor
  digitalWrite(PIN_CAR_IN1,LOW);  
  digitalWrite(PIN_CAR_IN2,LOW); 
  //back motor 
  digitalWrite(PIN_CAR_IN3,HIGH);  
  digitalWrite(PIN_CAR_IN4,HIGH);
}  

void doBackward() {  
  //Serial.println("doBackward\n");
  digitalWrite(PIN_CAR_IN1,LOW);  
  digitalWrite(PIN_CAR_IN2,LOW); 
  digitalWrite(PIN_CAR_IN3,LOW);  
  digitalWrite(PIN_CAR_IN4,HIGH);  
}  

void doLeft() {  
  //Serial.println("doLeft\n");
  //trun left-forward
  digitalWrite(PIN_CAR_IN1,HIGH);  
  digitalWrite(PIN_CAR_IN2,HIGH);   
  digitalWrite(PIN_CAR_IN3,HIGH);  
  digitalWrite(PIN_CAR_IN4,HIGH);
} 

void doLeft_back() {  
  //Serial.println("doLeft_back\n");
  digitalWrite(PIN_CAR_IN1,HIGH);  
  digitalWrite(PIN_CAR_IN2,HIGH);   
  digitalWrite(PIN_CAR_IN3,LOW);  
  digitalWrite(PIN_CAR_IN4,HIGH);
} 
  
void doRight() {  
  //trun right-forward
  //Serial.println("doRight\n");
  digitalWrite(PIN_CAR_IN1,LOW);  
  digitalWrite(PIN_CAR_IN2,HIGH);
  digitalWrite(PIN_CAR_IN3,HIGH);  
  digitalWrite(PIN_CAR_IN4,HIGH);   
} 

void doRight_back() {  
  //Serial.println("doRight_back\n");
  digitalWrite(PIN_CAR_IN1,LOW);  
  digitalWrite(PIN_CAR_IN2,HIGH);
  digitalWrite(PIN_CAR_IN3,LOW);  
  digitalWrite(PIN_CAR_IN4,HIGH);   
} 
  
void doStop() {  
  //Serial.println("doStop\n");
  digitalWrite(PIN_CAR_IN1,LOW);  
  digitalWrite(PIN_CAR_IN2,LOW); 
  digitalWrite(PIN_CAR_IN3,LOW);  
  digitalWrite(PIN_CAR_IN4,LOW);
}  
  
void setup()  
{  
  pinMode(PIN_CAR_IN1,OUTPUT);  
  pinMode(PIN_CAR_IN2,OUTPUT);  
  pinMode(PIN_CAR_IN3,OUTPUT);  
  pinMode(PIN_CAR_IN4,OUTPUT);  
  
  //digitalWrite(PIN_CAR_IN1, OUTPUT);  
  //digitalWrite(PIN_CAR_IN2, OUTPUT);  
  //digitalWrite(PIN_CAR_IN3, OUTPUT);  
  //digitalWrite(PIN_CAR_IN4, OUTPUT);  
  
  Serial.begin(9600);  
}  
  
void loop()  
{  
  //Serial.println("hello world\n"); 
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    while((incomingByte=Serial.read())>=0){
      switch (incomingByte) {
        case '1':
          // statements
          doForward();
          break;
        case '2':
          // statements
          doBackward();
          break;
        case '3':
          // statements
          doLeft();
          break;
        case '4':
          // statements
          doRight();
          break;
        case '5': 
          // statements
          doStop();
          break;
        case '6':
          doLeft_back();
          break;
        case '7':
          doRight_back();
          break;
      }
       
      //doStop();
      //incomingByte = 0; 
      //Serial.flush();
      delay(500);
    }
    // say what you got:
    //Serial.print("I received: ");
    //Serial.println(incomingByte, DEC);
  }
}  
