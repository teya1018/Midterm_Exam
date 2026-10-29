#include "Arduino.h"

const byte digital0 = 0b0111111; 
const byte digital1 = 0b0000110; 
const byte digital2 = 0b1011011; 
const byte digital3 = 0b1001111; 
const byte digital4 = 0b1100110; 
const byte digital5 = 0b1101101; 
const byte digital6 = 0b1111101; 
const byte digital7 = 0b0000111; 
const byte digital8 = 0b1111111; 
const byte digital9 = 0b1101111; 


uint8_t tens = 0;
uint8_t ones = 0;

 byte current_nums_10s = digital0;
 byte current_nums_1s = digital0;


void decode(int a) {
  tens = Number_of_Object / 10;
  ones = Number_of_Object % 10;
  switch(tens) {
    case 0: current_nums_10s = digital0; break;
    case 1: current_nums_10s = digital1; break;
    case 2: current_nums_10s = digital2; break;
    case 3: current_nums_10s = digital3; break;
    case 4: current_nums_10s = digital4; break;
    case 5: current_nums_10s = digital5; break;
    case 6: current_nums_10s = digital6; break;
    case 7: current_nums_10s = digital7; break;
    case 8: current_nums_10s = digital8; break;
    case 9: current_nums_10s = digital9; break;
  }
  
  switch(ones) {
    case 0: current_nums_1s = digital0; break;
    case 1: current_nums_1s = digital1; break;
    case 2: current_nums_1s = digital2; break;
    case 3: current_nums_1s = digital3; break;
    case 4: current_nums_1s = digital4; break;
    case 5: current_nums_1s = digital5; break;
    case 6: current_nums_1s = digital6; break;
    case 7: current_nums_1s = digital7; break;
    case 8: current_nums_1s = digital8; break;
    case 9: current_nums_1s = digital9; break;
  }
}
void display() {
  for(int i = 0; i < 7; i++){
    digitalWrite(LED_10s[i], bitRead(current_nums_10s, i));
    digitalWrite(LED_1s[i], bitRead(current_nums_1s, i));
    sw1 = digitalRead(sw1Pin);
    sw2 = digitalRead(sw2Pin);
  }
}
