#include <Servo.h>
#include <NewPing.h>


#define TRIGGER_PIN 13
#define ECHO_PIN 12

#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

Servo servo;
int angle = 10;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);
  servo.write(angle);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iterations = 5;
  distance = sonar.convert_cm(sonar.ping_median(iterations));
  Serial.println(distance);
  if (distance > 0 && distance < 5.00) {
    servo.write(90);
  } else if(distance > 5.00) {
    servo.write(0);
  }
  delay(50);
}
