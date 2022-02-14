void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

const int SHORT_TIME = 200;
const int LONG_TIME = 500;
const int DELAY_TIME = 100;

void short_blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_TIME);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY_TIME);
}

void long_blink() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_TIME);
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY_TIME);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  
  long_blink();
  short_blink();
  long_blink();
  long_blink();
  long_blink();
  short_blink();
  long_blink();
  long_blink();
  long_blink();
  long_blink();
  short_blink();
  short_blink();
}
