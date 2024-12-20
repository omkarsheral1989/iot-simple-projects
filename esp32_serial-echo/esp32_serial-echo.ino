/*
  Whatever is sent from serial port is written back to it.
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    delay(20); // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("\n\n");
  Serial.println("Hello! this is echo mode. Whatever you write will return u back");
}

void loop() {
  if (Serial.available() > 0) {
    Serial.write(Serial.read());
  }
}
