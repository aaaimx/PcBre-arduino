
#include <Wire.h>
const int casa1 = 9;
const int casa2 =10;
const int poste1 = 11;
const int poste2 =12;
void setup() {
 Wire.begin(0x09);
  Serial.begin(9600);
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  pinMode(casa1,OUTPUT);
  pinMode(casa2,OUTPUT);
  pinMode(poste1,OUTPUT);
  pinMode(poste2,OUTPUT);

  digitalWrite(casa1,LOW);
  digitalWrite(casa2,LOW);
  digitalWrite(poste1,LOW);
  digitalWrite(poste2,LOW);

}
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c =Wire.read(); // receive byte as a character
    digitalWrite(casa1,c);
  digitalWrite(casa2,c);
  digitalWrite(poste1,c);
  digitalWrite(poste2,c);
  }


}
void inicio(){
  digitalWrite(casa1,HIGH);
  digitalWrite(casa2,HIGH);
  digitalWrite(poste1,HIGH);
  digitalWrite(poste2,HIGH);
}
void parar(){
  digitalWrite(casa1,LOW);
  digitalWrite(casa2,LOW);
  digitalWrite(poste1,LOW);
  digitalWrite(poste2,LOW);
}

void loop() {
 

}
