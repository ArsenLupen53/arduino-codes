const int sesPin = A1;   
const int kirmiziLed = 2; 
const int sariLed = 3;    



int esikDegeri = 47; 

void setup() {
  pinMode(kirmiziLed, OUTPUT);
  pinMode(sariLed, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int sesSeviyesi = analogRead(sesPin);
  
  
  Serial.print("Ses Seviyesi: ");
  Serial.println(sesSeviyesi);

  if (sesSeviyesi > esikDegeri) {
    
    digitalWrite(sariLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
  } 
  else {
    
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(sariLed, LOW);
  }

  delay(50); 
}