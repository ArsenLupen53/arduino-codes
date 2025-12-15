int ledRed=2;
int ledBlue=3;
int ledGreen=4;
int ledYellow=5;
void setup() {

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH); 
  delay(200);
  digitalWrite(3,HIGH);
  delay(200);
  digitalWrite(4,HIGH);
  delay(200);
  digitalWrite(5,HIGH);


  delay(1000);


  digitalWrite(2,LOW); 
  delay(200);
  digitalWrite(3,LOW);
  delay(200);
  digitalWrite(4,LOW);
  delay(200);
  digitalWrite(5,LOW);
}
