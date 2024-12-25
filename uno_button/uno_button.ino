/*

  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital

  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:

  - momentary switch attached from pin 2 to ground

  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal

  20K-ohm resistor is pulled to 5V. This configuration causes the input to read

  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012

  by Scott Fitzgerald

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/InputPullupSerial

*/

const byte INPUT_PIN = 2;
const byte LED_PIN = 13;

void setup() {

  //start serial connection

  Serial.begin(9600);
  while (!Serial) {
    delay(20);  // wait for serial port to connect. Needed for native USB port only
  }

  //configure pin 2 as an input and enable the internal pull-up resistor

  pinMode(INPUT_PIN, INPUT_PULLUP);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  delay(100);

  //read the pushbutton value into a variable

  int sensorVal = digitalRead(INPUT_PIN);

  //print out the value of the pushbutton

  Serial.println(sensorVal);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes

  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the

  // button's pressed, and off when it's not:

  if (sensorVal == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}