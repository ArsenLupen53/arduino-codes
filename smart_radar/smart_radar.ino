#include <NewPing.h>
#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 400
#define BUZZER_PIN 2

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float distance;

// Kendi ses fonksiyonumuz (tone yerine bunu kullanacağız)
void bip(int pin, int frekans, int sure) {
  long bekleme = 1000000 / frekans / 2; // Mikrosaniye cinsinden hesaplama
  long dongu = (long)sure * 1000 / (bekleme * 2);
  for (long i = 0; i < dongu; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(bekleme);
    digitalWrite(pin, LOW);
    delayMicroseconds(bekleme);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  delay(50); // Sensörün kararlı çalışması için kısa bir bekleme
  distance = sonar.ping_cm();
  Serial.println(distance);

  if (distance > 20) {
    bip(BUZZER_PIN, 250, 200); // Pin, Frekans, Süre(ms)
    delay(500);
  } 
  else if (distance <= 20 && distance >= 10) {
    bip(BUZZER_PIN, 250, 100);
    delay(200);
  }
  else if (distance > 0 && distance < 10) {
    bip(BUZZER_PIN, 250, 50);
    delay(50);
  }
}
