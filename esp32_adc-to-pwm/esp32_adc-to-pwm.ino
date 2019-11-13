#define ANALOG_INPUT_PIN 13
#define PWM_LED_PIN 19

const int analogChannel0=0;
void setup() {
  pinMode(ANALOG_INPUT_PIN, INPUT);

  //setup channel 0 with frequency 312500 Hz
  sigmaDeltaSetup(analogChannel0, 312500);
  //attach pin 18 to channel 0
  sigmaDeltaAttachPin(PWM_LED_PIN, analogChannel0);
  //initialize channel 0 to off
  sigmaDeltaWrite(analogChannel0, 0);

  Serial.begin(9600);
}

void loop() {
  int inputVal = analogRead(ANALOG_INPUT_PIN);
  Serial.println(inputVal);

  
  int outputValue = map(inputVal, 0, 4095, 0, 255);
  sigmaDeltaWrite(analogChannel0, outputValue);
  
  delay(100);
}
