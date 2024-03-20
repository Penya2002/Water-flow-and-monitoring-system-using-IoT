#include <SoftwareSerial.h>

// Define the pins for the HC-12 receiver
const int HC12_TXD = 2;
const int HC12_RXD = 3;

// Create a SoftwareSerial object for the HC-12 receiver
SoftwareSerial HC12Serial(HC12_TXD, HC12_RXD);

// Define the distance variable
long distance;

void setup() {
  // Initialize the serial ports
  Serial.begin(9600);
  HC12Serial.begin(9600);
}

void loop() {
  // If there is data available from the HC-12 receiver
  if (HC12Serial.available()) {
    // Read the distance value
    distance = HC12Serial.readStringUntil('\n').toInt();

    // Print the distance value to the serial monitor
    Serial.println(distance );
    Serial.println("cm");
  }
}