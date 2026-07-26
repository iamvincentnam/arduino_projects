/*
  ==================================================================
  PROJECT: Variable Strobe Light & Synchronized Audio Alarm
  ==================================================================
  
  WHAT THIS CODE DOES:
  This sketch creates a dual-LED strobe flashing sequence (Pin 12 
  and Pin 11) accompanied by an active buzzer beep. An analog 
  potentiometer is used to dynamically adjust the flashing speed 
  and audio tempo in real time.
  
  HOW IT WORKS:
  1. The Arduino reads the position of the potentiometer (0 to 1023) 
     on Analog Pin A1.
  2. The map() function translates that raw value into a timing delay 
     ranging from 10 ms (rapid strobe) to 500 ms (slow pulse).
  3. The code alternates triggering Pin 12 and Pin 11 while toggling 
     Pin 10 HIGH and LOW so the buzzer clicks/beeps in exact sync 
     with the visual flash.
     
  PIN CONFIGURATION:
  - Potentiometer Signal -> Analog Pin A1
  - Strobe LED 1         -> Digital Pin 12
  - Strobe LED 2         -> Digital Pin 11
  - Active Buzzer (+)    -> Digital Pin 8
  ==================================================================
*/


const int analogInPin = A1; // Analog input pin connected to the 
const int BUZZER_PIN = 8;
//set up the variable for your LEDs
int led1=12;
int led2=11;
// potentiometer
int sensorValue = 0;        
// Value read from the potentiometer
int timer = 0;              
// Delay value
// Set digital pins 12 and 11 as outputs
void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(BUZZER_PIN, OUTPUT);
}
// --- HERE IS MY CUSTOM SIREN FUNCTION ---
void playSiren(){
  //quickly raise frequency (pitch) of the buzzer from 400Hz to 1000Hz 
      for(int hz =400; hz <= 2000; hz+=400){
        tone(BUZZER_PIN, hz );
        delay(2);
      }


}
// Start a loop to turn LEDs on and off with a delay in between
void loop() {
  sensorValue = analogRead(analogInPin); // Read value from the 
                                         // potentiometer
  timer = map(sensorValue, 0, 1023, 10, 500); // Delay 10 to 500 ms
digitalWrite(led1, HIGH); 
playSiren(); // Buzzer ON with LED 12
  delay(timer);           
  
  digitalWrite(led1, LOW);  
 noTone(BUZZER_PIN);  // Buzzer OFF
  delay(timer);

  digitalWrite(led1, HIGH);
playSiren();  // Buzzer ON with LED 12
  delay(timer);

  digitalWrite(led1, LOW);
noTone(BUZZER_PIN);   // Buzzer OFF

// --- LED 11 ON + SIREN ---
  digitalWrite(led2, HIGH);
  playSiren();  // Buzzer ON with LED 11
  delay(timer);

  digitalWrite(led2, LOW);
   noTone(BUZZER_PIN); // Buzzer OFF
  delay(timer);

  digitalWrite(led2, HIGH);
  playSiren();  // Buzzer ON with LED 11
  delay(timer);

  digitalWrite(led2, LOW);
noTone(BUZZER_PIN);
}