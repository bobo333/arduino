#include <RGBmatrixPanel.h>

#define CLK  8   // USE THIS ON ARDUINO UNO, ADAFRUIT METRO M0, etc.
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
const int DELAY = 5000;

typedef struct point {
    int x;
    int y;
} point;

void setup() {
  matrix.begin();
}

void loop() {
  france();
  italy();
  ireland();
  ukraine();
  scotland();
  canada();
  quebec();
  iceland();
  jollyRoger();
  eu();
  sovietUnion();
  cal();
  // 13 colonies
  // red sox B
  // red sox sox
  // bruins
  // sharks
  // liverpool
  // spain
  // california
  // US
  // old irish flag
  // nasa
  // odessa
  // scrolling middle finger
  // cipriano();
  // sf();
  // greece();
}

void clearScreen() {
  matrix.fillScreen(matrix.Color333(0, 0, 0));
}

void triColor(uint16_t lColor, uint16_t mColor, uint16_t rColor) {
  matrix.fillRect(1, 0, 10, 16, lColor);
  matrix.fillRect(11, 0, 10, 16, mColor);
  matrix.fillRect(21, 0, 10, 16, rColor);
}

void france() {
  clearScreen();
  triColor(matrix.Color333(0, 0, 7), matrix.Color333(7, 7, 7), matrix.Color333(7, 0, 0));
  delay(DELAY);
}

void italy() {
  clearScreen();
  triColor(matrix.Color333(0, 7, 0), matrix.Color333(7, 7, 7), matrix.Color333(7, 0, 0));
  delay(DELAY);
}

void ireland() {
  clearScreen();
  triColor(matrix.Color333(0, 7, 0), matrix.Color333(7, 7, 7), matrix.Color333(7, 2, 0));
  delay(DELAY);
}

void ukraine() {
  clearScreen();
  matrix.fillRect(0, 0, 32, 8, matrix.Color333(0, 3, 7));
  matrix.fillRect(0, 8, 32, 8, matrix.Color333(7, 7, 0));
  delay(DELAY);
}

void scotland() {
  clearScreen();
  matrix.fillScreen(matrix.Color333(0, 0, 7));
  matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 7, 7));
  matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 7, 7));
  delay(DELAY);
}

void canada() {
  clearScreen();
  matrix.fillScreen(matrix.Color333(7, 0, 0));
  matrix.fillRect(9, 0, 14, 16, matrix.Color333(7, 7, 7));
  // leaf
  matrix.fillRect(15, 2, 2, 13, matrix.Color333(7, 0, 0));
  matrix.drawLine(17, 10, 21, 6, matrix.Color333(7, 0, 0));
  matrix.drawLine(17, 9, 20, 6, matrix.Color333(7, 0, 0));
  matrix.drawLine(17, 11, 21, 7, matrix.Color333(7, 0, 0));
  matrix.drawLine(17, 12, 21, 8, matrix.Color333(7, 0, 0));
  matrix.drawLine(14, 10, 10, 6, matrix.Color333(7, 0, 0));
  matrix.drawLine(14, 9, 11, 6, matrix.Color333(7, 0, 0));
  matrix.drawLine(14, 11, 10, 7, matrix.Color333(7, 0, 0));
  matrix.drawLine(14, 12, 10, 8, matrix.Color333(7, 0, 0));
  matrix.drawLine(14, 3, 14, 8, matrix.Color333(7, 0, 0));
  matrix.drawLine(17, 3, 17, 8, matrix.Color333(7, 0, 0));
  delay(DELAY);
}

void quebec() {
  clearScreen();
  uint16_t white = matrix.Color333(5, 5, 5);
  matrix.fillScreen(matrix.Color333(0, 0, 7));
  matrix.fillRect(0, 7, 32, 2, white);
  matrix.fillRect(15, 0, 2, 16, white);
  fleurDeLis(7, 1, white);
  fleurDeLis(24, 1, white);
  fleurDeLis(7, 10, white);
  fleurDeLis(24, 10, white);
  delay(DELAY);
}

void fleurDeLis(int x, int y, uint16_t color) {
  matrix.drawLine(x, y, x, y+4, color);
  matrix.drawLine(x-1, y+1, x+1, y+1, color);
  matrix.drawLine(x-2, y+3, x+2, y+3, color);
}

void iceland() {
  clearScreen();
  matrix.fillScreen(matrix.Color444(0, 0, 2));
  matrix.fillRect(0, 6, 32, 4, matrix.Color333(1, 1, 1));
  matrix.fillRect(8, 0, 4, 16, matrix.Color333(1, 1, 1));
  matrix.fillRect(0, 7, 32, 2, matrix.Color333(3, 0, 0));
  matrix.fillRect(9, 0, 2, 16, matrix.Color333(3, 0, 0));
  delay(DELAY);
}

void jollyRoger() {
  clearScreen();
  // head
  matrix.fillRect(11, 0, 10, 8, matrix.Color333(3, 3, 3));
  matrix.drawPixel(11, 0, matrix.Color333(0, 0, 0));
  matrix.drawPixel(20, 0, matrix.Color333(0, 0, 0));
  matrix.drawPixel(11, 6, matrix.Color333(0, 0, 0));
  matrix.drawPixel(11, 7, matrix.Color333(0, 0, 0));
  matrix.drawPixel(12, 7, matrix.Color333(0, 0, 0));
  matrix.drawPixel(20, 6, matrix.Color333(0, 0, 0));
  matrix.drawPixel(20, 7, matrix.Color333(0, 0, 0));
  matrix.drawPixel(19, 7, matrix.Color333(0, 0, 0));
  // eyes
  matrix.fillRect(13, 2, 2, 2, matrix.Color333(0, 0, 0));
  matrix.fillRect(17, 2, 2, 2, matrix.Color333(0, 0, 0));
  // mouth
  matrix.fillRect(15, 6, 2, 1, matrix.Color333(0, 0, 0));
  // bones
  matrix.fillRect(21, 8, 3, 3, matrix.Color333(3, 3, 3));
  matrix.fillRect(21, 13, 3, 3, matrix.Color333(3, 3, 3));
  matrix.fillRect(8, 8, 3, 3, matrix.Color333(3, 3, 3));
  matrix.fillRect(8, 13, 3, 3, matrix.Color333(3, 3, 3));
  matrix.drawLine(11, 9, 20, 14, matrix.Color333(3, 3, 3));
  matrix.drawLine(11, 14, 20, 9, matrix.Color333(3, 3, 3));
  delay(DELAY);
}

void eu() {
  clearScreen();
  uint16_t gold = matrix.Color444(15, 13, 0);
  matrix.fillScreen(matrix.Color444(0, 0, 4));
  // stars
  matrix.fillRect(15, 1, 2, 2, gold);
  matrix.fillRect(15, 13, 2, 2, gold);
  matrix.fillRect(21, 7, 2, 2, gold);
  matrix.fillRect(9, 7, 2, 2, gold);
  matrix.fillRect(19, 3, 2, 2, gold);
  matrix.fillRect(11, 3, 2, 2, gold);
  matrix.fillRect(11, 11, 2, 2, gold);
  matrix.fillRect(19, 11, 2, 2, gold);
  delay(DELAY);
}

void sovietUnion() {
  clearScreen();
  uint16_t gold = matrix.Color444(15, 12, 0);
  matrix.fillScreen(matrix.Color444(7, 0, 0));
  // hammer
  matrix.drawLine(3, 5, 4, 4, gold);
  matrix.drawLine(3, 6, 5, 4, gold);
  matrix.drawLine(5, 6, 8, 9, gold);
  // sickle
  matrix.drawLine(3, 9, 4, 8, gold);
  matrix.drawPixel(5, 8, gold);
  matrix.drawPixel(7, 7, gold);
  matrix.drawPixel(8, 6, gold);
  matrix.drawPixel(8, 5, gold);
  matrix.drawPixel(7, 4, gold);
  // star
  matrix.fillRect(5, 1, 2, 2, gold);
  delay(DELAY);
}

void cal() {
  clearScreen();
  uint16_t gold = matrix.Color444(15, 12, 0);
  matrix.fillScreen(matrix.Color444(0, 0, 1));

  point deltas[] = {
    point{1, -1},
    point{-1, -1},
    point{-1, 0},
    point{-1, 0},
    point{-1, 1},
    point{-1, 1},
    point{-1, 1},
    point{0, 1},
    point{0, 1},
    point{0, 1},
    point{1, 1},
    point{1, 1},
    point{1, 0},
    point{1, 0},
    point{1, 0},
    point{1, -1},
    point{1, -1},
    point{1, -1},
    point{1, 0},
    point{1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 1},
    point{0, 1},
    point{1, 1},
    point{1, 0},
    point{1, -1},
    point{0, -1},
    point{0, 1},
    point{1, 1},
    point{1, 0},
    point{1, -1},
    point{1, -1},
    point{1, -1},
    point{0, -1},
    point{0, -1},
    point{0, -1},
    point{0, -1},
    point{-1, -1},
    point{-1, 1},
    point{0, 1},
    point{0, 1},
    point{0, 1},
    point{0, 1},
    point{1, 1},
    point{1, 1},
    point{1, 1},
    point{1, 1},
    point{-1, 1},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 0},
    point{-1, 1},
    point{0, 0}
  };

  deltas.length;

  script(12, 4, deltas, gold);
  
  delay(DELAY);
}

void script(int x, int y, point deltas[], uint16_t color) {
  matrix.drawPixel(x, y, color);
  
  for (int i = 0; i < deltas.length; i++) {
    point delta = deltas[i];
    if (delta.x == 0 && delta.y == 0) {
      break;
    }

    x = x + delta.x;
    y = y + delta.y;

    matrix.drawPixel(x, y, color);
    delay(150);
  }
}
