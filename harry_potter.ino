int buzzerPin = 12;

// Eksik olanlar dahil tüm nota tanımları
int nB3=247; 
int nC4=262; int nCS4=277; int nD4=294; int nDS4=311; int nE4=330; int nF4=349; int nFS4=370; int nG4=392; int nGS4=415; int nA4=440; int nAS4=466; int nB4=494;
int nC5=523; int nCS5=554; int nD5=587; int nDS5=622; int nE5=659; int nF5=698; int nFS5=740; int nG5=784;

// Harry Potter - Hedwig's Theme (Tam Liste)
int melody[] = {
  nB3, nE4, nG4, nF4, nE4, nB4, nA4, nF4, 
  nE4, nG4, nF4, nD4, nF4, nB3,          
  nB3, nE4, nG4, nF4, nE4, nB4, nD5, nCS5, nC5,
  nA4, nC5, nB4, nAS4, nB3, nG4, nE4      
};

// Nota süreleri
int durations[] = {
  300, 450, 150, 300, 600, 300, 900, 900,
  450, 150, 300, 600, 300, 900,
  300, 450, 150, 300, 600, 300, 600, 300, 600,
  300, 450, 150, 300, 600, 300, 900
};

void setup() {
  // İlk çalıştırmada bir kere çalar
  for (int i = 0; i < 30; i++) {
    tone(buzzerPin, melody[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(durations[i] * 0.1); 
  }
}

void loop() {
  // Şarkı bittikten sonra 3 saniye bekler ve sonsuz döngüde baştan çalar
  delay(3000);
  for (int i = 0; i < 30; i++) {
    tone(buzzerPin, melody[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(durations[i] * 0.1); 
  }
}