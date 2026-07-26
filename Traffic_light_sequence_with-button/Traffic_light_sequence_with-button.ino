/* traffic light sequence is controlled by button  */

// C++ code
int red =2;
int yellow =4;
int green =6;
int inputPin= 8;
  void traffictLightSequenceOff(){
  		digitalWrite(red, LOW);
      	digitalWrite(yellow, LOW);
        digitalWrite(green,LOW);
}
void traffictLightSequence(){
		digitalWrite(red,HIGH);
  		digitalWrite(yellow, LOW);
      	digitalWrite(green, LOW);
     delay(600);
  		digitalWrite(yellow, HIGH);
 	 	digitalWrite(green, LOW);
      	digitalWrite(red,LOW);
      delay(600);
  		digitalWrite(green, HIGH);
       	digitalWrite(yellow, LOW);
      	digitalWrite(red,LOW);
       
      delay(600);
}
    
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(inputPin,INPUT);
}


void loop()
{
    if(digitalRead(inputPin)== HIGH){
      traffictLightSequence();              
    }
  else{ traffictLightSequenceOff(); 
      }
}
       