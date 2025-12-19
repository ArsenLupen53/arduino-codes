
#define BUTTON 3
#define LED 4


bool state;
bool ledDurum = LOW;
unsigned long simdikiZaman = 0;
unsigned long eskiZaman = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(BUTTON);
  if (state == 0){
    Serial.println("butona basıldı");
    while (digitalRead(BUTTON) == 0);
  }

  simdikiZaman = millis();
  if (simdikiZaman - eskiZaman > 1000){
    eskiZaman = simdikiZaman;
    if (ledDurum ==LOW){
      ledDurum=HIGH;
    }
    else{
      ledDurum=LOW;
    }
    digitalWrite(LED,ledDurum);
  }
}
