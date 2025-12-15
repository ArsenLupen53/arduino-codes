int button = 8;
const int ledRed = 2;  //sadece okunabilir bir değişken olur daha sonra değiştirilemez.
int ledBlue = 3;
int ledGreen = 4;
int ledYellow = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);



  //Serial.begin(9600);
}

void loop() {
  int state = digitalRead(button);
  if (state == 1) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, HIGH);
  }

  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
  }
  // put your main code here, to run repeatedly:
}
