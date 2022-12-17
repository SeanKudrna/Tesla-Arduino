// Partner #1 Name: Rayaan Siddiqi
// Partner #1 NETID: rsiddi29
// Partner #2 Name: Sean Kudrna
// Partner #2 NETID: skudr2
// Main purpose of this file is to get the read input from over the serial communication and interpret it
#include <Wire.h>

const int motorRearLeftPin = 7; 
const int motorRearRightPin = 2; 
const int motorFrontLeftPin = 6; 
const int motorFrontRightPin = 3; 

const int breakLightLeftPin = 8;
const int breakLightRightPin = 9;

const int turnRightLightPin = 5;
const int turnLeftLightPin = 4;

const int trigPin = 11;
const int echoPin = 12;
unsigned long currentTime;

int dist = 100;

void setup() {
  Serial.begin(9600); // port over which we communicate
  pinMode(motorRearLeftPin, OUTPUT);
  pinMode(motorRearRightPin, OUTPUT);
  pinMode(motorFrontLeftPin, OUTPUT);
  pinMode(motorFrontRightPin, OUTPUT);

  pinMode(breakLightLeftPin, OUTPUT);
  pinMode(breakLightRightPin, OUTPUT);

  pinMode(turnRightLightPin, OUTPUT);
  pinMode(turnLeftLightPin, OUTPUT);


  // Ultrasonic sensor
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input

    // Serial Communication
    Wire.begin(9);
    Wire.onReceive(receiveEvent);
}

long duration;
int distance;
int valueReadFromApp = 0;

int currentModeIn = -1; // 0 is manual control, 1 is automated control

void receiveEvent(int bytes) {
  valueReadFromApp = Wire.read();    // read one character from the I2C
}

void loop() {
  Serial.write(valueReadFromApp);
  if (valueReadFromApp == '5') { 
    currentModeIn = 1;
  } else if (valueReadFromApp == '6') { 
    currentModeIn = 0;
  }
  if (currentModeIn == 0) { // handle autonomous mode
    // handle auto detection and distances
    handleCarAutonomously();
  } else if (currentModeIn == 1) { // handle manual mode
    Serial.println("value read from app below");
    Serial.println(valueReadFromApp);
    if (valueReadFromApp == '1') {
      Serial.println("going froward");
      carGoForward();
    } else if (valueReadFromApp == '3') {
      Serial.println("going right");
      carGoRight();
    } else if (valueReadFromApp == '4') {
      Serial.println("going left");
       digitalWrite(turnLeftLightPin, LOW);
       digitalWrite(turnRightLightPin, LOW);
       breakLightsOFF();
       carGoLeft();
    } else if (valueReadFromApp == '7') {
      Serial.println("stopping car");
      carSTOP();
      digitalWrite(turnLeftLightPin, LOW);
      digitalWrite(turnRightLightPin, LOW);
      breakLightsON();
    }
  }
}

void handleCarAutonomously() {
  dist = receiveUltraSonicReading();
  Serial.println(dist);


  // Hit an obstacle
  if (dist <= 30 && dist >7) {
    currentTime = millis();
    Serial.println(currentTime);
    
    // Stop car (1 sec)
    while (millis() < currentTime + 1000) {
      dist = receiveUltraSonicReading();
      Serial.println(dist);
      dist = receiveUltraSonicReading();
      carStop();
    }
    breakLightsOFF();

    // Update currentTime
    currentTime = millis();
   
    // Turn Left or Right (2.4 sec)
    int randNum = random(1, 3);
    while (millis() < currentTime + 2400) {
      //dist = receiveUltraSonicReading();
      //Serial.println(dist);
      switch(randNum) {
        case 1:
          carGoRight();
          digitalWrite(turnRightLightPin, LOW);
          break;
        case 2:
          carGoLeft();
          digitalWrite(turnLeftLightPin, LOW);
          break;
        default:
          break;
      }
    }

    
  } else {
    delay(150);
    carGoForward();
  }
  
}

void breakLightsOFF() { 
  digitalWrite(breakLightLeftPin, LOW);
  digitalWrite(breakLightRightPin, LOW);
}

void breakLightsON() {
  digitalWrite(breakLightLeftPin, HIGH);
  digitalWrite(breakLightRightPin, HIGH);
}

void carStop() {
  breakLightsON();
  digitalWrite(motorFrontLeftPin, LOW);
  digitalWrite(motorRearLeftPin, LOW);
  digitalWrite(motorFrontRightPin, LOW);
  digitalWrite(motorRearRightPin, LOW);
}


int receiveUltraSonicReading() { // purpose of this function is to translate the ultrasonic reading into cm unit number
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  return distance = duration * 0.034 / 2;
}

void carGoForward() {
  digitalWrite(motorFrontLeftPin, HIGH);
  digitalWrite(motorRearLeftPin, HIGH);
  digitalWrite(motorFrontRightPin, HIGH);
  digitalWrite(motorRearRightPin, HIGH);
}

void carGoRight() {
  digitalWrite(turnRightLightPin, HIGH);
  digitalWrite(motorFrontLeftPin, HIGH);
  digitalWrite(motorRearLeftPin, HIGH);
  digitalWrite(motorFrontRightPin, LOW);
  digitalWrite(motorRearRightPin, LOW);
}

void carGoLeft() {
  digitalWrite(turnLeftLightPin, HIGH);
  digitalWrite(motorFrontLeftPin, LOW);
  digitalWrite(motorRearLeftPin, LOW);
  digitalWrite(motorFrontRightPin, HIGH);
  digitalWrite(motorRearRightPin, HIGH);
}

void carSTOP() {
  digitalWrite(motorFrontLeftPin, LOW);
  digitalWrite(motorRearLeftPin, LOW);
  digitalWrite(motorFrontRightPin, LOW);
  digitalWrite(motorRearRightPin, LOW);
}
