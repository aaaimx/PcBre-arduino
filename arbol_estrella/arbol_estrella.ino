/*
  Arduino Slave for Raspberry Pi Master
  i2c_slave_ard.ino
  Connects to Raspberry Pi via I2C
  
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include the Wire library for I2C
#include <Wire.h>

// LED on pin 13
const int ledPin = 10; 
const int ledPin2 = 12; 

void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x0A);
  Serial.begin(9600);
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  // Setup pin 13 as output and turn LED off
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, LOW);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  String cadena="";

  while (Wire.available()) { // loop through all but the last
    cadena+=(char)Wire.read(); // receive byte as a character

    
  }
  cadena=cadena.substring(1);
  Serial.println(cadena);
  if (cadena == "Estrella"){
    digitalWrite(ledPin, HIGH);    
    digitalWrite(ledPin, HIGH);
  }else if(cadena == "Inicio"){
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
  }else if (cadena == "0"{
    digitalWrite(ledPin2, LOW);
  }else if(cadena == "1"){
    
  
  }

}
void loop() {
  delay(100);
}