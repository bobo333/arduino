#include <RGBmatrixPanel.h>

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
  matrix.begin();

  matrix.drawRect(10, 8, 11, 5, matrix.Color333(0, 7, 0));
  matrix.drawRect(14, 3, 3, 6, matrix.Color333(0, 7, 0));
  matrix.drawPixel(15, 8, matrix.Color333(0, 0, 0));
  matrix.drawLine(18, 8, 18, 10, matrix.Color333(0, 7, 0));
  matrix.drawLine(16, 8, 16, 10, matrix.Color333(0, 7, 0));
  matrix.drawLine(14, 8, 14, 10, matrix.Color333(0, 7, 0));
  matrix.drawLine(12, 8, 12, 10, matrix.Color333(0, 7, 0));
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
