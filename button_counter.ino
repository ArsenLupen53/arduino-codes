#define MINUS 4
#define PLUS 8

int counter = 0;




void setup() {
  pinMode(MINUS, INPUT);
  pinMode(PLUS, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PLUS) == 1){
    counter++;
    Serial.println(counter);
    while(digitalRead(PLUS) == 1){
      delay(100);
    }
  }
  else if(digitalRead(MINUS) == 1){
    counter--;
    Serial.println(counter);
    while(digitalRead(MINUS) == 1){
      delay(100);
    }
  }

}