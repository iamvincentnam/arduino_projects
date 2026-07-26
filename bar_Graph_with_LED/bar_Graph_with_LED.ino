/*
  ==================================================================
  HOW IT WORKS: LED Bar Graph Display
  ==================================================================
  A bar graph is a row of LEDs arranged in a straight line, similar 
  to the volume audio meters you see on sound equipment. 
  
  In this project, we read an analog signal from a potentiometer to 
  control how many LEDs light up. 
  
  IMPORTANT LOGIC NOTE: 
  We are NOT fading the brightness of individual LEDs here. Instead, 
  we are sequencing them (turning them on or off one by one) based on 
  the physical position of the knob.
  
  - Turning the knob one way lights up the LEDs one at a time in sequence 
    until the whole bar is glowing.
  - Turning the knob back the other way turns them off in the reverse 
    sequence.
  ==================================================================
*/

const int analogPin =A0;
const int ledCount =5;  // Number of LEDs
int ledPins[]={2,3,5,6,8} ; // Pins connected to the LEDs
void setup() {
  // put your setup code here, to run once:
for(int thisLed =0; thisLed < ledCount; thisLed++){
  pinMode(ledPins[thisLed], OUTPUT);  // Set the LED pins as output
}
}

void loop() {
  // put your main code here, to run repeatedly:
int SensorValue = analogRead(A0);
int brightnessControl =map(SensorValue,0,1023,0,ledCount);
for(int thisLed =0; thisLed < ledCount; thisLed++){
    if(thisLed < brightnessControl)
    {
    digitalWrite(ledPins[thisLed],HIGH);
    }
 
    else{
      digitalWrite(ledPins[thisLed], LOW); 
    }
}
}