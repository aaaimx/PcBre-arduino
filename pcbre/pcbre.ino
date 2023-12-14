#include <Wire.h>
const int led = 3;
const int ventilador = 11;

void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x0B);
  Serial.begin(9600);
  // Call receiveEvent when data received
  Wire.onReceive(receiveEvent);

  // Setup pin 13 as output and turn LED off
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(ventilador, OUTPUT);
  digitalWrite(ventilador, LOW);
}
void receiveEvent(int howMany) {
while (Wire.available()) { // loop through all but the last
    char c =Wire.read(); // receive byte as a character
    digitalWrite(ventilador,c);
    digitalWrite(led,c);
    
  }
}

void inicio() {
  digitalWrite(led, HIGH);
  digitalWrite(ventilador, HIGH);
}
void apagar() {
  digitalWrite(led, LOW);
  digitalWrite(ventilador, LOW);
}
void loop() {
  delay(100);
}
