void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);

}


void ledFadingFunc(int analogPin){
      for(int fadeValue =0; fadeValue <=255; fadeValue +=15){
        analogWrite(analogPin,fadeValue);
        delay(30);
      }

      for(int fadeValue =255; fadeValue >=0; fadeValue -=15){
        analogWrite(analogPin,fadeValue);
        delay(30);
      }
}
void loop() {

 //THE above code is commented out when the one bellow is needed to be used.
ledFadingFunc(9);
}
