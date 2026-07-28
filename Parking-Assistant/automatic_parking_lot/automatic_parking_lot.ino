/*
  Smart Parking Assistant / Proximity Alarm
  Uses HC-SR04, 4 LEDs (Bar Graph), and a Passive Piezo Buzzer
*/

const int TRIG_PIN = 7;
const int ECHO_PIN = 9;

// 4-LED Bar Graph Pins (Green, Yellow, Orange, Red)
const int ledPins[] = {2, 3, 4, 5}; 
const int BUZZER_PIN = 8;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  // 1. Trigger the Ultrasonic Pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 2. Measure Echo Pulse duration
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); 
  float distanceCm = (duration * 0.0343) / 2.0;

  // 3. Proximity Logic & Feedback
  if (duration == 0 || distanceCm > 40.0) {
    // --- Safe / Out of Range (> 40 cm) ---
    clearLEDs();
    noTone(BUZZER_PIN);
  } 
  else if (distanceCm > 30.0) {
    // --- Level 1: Far (30-40 cm) ---
    setLEDs(1);             // 1 LED ON
    tone(BUZZER_PIN, 500);  // Low beep
    delay(100);
    noTone(BUZZER_PIN);
    delay(400);             // Slow beep rate
  } 
  else if (distanceCm > 20.0) {
    // --- Level 2: Medium (20-30 cm) ---
    setLEDs(2);             // 2 LEDs ON
    tone(BUZZER_PIN, 800);  
    delay(100);
    noTone(BUZZER_PIN);
    delay(200);             // Medium beep rate
  } 
  else if (distanceCm > 10.0) {
    // --- Level 3: Close (10-20 cm) ---
    setLEDs(3);             // 3 LEDs ON
    tone(BUZZER_PIN, 1200); 
    delay(100);
    noTone(BUZZER_PIN);
    delay(80);              // Fast beep rate
  } 
  else {
    // --- Level 4: DANGER (< 10 cm) ---
    setLEDs(4);             // All 4 LEDs ON
    tone(BUZZER_PIN, 1800); // High pitch continuous tone
    delay(100);
  }

  // Serial Monitor Output
  Serial.print("Distance: ");
  Serial.print(distanceCm, 1);
  Serial.println(" cm");
}

// Helper function to light up LEDs up to a given count
void setLEDs(int count) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], i < count ? HIGH : LOW);
  }
}

// Helper function to turn off all LEDs
void clearLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}