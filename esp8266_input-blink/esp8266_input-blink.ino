/*
  This example demonstrates the use of pinMode(INPUT_PULLUP). 
  It reads a digital input on pin 14 and blinks the inbuilt LED

  The circuit:
  - momentary switch attached from pin 14 to ground
  - built-in LED on pin 2

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 3V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

*/

#define INPUNT_PIN 14
#define LED_BUILTIN 2



void setup() {
  //configure pin 14 as an input and enable the internal pull-up resistor
  pinMode(INPUNT_PIN, INPUT_PULLUP);

  pinMode(LED_BUILTIN, OUTPUT);

  // initially turn off the LED
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(INPUNT_PIN);
  
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. 
  // Blink LED if pin is LOW, that means connected 
  if (sensorVal == LOW) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
  }
}

// Next exercise: create a coin flip game.
