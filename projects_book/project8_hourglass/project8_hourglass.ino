const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2; // tracks next led to be turned on
unsigned long interval = 500; // 10 seconds x 6 leds => total time of 1 minute

void setup() {
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    // turn on next led
    digitalWrite(led, HIGH);
    if (led > 7) {
      
    } else {
      if (led == 7) {
        delay(1000);
      }
      led++;
    }
    
    previousTime = currentTime;
  }

  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;

  if (led > 7) {
    int curState = digitalRead(2);
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, 1-curState);
    }
    delay(200);
  }

}
