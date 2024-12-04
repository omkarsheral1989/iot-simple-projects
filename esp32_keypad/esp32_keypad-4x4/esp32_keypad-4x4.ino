#include <Keypad.h>

// install library: Keypad by Mark Stanley, Alexander Brevig.
// 
//   1       2       3       A
// 
//   4       5       6       B
// 
//   7       8       9       C
// 
//   *       0       #       D
// 
// ☉   ☉   ☉   ☉   ☉   ☉   ☉   ☉
// 13  12  14  27  26  25  33  32

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};
byte rowPins[4] = {13, 12, 14, 27};
byte colPins[4] = {26, 25, 33, 32};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  while (!Serial) {
    delay(20); // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("\n\nInitializing...");
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}