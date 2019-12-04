#define ANALOG_INPUT_PIN 13

// max value: 4095 - 12 bits

void setup() {
  pinMode(ANALOG_INPUT_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  int inputVal = analogRead(ANALOG_INPUT_PIN);
  Serial.println(inputVal);
  delay(100);
}
