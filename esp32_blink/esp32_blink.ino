
#define LED_PIN 23

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
   while (!Serial) {
    delay(20); // wait for serial port to connect. Needed for native USB port only
  }
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("ON");
  delay(500);
  digitalWrite(LED_PIN, LOW);
  Serial.println("OFF");
  delay(500);
}
