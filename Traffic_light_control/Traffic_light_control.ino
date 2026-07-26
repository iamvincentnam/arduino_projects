void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(4,OUTPUT);
pinMode(2,OUTPUT);
}

void loop() {
  digitalWrite(8,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(2,LOW);

  delay(2000);

  digitalWrite(8,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
  
  delay(2000);

  digitalWrite(8,LOW);
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH);
  
  delay(2000);
  // put your main code here, to run repeatedly:

}
