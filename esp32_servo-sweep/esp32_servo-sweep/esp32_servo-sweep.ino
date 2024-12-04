// Library: ESP32Servo by Kevin Harrington, John K. Bennett
// https://randomnerdtutorials.com/esp32-servo-motor-web-server-arduino-ide/
// https://docs.arduino.cc/libraries/esp32servo/


#include <ESP32Servo.h>


static const int servoPin = 23;

Servo servo1;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("\n\nInitializing...");
  servo1.attach(servoPin);
}

void loop() {
  for (int posDegrees = 0; posDegrees <= 180; posDegrees++) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }

  for (int posDegrees = 180; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
}
