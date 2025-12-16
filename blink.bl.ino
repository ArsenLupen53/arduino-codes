#define BLUELED 3
#define YELLOWLED 5
void setup() {
  // put your setup code here, to run once:
  pinMode(BLUELED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++){
    analogWrite(BLUELED,i);
    analogWrite(YELLOWLED,255-i);
    delay(10);
  }
  for(int j=255;j>=0;j--){
    analogWrite(BLUELED,j);
    analogWrite(YELLOWLED,255-j);
    delay(10);
  }
  
}