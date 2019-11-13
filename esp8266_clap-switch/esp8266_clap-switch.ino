/**
 * Clap switch
 */

#define LED_PIN 2
#define MIC_INPUT_PIN D5


void setup() {
  // put your setup code here, to run once:
  pinMode(MIC_INPUT_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

int inputVal;
void loop() {
  inputVal = digitalRead(MIC_INPUT_PIN);
  if(inputVal==LOW){
    toggleLed();
    delay(500);
  }
}


int ledValue=HIGH;
void toggleLed(){
  if(ledValue==HIGH){
    ledValue = LOW;
  }else{
    ledValue = HIGH;
  }
  digitalWrite(LED_PIN, ledValue);
}
