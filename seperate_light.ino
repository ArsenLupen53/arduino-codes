#define RED_LED 2
#define BLUE_LED 3
#define GREEN_LED 4
#define YELLOW_LED 5

#define BUTTON1 8
#define BUTTON2 9

void setup() {
  // LED pinlerini çıkış olarak ayarla
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);

  // Butonları dahili pull-up direnci ile giriş olarak ayarla
  // Bu modda butona basınca 0 (LOW), basmayınca 1 (HIGH) okunur.
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Buton durumlarını oku
  int b1Durum = digitalRead(BUTTON1);
  int b2Durum = digitalRead(BUTTON2);

  // Seri ekranda kontrol etmek istersen:
  // Serial.print("B1: "); Serial.print(b1Durum);
  // Serial.print(" - B2: "); Serial.println(b2Durum);

  if (b1Durum == LOW) { // Button 1'e basıldıysa
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
  else if (b2Durum == LOW) { // Button 2'ye basıldıysa
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
  }
  else { // Hiçbir butona basılmıyorsa her şeyi söndür
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
  
  delay(10); // İşlemciyi yormamak ve kararlı okuma için küçük bir gecikme
}