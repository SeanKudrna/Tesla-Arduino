// Main purpose of this file is to get the input from the app
#include <Wire.h>

char incomingValue = 0;

void setup() {
  Serial.begin(9600);       
  Wire.begin();  
}


// INCOMING SIGNAL MEANINGS
// 1 == FORWARD
// 2 == BACKWARD
// 3 == RIGHT
// 4 == LEFT
// 5 == MANUAL MODE
// 6 == AUTOMATED MODE

void loop(){
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write('5');   
  Wire.endTransmission();
      
//  if(Serial.available() > 0){
//    incomingValue = Serial.read();      
//    if(incomingValue == '1'){ 
//      Wire.beginTransmission(9); // transmit to device #9
//      Wire.write('1');   
//      Wire.endTransmission();
//    } else if (incomingValue == '2') {
//      Wire.beginTransmission(9); // transmit to device #9
//      Wire.write('2');   
//      Wire.endTransmission();
//    } else if (incomingValue == '3') {
//      Wire.beginTransmission(9); // transmit to device #9
//      Wire.write('3');   
//      Wire.endTransmission();
//    } else if (incomingValue == '4') {
//      Wire.beginTransmission(9); // transmit to device #9
//      Wire.write('4');   
//      Wire.endTransmission();
//    } else if (incomingValue == '5') {
//      Wire.beginTransmission(9); // transmit to device #9
//      Wire.write('5');   
//      Wire.endTransmission();
//    } else if (incomingValue == '6') {
//      Wire.beginTransmission(9); // transmit to device #9
//      Wire.write('6');   
//      Wire.endTransmission();
//    }
//  }                            
} 
