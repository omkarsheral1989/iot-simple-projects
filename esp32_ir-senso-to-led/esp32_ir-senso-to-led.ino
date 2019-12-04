// IR sensor to LED

#define ANALOG_INPUT_PIN 13
#define LED_PIN 21

// max value: 4095 - 12 bits

void setup() {
  pinMode(ANALOG_INPUT_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int inputVal = analogRead(ANALOG_INPUT_PIN);
  Serial.println(inputVal);
  
  if(inputVal < 1000){
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
}
