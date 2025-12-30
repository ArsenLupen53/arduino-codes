#define ANALOG_X_PIN A4
#define ANALOG_Y_PIN A3
#define ANALOG_BUTTON_PIN A2
#define RED_LED 2
#define YELLOW_LED 3
#define GREEN_LED 4

#define ANALOG_X_CORRECTION 128
#define ANALOG_Y_CORRECTION 128

struct button {
  byte pressed = 0;
};

struct analog_data {
  short x, y;
  button btn;
};

void setup() {
  pinMode(ANALOG_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  analog_data joy;

  joy.x = readAnalogAxisLevel(ANALOG_X_PIN) - ANALOG_X_CORRECTION;
  joy.y = readAnalogAxisLevel(ANALOG_Y_PIN) - ANALOG_Y_CORRECTION;
  joy.btn.pressed = isAnalogButtonPressed(ANALOG_BUTTON_PIN);

  Serial.print("X:"); Serial.print(joy.x);
  Serial.print(" Y:"); Serial.println(joy.y);

  if (joy.btn.pressed) {
    Serial.println("Buton Basildi");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    delay(300);
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(300);
  } else {
    // Mantıksal karşılaştırmalar (&& kullanılarak) düzeltildi
    if (joy.x > 110) {
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
    else if (joy.x < -110) {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
    else if (joy.y < -110) {
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
    else if (joy.y > 110) {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(YELLOW_LED, HIGH);
      digitalWrite(GREEN_LED, HIGH);
    }
    else {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
    }
  }

  delay(100); 
} // loop fonksiyonunun gerçek bitişi burası

// Yardımcı fonksiyonlar loop dışında olmalı
byte readAnalogAxisLevel(int pin) {
  return map(analogRead(pin), 0, 1023, 0, 255);
}

bool isAnalogButtonPressed(int pin) {
  return digitalRead(pin) == LOW;
}