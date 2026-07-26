// Pin Definitions
const int redLed = 13;
const int blueLed = 8;
const int buzzer = 2;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // --- STATE 1: Red LED ON, Blue LED OFF ---
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, LOW);
  
  tone(buzzer, 1000);  // Play high tone
  delay(150);          // Beep for 150 milliseconds
  noTone(buzzer);      // Stop sound
  
  delay(1850);         // Wait out the rest of the 2-second total cycle time

  // --- STATE 2: Red LED OFF, Blue LED ON ---
  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, HIGH);
  
  tone(buzzer, 400);   // Play low tone
  delay(150);          // Beep for 150 milliseconds
  noTone(buzzer);      // Stop sound
  
  delay(1850);         // Wait out the rest of the 2-second total cycle time
}