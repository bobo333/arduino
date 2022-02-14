/*  Pushing the button toggles between blinking red lights and solid green.
 *  There's an issue though where pushing the button doesn't always turn the blinking lights back to green.
 *  I think because it may be during the delay call.
 */

int prevState = 0;
int blinkState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  prevState = digitalRead(2);
}

int switchState = 0;


void loop() {
  switchState = digitalRead(2);

  if (switchState == HIGH) {
    if (prevState == LOW) {
      // switch blink state
      blinkState = 1 - blinkState;
    }
    prevState = HIGH;
  } else {
    prevState = LOW;
  }

  if (blinkState == 1) {
    // green off
    digitalWrite(3, LOW);
    
    // blink red lights
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);

    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    // green on
    digitalWrite(3, HIGH);
  }
}
