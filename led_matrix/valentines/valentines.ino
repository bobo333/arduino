#include <RGBmatrixPanel.h>

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
const int DELAY = 1000;

typedef struct point {
    int x;
    int y;
} point;

void setup() {
  matrix.begin();
}

void loop() {
  valentines();
}

void valentines() {
  // write happy valentines day
  matrix.setTextSize(1);

  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(0, 0);
  matrix.setTextColor(matrix.Color333(7, 0, 0));

  matrix.print("Happy");
  delay(2000);

  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(0, 0);
  matrix.print("Valentines");

  delay(2000);

  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setCursor(0, 0);
  matrix.print("Day!");

  delay(2000);

  matrix.fillScreen(matrix.Color333(0, 0, 0));

  matrix.setTextSize(2);
  matrix.setCursor(11, 1);
  matrix.setTextColor(matrix.Color333(0, 7, 0));
  matrix.print("I");

  delay(2000);
  matrix.fillScreen(matrix.Color333(0, 0, 0));


  // draw heart
  uint16_t pink = matrix.Color333(7, 0, 7);
  matrix.fillCircle(11, 5, 4, pink);
  matrix.fillCircle(20, 5, 4, pink);
  matrix.drawLine(15, 15, 8, 8, pink);
  matrix.drawLine(16, 15, 23, 8, pink);
  for (int i = 0; i < 5; i++) {
    matrix.drawLine(15 - i, 14 - i, 15-i, 5, pink);
    matrix.drawLine(16 + i, 14 - i, 16+i, 5, pink);
  }
  delay(2000);

  matrix.fillScreen(matrix.Color333(0, 0, 0));
  matrix.setTextSize(1);
  matrix.setTextColor(matrix.Color333(0, 7, 0));
  matrix.setCursor(4, 4);
  matrix.print("Y");
  delay(20);
  matrix.setTextColor(matrix.Color333(7, 7, 0));
  matrix.print("U");
  delay(20);
  matrix.setTextColor(matrix.Color333(0, 0, 7));
  matrix.print("Y");
  delay(20);
  matrix.setTextColor(matrix.Color333(7, 2, 0));
  matrix.print("U");
  delay(2000);
}
