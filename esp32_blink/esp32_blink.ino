
#define LED_PIN 23

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(500);
  digitalWrite(LED_PIN, HIGH);    // turn the LED off by making the voltage LOW
  delay(500);
}
