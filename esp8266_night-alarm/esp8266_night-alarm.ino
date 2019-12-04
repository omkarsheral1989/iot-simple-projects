// Sounds alarm at night using LDR.

#define PWM_PIN 14
#define ANALOG_INPUT_PIN 0

// max val: 1024 - 10 bits

const int freq = 800;   // in Hz
const int nightThreshold = 500;

void setup() {
  pinMode(ANALOG_INPUT_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  int inputVal = analogRead(ANALOG_INPUT_PIN);
  Serial.println(inputVal);
  if(inputVal > nightThreshold){
   tone(PWM_PIN, freq); 
  }else{
    noTone(PWM_PIN);
  }
  delay(50);
}
