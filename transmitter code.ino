#include <SoftwareSerial.h>

// Define the pins for the ultrasonic sensor
const int trigPin = 7 ;
const int echoPin = 8;

// Define the pins for the HC-12 transmitter
const int HC12_TXD = 2;
const int HC12_RXD = 3;
SoftwareSerial HC12Serial(HC12_TXD, HC12_RXD);
long distance;

void setup() {
  Serial.begin(9600);
  HC12Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long pulseDuration = pulseIn(echoPin, HIGH);
  distance = pulseDuration / 58.2;
  HC12Serial.print(distance);
  HC12Serial.println();
  delay(2000);
}