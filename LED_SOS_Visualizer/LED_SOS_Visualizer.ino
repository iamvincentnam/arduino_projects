/*
 ===============================================================================
  Project Name: Multi-LED Morse Code SOS Visualizer
  Description:  This program blinks three LEDs (Red, Yellow, and Green) 
  together at the same time to flash the international 
  distress signal: S.O.S.
	
  Morse Code Timing Standards Used:
    - Dot (.)    = 200ms
    - Dash (-)   = 600ms (Exactly 3x the duration of a dot)
    - Part Gap   = 200ms (Silence between blinks within the same letter)
    - Letter Gap = 400ms (Silence between S, O, and S)
 ===============================================================================
*/


// ... here  is thr rest of my code  below ...

int red = 12;
int yellow = 4;
int green = 7;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // S (. . .)
  dot(); dot(); dot();
  delay(400); // Standard gap between letters
  
  // O (- - -)
  dash(); dash(); dash();
  delay(400); // Standard gap between letters
  
  // S (. . .)
  dot(); dot(); dot();
  
  delay(2000); // 3-second pause before the whole SOS repeats
}

// --- Morse Code Helper Functions ---

void dot() {
  digitalWrite(red, HIGH);    digitalWrite(yellow, HIGH);    digitalWrite(green, HIGH);
  delay(200); // Short flash
  digitalWrite(red, LOW);     digitalWrite(yellow, LOW);     digitalWrite(green, LOW);
  delay(200); // Gap between flashes
}

void dash() {
  digitalWrite(red, HIGH);    digitalWrite(yellow, HIGH);    digitalWrite(green, HIGH);
  delay(600); // Long flash (3x longer than a dot)
  digitalWrite(red, LOW);     digitalWrite(yellow, LOW);     digitalWrite(green, LOW);
  delay(200); // Gap between flashes
}




