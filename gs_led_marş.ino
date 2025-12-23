
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
  digitalWrite(3, LOW);
  delay(500);
  for (int i = 0; i < 3; i++) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    delay(200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    delay(200);
  }
  calGalatasarayRitim();
}
void bip(int sure, int bekleme) {
  digitalWrite(8, HIGH);
  delay(sure);
  digitalWrite(8, LOW);
  delay(bekleme);
}

void calGalatasarayRitim() {
  // --- RE RE RE ---
  bip(200, 200); 
  bip(200, 200);
  bip(200, 500);

  // --- RA RA RA ---
  bip(200, 200);
  bip(200, 200);
  bip(200, 500);

  // --- GASSA GASSA --- (Hızlı ve kesik ritim)
  bip(150, 100); // Gas-
  bip(150, 250); // -sa
  bip(150, 100); // Gas-
  bip(150, 400); // -sa

  // --- CIM BOM BOM ---
  bip(150, 200); // Cim
  bip(150, 200); // Bom
  bip(250, 1000); // BOOOM!
}
