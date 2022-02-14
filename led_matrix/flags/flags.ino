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
  france();
  delay(DELAY);
  clearScreen();
  italy();
  delay(DELAY);
  clearScreen();
  ireland();
  delay(DELAY);
  clearScreen();
  ukraine();
  delay(DELAY);
  clearScreen();
  scotland();
  delay(DELAY);
  clearScreen();
  canada();
  delay(DELAY);
  clearScreen();
  quebec();
  delay(DELAY);
  clearScreen();
  iceland();
  delay(DELAY);
  clearScreen();
  jollyRoger();
  delay(DELAY);
  clearScreen();
  eu();
  delay(DELAY);
  clearScreen();
  sovietUnion();
  delay(DELAY);
  clearScreen();
  cal();
  delay(DELAY);
  clearScreen();
  fu();
  delay(DELAY);
  clearScreen();
  kosmo();
  delay(DELAY);
  clearScreen();
  colonies();
  delay(DELAY);
  clearScreen();
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
  // cipriano();
  // sf();
  // greece();

  // transitions
  // concentric rings from various locations (ripples)
  // concentric squares/rectangles (square ripples)
  // pixels randomly cycle until correct color
}

void clearScreen() {
  void (*transitions[])() = {
    wipeLeft,
    wipeRight,
    wipeTop,
    wipeBottom,
    wipeCircleOut,
    wipeSquareOut,
    wipeSquareIn,
    wipeMatrix,
    pixelFade
  };

  randomSeed(analogRead(4));
  int r = random(9);
  transitions[r]();
}

/*
 * FLAGS
 */

void triColor(uint16_t lColor, uint16_t mColor, uint16_t rColor) {
  matrix.fillRect(1, 0, 10, 16, lColor);
  matrix.fillRect(11, 0, 10, 16, mColor);
  matrix.fillRect(21, 0, 10, 16, rColor);
}

void france() {
  triColor(matrix.Color333(0, 0, 7), matrix.Color333(7, 7, 7), matrix.Color333(7, 0, 0));
}

void italy() {
  triColor(matrix.Color333(0, 7, 0), matrix.Color333(7, 7, 7), matrix.Color333(7, 0, 0));
}

void ireland() {
  triColor(matrix.Color333(0, 7, 0), matrix.Color333(7, 7, 7), matrix.Color333(7, 2, 0));
}

void ukraine() {
  matrix.fillRect(0, 0, 32, 8, matrix.Color333(0, 3, 7));
  matrix.fillRect(0, 8, 32, 8, matrix.Color333(7, 7, 0));
}

void scotland() {
  matrix.fillScreen(matrix.Color333(0, 0, 7));
  matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 7, 7));
  matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 7, 7));
}

void canada() {
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
}

void quebec() {
  uint16_t white = matrix.Color333(5, 5, 5);
  matrix.fillScreen(matrix.Color333(0, 0, 7));
  matrix.fillRect(0, 7, 32, 2, white);
  matrix.fillRect(15, 0, 2, 16, white);
  fleurDeLis(7, 1, white);
  fleurDeLis(24, 1, white);
  fleurDeLis(7, 10, white);
  fleurDeLis(24, 10, white);
}

void fleurDeLis(int x, int y, uint16_t color) {
  matrix.drawLine(x, y, x, y+4, color);
  matrix.drawLine(x-1, y+1, x+1, y+1, color);
  matrix.drawLine(x-2, y+3, x+2, y+3, color);
}

void iceland() {
  matrix.fillScreen(matrix.Color444(0, 0, 2));
  matrix.fillRect(0, 6, 32, 4, matrix.Color333(1, 1, 1));
  matrix.fillRect(8, 0, 4, 16, matrix.Color333(1, 1, 1));
  matrix.fillRect(0, 7, 32, 2, matrix.Color333(3, 0, 0));
  matrix.fillRect(9, 0, 2, 16, matrix.Color333(3, 0, 0));
}

void jollyRoger() {
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
}

void eu() {
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
}

void sovietUnion() {
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
}

void cal() {
  uint16_t gold = matrix.Color444(15, 12, 0);
  matrix.fillScreen(matrix.Color444(0, 0, 1));

  point deltas[100] = {
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

  script(12, 4, deltas, gold);
}

void script(int x, int y, point deltas[100], uint16_t color) {
  matrix.drawPixel(x, y, color);
  
  for (int i = 0; i < 100; i++) {
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

void fu() {
  // rect divisible by 4
  matrix.drawRect(12, 6, 9, 5, matrix.Color333(7, 7, 7));
  // inner rect(s) to complete the 4
  matrix.drawRect(14, 6, 3, 5, matrix.Color333(7, 7, 7));
  matrix.drawLine(18, 6, 18, 10, matrix.Color333(7, 7, 7));
  // smaller outer rect for thumb
  matrix.drawRect(10, 6, 3, 3, matrix.Color333(7, 7, 7));

  // slowly increase height of inner rect for finger going up
  for (int i = 0; i < 5; i++) {
    delay(250);
    matrix.drawRect(14, 5-i, 3, 6+i, matrix.Color333(7, 7, 7));
    matrix.drawPixel(15, 6-i, matrix.Color333(0, 0, 0));
  }

  // flash fuck off on and off
  for (int i = 0; i < 7; i++) {
    // f
    uint16_t red = matrix.Color333(7, 0, 0);
    matrix.drawLine(0, 11, 0, 15, red);
    matrix.drawLine(0, 11, 2, 11, red);
    matrix.drawLine(0, 13, 2, 13, red);

    // u
    uint16_t orange = matrix.Color333(7, 3, 0);
    matrix.drawLine(4, 11, 4, 15, orange);
    matrix.drawLine(4, 15, 6, 15, orange);
    matrix.drawLine(6, 15, 6, 11, orange);

    // c
    uint16_t yellow = matrix.Color333(7, 7, 0);
    matrix.drawLine(8, 11, 8, 15, yellow);
    matrix.drawLine(8, 11, 10, 11, yellow);
    matrix.drawLine(8, 15, 10, 15, yellow);

    // k purple
    uint16_t green = matrix.Color333(0, 7, 0);
    matrix.drawLine(12, 11, 12, 15, green);
    matrix.drawLine(13, 13, 15, 11, green);
    matrix.drawLine(13, 13, 15, 15, green);

    delay(500);

    if (i < 6) {
      // clear
      matrix.fillRect(0, 11, 17, 5, matrix.Color333(0, 0, 0));
    }

    // o
    matrix.drawRect(19, 11, 4, 5, matrix.Color333(0, 0, 7));

    // f
    uint16_t pink = matrix.Color333(2, 0, 3);
    matrix.drawLine(24, 11, 24, 15, pink);
    matrix.drawLine(24, 11, 26, 11, pink);
    matrix.drawLine(24, 13, 26, 13, pink);

    // f
    uint16_t turquoise = matrix.Color333(1, 6, 4);
    matrix.drawLine(28, 11, 28, 15, turquoise);
    matrix.drawLine(28, 11, 30, 11, turquoise);
    matrix.drawLine(28, 13, 30, 13, turquoise);

    if (i < 6) {
      // pause then clear
      delay(500);
      matrix.fillRect(18, 11, 17, 5, matrix.Color333(0, 0, 0));
    }
  }
}

void kosmo() {
  matrix.setTextSize(1);

  matrix.setCursor(0, 0);
  matrix.setTextColor(matrix.Color333(7, 0, 0));
  matrix.print("K");

  matrix.setCursor(7, 2);
  matrix.setTextColor(matrix.Color333(0, 7, 0));
  matrix.print("O");

  matrix.setCursor(14, 4);
  matrix.setTextColor(matrix.Color333(0, 0, 7));
  matrix.print("S");

  matrix.setCursor(21, 6);
  matrix.setTextColor(matrix.Color333(7, 0, 7));
  matrix.print("M");

  matrix.drawRect(27, 8, 5, 7, matrix.Color333(7, 7, 0));
  matrix.drawPixel(27, 8, matrix.Color333(0, 0, 0));
  matrix.drawPixel(31, 8, matrix.Color333(0, 0, 0));
  matrix.drawPixel(27, 14, matrix.Color333(0, 0, 0));
  matrix.drawPixel(31, 14, matrix.Color333(0, 0, 0));
}

void colonies() {
  // top left rect
  matrix.fillRect(0, 1, 11, 7, matrix.Color333(0, 0, 7));

  // top left circle
  matrix.drawCircle(5, 4, 2, matrix.Color333(7, 7, 7));

  // stripes
  uint16_t red = matrix.Color333(7, 0, 0);
  uint16_t white = matrix.Color333(7, 7, 7);
  uint16_t color;

  for (int i = 0; i < 13; i++) {
    if (i%2 == 0) {
      color = red;
    } else {
      color = white;
    }
    if (i < 7) {
      matrix.drawLine(11, 1+i, 31, 1+i, color);
    } else {
      matrix.drawLine(0, 1+i, 31, 1+i, color);
    }
  }
}

/*
 * TRANSITIONS
 */

void wipeLeft() {
  for (int i = 0; i <= 32; i++) {
    matrix.fillRect(0, 0, i, 16, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

void wipeRight() {
  for (int i = 0; i < 32; i++) {
    matrix.fillRect(31-i, 0, i+1, 16, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

void wipeTop() {
  for (int i = 0; i < 16; i++) {
    matrix.fillRect(0, i, 32, i, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

void wipeBottom() {
  for (int i = 0; i <= 16; i++) {
    matrix.fillRect(0, 16-i, 32, i, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

// TODO: support centering circle in different places
void wipeCircleOut() {
  // radius must go slightly larger than width to account for diagonal
  for (int i = 0; i < 19; i++) {
    matrix.fillCircle(15, 7, i, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

// TODO: has bugs, because circle is not being filled it misses some pixels
void wipeCircleIn() {
  for (int i = 0; i < 16; i++) {
    matrix.drawCircle(15, 7, 16-i, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

// TODO: support arbitrary placement
void wipeSquareOut() {
  for (int i = 1; i < 32; i++) {
    matrix.drawRect(16-i, 8-i, 2*i, 2*i, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

// TODO: support arbitrary placement
void wipeSquareIn() {
  // start on sides
  for (int i = 0; i < 8; i++) {
    matrix.drawLine(i, 0, i, 15, matrix.Color333(0, 0, 0));
    matrix.drawLine(31-i, 0, 31-i, 15, matrix.Color333(0, 0, 0));
    delay(30);
  }

  for (int i = 0; i < 8; i++) {
    matrix.drawRect(8+i, i, 16-2*i, 16-2*i, matrix.Color333(0, 0, 0));
    delay(30);
  }
}

// TODO: support already-empty columns
void wipeMatrix() {
  int cols[32];
  for (int i = 0; i < 32; i++) {
    cols[i] = i;
  }

  int n = 31;
  randomSeed(analogRead(4));

  // "truncate" the array without actually truncating the array
  while (n >= 0) {
    int r = random(n);
    wipeCol(cols[r]);
    cols[r] = cols[n];
    n--;
  }
}

void wipeCol(int col) {
  for (int i = 0; i < 16; i++) {
    matrix.drawLine(col, 0, col, i, matrix.Color333(0, 0, 0));
    delay(20);
  }
}

/*
 * Must do chunks of 2, running out of memory when doing individual pixels
 */
void pixelFade() {
  int numPixel = 256;
  int pixels[numPixel];
  for (int i = 0; i < numPixel; i++) {
    pixels[i] = i;
  }

  randomSeed(analogRead(4));
  int p = numPixel-1;
  while (p >= 0) {
    int r = random(p);
    deletePixel(pixels[r]);
    pixels[r] = pixels[p];
    p--;
  }
}

void deletePixel(int p) {
  int row = p / 16;
  int col = p % 16;
  matrix.fillRect(2*col, 2*row, 2, 2, matrix.Color333(0, 0, 0));
  delay(30);
}

// void diagWipe
