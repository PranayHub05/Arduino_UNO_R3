// Project 06: 8-key Arduino mini piano
// Buttons D2-D9 -> button -> GND, using INPUT_PULLUP.
// Speaker output: D10.
// Notes: C4 D4 E4 F4 G4 A4 B4 C5.
// Frequencies: 262 294 330 349 392 440 494 523 Hz.
//
// Do NOT connect a 4-ohm speaker directly to an Arduino GPIO.
// Use a suitable driver/amplifier. A 2N2222 is not a 2 W audio amplifier.

const int speaker = 10;

const int buttons[8] = {2,3,4,5,6,7,8,9};

const int notes[8] = {
  262, 294, 330, 349,
  392, 440, 494, 523
};

void setup() {
  pinMode(speaker, OUTPUT);

  for (int i = 0; i < 8; i++)
    pinMode(buttons[i], INPUT_PULLUP);
}

void loop() {
  bool notePlaying = false;

  for (int i = 0; i < 8; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      tone(speaker, notes[i]);
      notePlaying = true;
      break;
    }
  }

  if (!notePlaying)
    noTone(speaker);
}
