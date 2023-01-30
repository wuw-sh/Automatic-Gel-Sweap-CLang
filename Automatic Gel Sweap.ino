#include <Servo.h>
Servo myservo;
int pos = 45;
const int TrigPin = 18;
int EchoPin = 19;
int detected = 0;
float duration, cm;

void setup() {
  Serial.begin(9600);
  myservo.attach(11);
  myservo.write(pos);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop()
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(EchoPin, HIGH);
  cm = round(duration * 0.0171);
  if (cm > 8 && cm < 18 && detected == 0) {
    detected = 1;
    for (pos = 45; pos <= 155; pos++) {
      myservo.write(pos);
      delay(2);
    }
    myservo.write(45);
  } else if (cm > 20) {
    detected = 0;
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(150);
}
