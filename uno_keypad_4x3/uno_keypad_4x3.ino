#include <Keypad.h>


//     1       2       3
//
//     4       5       6
//
//     7       8       9
//
//     *       0       #
//
// 1   2   3   4   5   6   7
// ☉   ☉   ☉   ☉   ☉   ☉   ☉
// C2, R1, C1, R4, C3, R3, R2
// 2   3   4   5   6   7   8    - uC pin no



const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' },
};
byte rowPins[4] = { 3, 8, 7, 5 };  // R1, R2, R3, R4
byte colPins[3] = { 4, 2, 6 };     // C1, C2, C3
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(20);  // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("\n\nInitializing...");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
  }
}