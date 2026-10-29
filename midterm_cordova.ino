
// 1. Pin Definitions (Using safe GPIOs)
const int OUT = 4;          // Move IR Sensor to a safe pin like GPIO 4 (avoiding strapping pin GPIO 2)

const int sw1Pin = 15;      // Move Switch 1 away from GPIO 3 (RX) to 
GPIO 15

const int sw2Pin = 16;


int Number_of_Object = 0;   
int SensorState = 0;        
int lastSensorState = HIGH; 

int sw1 = 0;
int sw2 = 0;
int mode = 1;               


const int LED_10s[7] = {32, 33, 25, 26, 27, 14, 13};
const int LED_1s[7]  = {19, 18, 5, 17, 23, 22, 21};

#include "Decode.h"

void setup() {
  Serial.begin(115200);


  pinMode(OUT, INPUT);
  pinMode(sw1Pin, INPUT);
  pinMode(sw2Pin, INPUT);

  for(int i = 0; i < 7; i++){
    pinMode(LED_10s[i], OUTPUT);
    pinMode(LED_1s[i], OUTPUT);
  }

  Serial.println("System Initialized: Object Counter with Switch Modes & Dual 7-Segment Display...");
}


void loop() {

  sw1 = digitalRead(sw1Pin);
  sw2 = digitalRead(sw2Pin);

  if (sw1 == 0 && sw2 == 0) {
    mode = 1;
  } 
  else if (sw1 == 0 && sw2 == 1) {
    mode = -1;
  } 
  else if (sw1 == 1 && sw2 == 0) {
    mode = 2;
  } 
  else if (sw1 == 1 && sw2 == 1) {
    mode = -2;
  }

  
  SensorState = digitalRead(OUT);


  if (SensorState == LOW && lastSensorState == HIGH) {
    Number_of_Object += mode;  

   
    if (Number_of_Object > 99) {
      Number_of_Object = 0;
    } else if (Number_of_Object < 0) {
      Number_of_Object = 99;
    }

    Serial.print("SW1: "); Serial.print(sw1);
    Serial.print(" | SW2: "); Serial.print(sw2);
    Serial.print(" | Mode: "); Serial.print(mode > 0 ? "+" : ""); Serial.print(mode);
    Serial.print(" | Total Objects: "); Serial.println(Number_of_Object);

    delay(200); // Debounce delay
  }

  // 4. Update 7-Segment Displays using Decode.h functions
  decode(Number_of_Object);
  display();

  // Save current state for next loop iteration
  lastSensorState = SensorState;
}
