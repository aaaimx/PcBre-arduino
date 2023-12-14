#include <Servo.h>
#include <Wire.h>

char c;

const int ledPin = 13;

Servo myservo;  // crea el objeto servo

int vel = 0;  // velocidad del servo

void setup() {
  myservo.attach(4);  // vincula el servo al pin digital 9

  Wire.begin(0x08);
  Serial.begin(9600);
 Wire.onReceive(receiveEvent);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    c = Wire.read();
    myservo.write(c);
  }
}

void run(){
    digitalWrite(ledPin, HIGH);
    vel = 135;
    myservo.write(vel);
    delay(1500);
  

}
void stop(){
    digitalWrite(ledPin, LOW);
    vel = 90;
    myservo.write(vel);
    delay(1500);
}
void loop() {

  delay(2000);
}