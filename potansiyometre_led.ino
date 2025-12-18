#define LED 3
#define POT A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(POT);
  int potValue2 = map(potValue,0,1023,0,255);
  analogWrite(LED, potValue2);
}
