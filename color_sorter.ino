#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

Servo topServo;
Servo bottomServo;

int frequency = 0;
int color = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  topServo.attach(7);
  bottomServo.attach(8);

  Serial.begin(9600);
}

void loop() {
  topServo.write(115);
  delay(500);

  for (int i = 115; i > 28; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(500);

  color = readColor();
  delay(10);

  switch (color) {
    case 1:
      bottomServo.write(50);
      break;

    case 2:
      bottomServo.write(75);
      break;

    case 3:
      bottomServo.write(100);
      break;

    case 4:
      bottomServo.write(125);
      break;

    case 5:
      bottomServo.write(25);
      break;

    case 0:
      break;
  }
  delay(300);

  for (int i = 28; i > 10; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(200);

  for (int i = 10; i < 115; i++) {
    topServo.write(i);
    delay(2);
  }
  color = 0;
}

int readColor() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("R= ");      
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("G= ");      
  Serial.print(frequency);
  Serial.print("  ");
  delay(50);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("B= ");    
  Serial.print(frequency); 
  Serial.println("  ");
  delay(50);
 
    if (G/R <= 1.03 & G/R >= 1) {
    color = 5;  // Purple
  }
  if (G/R <= 1.08 & G/R >= 1.04) {
    color = 4;  // yellow
  }
  if (G/R <= 0.96 & G/R > 0.9) {
    color = 3;  //Green
  }
  if (G/R <= 1.35 & G/R > 1.16 & B/R >= 1.04) {
    color = 2;  // Orange
  }
  if (G/R <= 1.35 & G/R > 1.16 & B/R > 0.7 & B/R <= 1.03) {
    color = 1;  // Red
  }

  return color;
}