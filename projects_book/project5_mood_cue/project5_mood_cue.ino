/*
 * Consider replacing potentiometer with temperature sensor.
 * Need to account for large range of temp sensor and small range of likely temperatures to encounter.
 * Scale accordingly (and set bounds?) so the servo actually moves a bit.
 */

#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);

}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);

}
