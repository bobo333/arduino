#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  pinMode(switchPin, INPUT);
  lcd.begin(16, 2);
  
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");

}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says...");
      lcd.setCursor(0, 1);

      switch(reply) {
        case 0:
          scrollPrintBottom("Whatevs", &lcd);
          break;
        case 1:
          scrollPrintBottom("Fosho", &lcd);
          break;
        case 2:
          scrollPrintBottom("Yo mama", &lcd);
          break;
        case 3:
          scrollPrintBottom("Piss off", &lcd);
          break;
        case 4:
          scrollPrintBottom("Sup dudes", &lcd);
          break;
        case 5:
          scrollPrintBottom("Nope", &lcd);
          break;
        case 6:
          scrollPrintBottom("Oopsila", &lcd);
          break;
        case 7:
          scrollPrintBottom("Sigh", &lcd);
          break;
      }
    }
  }

  prevSwitchState = switchState;

}

const int LCD_WIDTH = 16;

void scrollPrintBottom(String msg, LiquidCrystal *lcd) {
  // for width of lcd
    // go to next column (starting at end)
      // for num columns used
        // print next char
        // if end of msg continue

  // for width of lcd
    // go to next column (starting at end)
      // print msg

  int strLen = msg.length();
  for (int i = LCD_WIDTH - 1; i >= 0; i--) {
    lcd->setCursor(i, 1);
    lcd->print(msg);
    delay(50);

    // write blanks to end of line if necessary
    int blanks = 16 - i - strLen;
    if (blanks > 0) {
      for (int y = 0; y < blanks; y++) {
        lcd->setCursor(15 - y, 1);
        lcd->write(" ");
      }
    }
  }
}
