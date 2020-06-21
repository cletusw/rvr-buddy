uint32_t currentBaud = 9600;

void setup() {
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  currentBaud = Serial.baud();
  Serial1.begin(currentBaud);    // Set hardware serial baud rate to USB's desired baud rate
}

void loop() {
  // Poll for baud changes on the USB CDC side
  if (currentBaud != Serial.baud()) {
    currentBaud = Serial.baud();
    Serial1.flush();             // Finish sending any pending messages
    Serial1.begin(currentBaud);  // Set hardware serial baud rate to USB's desired baud rate
  }

  if (Serial.available()) {
    Serial1.write(Serial.read()); // USB -> D1/pin21/TX
  }

  if (Serial1.available()) {
    Serial.write(Serial1.read()); // D0/pin20/RX -> USB
  }
}
