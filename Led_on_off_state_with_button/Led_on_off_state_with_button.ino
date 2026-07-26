int red = 12;
int yellow = 8;
int green = 2;
int buttonPin=4;
int ledState = LOW;
int lastButtonState =LOW;
void setup() {

pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(buttonPin,INPUT);
  // put your setup code here, to run once:

}

int blink_3_Leds(){
int currentButtonState = digitalRead(buttonPin);
  if( currentButtonState == HIGH && lastButtonState == LOW){
  ledState =!ledState;

    digitalWrite(red,ledState);
    digitalWrite(yellow,ledState);
    digitalWrite(green,ledState);

    delay(60);
  }
  lastButtonState = currentButtonState;
   
}
void loop() {
  // put your main code here, to run repeatedly:
blink_3_Leds();
}
