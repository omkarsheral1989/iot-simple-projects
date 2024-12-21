#include <Keypad.h>

// install library: Keypad by Mark Stanley, Alexander Brevig.
// 
//   1       2       3 
// 
//   4       5       6 
// 
//   7       8       9
// 
//   *       0       #
// 
// 1   2   3   4   5   6   7
// ☉   ☉   ☉   ☉   ☉   ☉   ☉ 
// C2, R1, C1, R4, C3, R3, R2
//black ------------------blue
// 25  13  26  27  33  14  12   - uC pin no


const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};
byte rowPins[4] = {13, 12, 14, 27};   // R1, R2, R3, R4
byte colPins[3] = {26, 25, 33};       // C1, C2, C3, C4
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