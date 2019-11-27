/*
  String to Integer conversion

  Reads a serial input string until it sees a newline, then converts the string
  to a number if the characters are digits.
  And writes to PWM
*/


#define PWM_LED_PIN 14

String inString = "";    // string to hold input

void setup() {
  pinMode(PWM_LED_PIN, OUTPUT);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.print("\n\nWrite a number between 0 - ");
  Serial.print(PWMRANGE);
  Serial.println();
  Serial.println();
}

void loop() {
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    };pp
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      Serial.print("String: ");
      Serial.println(inString);
      
      Serial.print("Value:");
//      uint8_t pwmOutput=(uint8_t)inString.toInt();
      int pwmOutput = inString.toInt();
      Serial.println(pwmOutput);
      Serial.println();

      analogWrite(PWM_LED_PIN, pwmOutput);
      
      // clear the string for new input:
      inString = "";
    }
  }
}
