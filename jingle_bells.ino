int buzzerPin = 12;

// Notalar
int nC4=262; int nD4=294; int nE4=330; int nF4=349; int nG4=392; int nA4=440; int nB4=494;
int nC5=523; int nD5=587; int nE5=659; int nF5=698; int nG5=784;

// Jingle Bells Melodisi
int melody[] = {
  nE4, nE4, nE4,       // Jin-gle bells
  nE4, nE4, nE4,       // jin-gle bells
  nE4, nG4, nC4, nD4,  // jin-gle all the
  nE4,                 // way
  nF4, nF4, nF4, nF4,  // Oh what fun it
  nF4, nE4, nE4, nE4,  // is to ride in a
  nE4, nD4, nD4, nE4,  // one horse o-pen
  nD4, nG4             // sleigh
};

// Nota süreleri (4: çeyrek nota, 2: yarım nota)
int durations[] = {
  4, 4, 2, 
  4, 4, 2, 
  4, 4, 4, 4, 
  1, 
  4, 4, 4, 4, 
  4, 4, 4, 8, 8, 
  4, 4, 4, 4, 
  2, 2
};

void setup() {
  for (int i = 0; i < 26; i++) {
    // Nota süresini hesapla (1000ms / süre tipi)
    int noteDuration = 1000 / durations[i];
    tone(buzzerPin, melody[i], noteDuration);

    // Notalar arası temiz geçiş
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(buzzerPin);
  }
}

void loop() {
  // Şarkı bittikten sonra 3 saniye bekle ve baştan çal
  delay(3000);
  setup();
}