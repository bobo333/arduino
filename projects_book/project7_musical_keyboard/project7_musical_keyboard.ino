/*
 * 2 buttons at once doesn't really change the analog measurement except very slightly on the 10Kohm and 5Mohm, probably because the resistances are too far apart.
 * Apparently resistance should be doubled each time to be useful. Tested with 220ohm vs 560ohm and the difference could be seen.
 */
int notes[] = {262, 294, 330, 349}; // Hz

void setup() {
  Serial.begin(9600);

}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  /*
   * > 0 < 100
   * > 450 < 600
   * > 950 < 1015
   * > 1020
   */
  if (keyVal > 0 && keyVal < 100) {
    tone(8, notes[0]);
  } else if (keyVal > 450 && keyVal < 600) {
    tone(8, notes[1]);
  } else if (keyVal > 950 && keyVal < 1015) {
    tone(8, notes[2]);
  } else if (keyVal > 1020) {
    tone(8, notes[3]);
  } else {
    noTone(8);
  }
}
