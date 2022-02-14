/*
 * Added a button to turn the theramin on and off.
 * When opening the serial terminal sometimes this causes it to reset? Not sure why
 */

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
int soundOn = 0;
int buttonPin = 7;
int buttonVal = LOW;
int prevButtonVal = LOW;

const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);

  // calibrate high and low of sensor
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while(millis() < 5000) {
    sensorValue = analogRead(A0);

    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  Serial.print("Calibration high: ");
  Serial.print(sensorHigh);
  Serial.print(" low: ");
  Serial.println(sensorLow);

  digitalWrite(ledPin, LOW);

}

void loop() {
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == HIGH && prevButtonVal == LOW) {
    prevButtonVal = HIGH;
    soundOn = 1 - soundOn;
    delay(20);  // to "debounce" the button
  }

  if (buttonVal == LOW && prevButtonVal == HIGH) {
    prevButtonVal = LOW;
    delay(20);  // to "debounce" the button
  }
  
  if (!soundOn) {
    return;
  }
  
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 2000);
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  Serial.print(" pitch: ");
  Serial.println(pitch);
  tone(8, pitch, 20);
  delay(10);

}
