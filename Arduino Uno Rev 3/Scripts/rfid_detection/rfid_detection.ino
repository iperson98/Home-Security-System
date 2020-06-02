#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9
#define SS_PIN    10

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 object

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  while (!Serial);     // Wait for serial port to open
  SPI.begin();         // Initialize SPI
  mfrc522.PCD_Init();  // Initialize MFRC522 card
  pinMode(7, OUTPUT);  // Initialize digital pin LED_BUILTIN as an output.
}

// UID Check
void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);
  }
  else {
    digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
    delay(500);
  }
}
