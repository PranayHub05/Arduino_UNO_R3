// Project 05: 8 LED controller with four patterns
// LEDs: D2-D9, each through its own 220 ohm resistor to GND.
// Switch: D12 <-> switch <-> D13.
// D12 = INPUT_PULLUP; D13 is held LOW.

const int leds[] = {2,3,4,5,6,7,8,9};
const int numberOfLEDs = 8;
const int buttonPin = 12;
const int buttonGround = 13;

int pattern = 0;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
unsigned long previousMillis = 0;
const unsigned long patternSpeed = 100;

void setup() {
  for (int i = 0; i < numberOfLEDs; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonGround, OUTPUT);
  digitalWrite(buttonGround, LOW);
}

void loop() {
  checkButton();

  switch (pattern) {
    case 0: smoothTrail(); break;
    case 1: alternateBlink(); break;
    case 2: fillAndClear(); break;
    case 3: centerOut(); break;
  }
}

void checkButton() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState)
    lastDebounceTime = millis();

  if ((millis() - lastDebounceTime) > debounceDelay) {
    static int stableState = HIGH;

    if (reading != stableState) {
      stableState = reading;

      if (stableState == LOW) {
        pattern++;
        if (pattern > 3) pattern = 0;
        allOff();
        previousMillis = millis();
      }
    }
  }

  lastButtonState = reading;
}

void smoothTrail() {
  static int position = 0;

  if (millis() - previousMillis >= patternSpeed) {
    previousMillis = millis();
    allOff();

    digitalWrite(leds[position], HIGH);
    if (position - 1 >= 0) digitalWrite(leds[position - 1], HIGH);
    if (position - 2 >= 0) digitalWrite(leds[position - 2], HIGH);

    position++;
    if (position >= numberOfLEDs) position = 0;
  }
}

void alternateBlink() {
  static bool state = false;

  if (millis() - previousMillis >= 300) {
    previousMillis = millis();
    state = !state;

    for (int i = 0; i < numberOfLEDs; i++) {
      digitalWrite(leds[i], (i % 2 == 0) ? state : !state);
    }
  }
}

void fillAndClear() {
  static int position = 0;
  static bool filling = true;

  if (millis() - previousMillis >= 120) {
    previousMillis = millis();

    if (filling) {
      digitalWrite(leds[position], HIGH);
      position++;
      if (position >= numberOfLEDs) {
        position = numberOfLEDs - 1;
        filling = false;
      }
    } else {
      digitalWrite(leds[position], LOW);
      position--;
      if (position < 0) {
        position = 0;
        filling = true;
      }
    }
  }
}

void centerOut() {
  static int step = 0;

  if (millis() - previousMillis >= 180) {
    previousMillis = millis();
    allOff();

    if (step == 0) {
      digitalWrite(leds[3], HIGH);
      digitalWrite(leds[4], HIGH);
    } else if (step == 1) {
      for (int i = 2; i <= 5; i++) digitalWrite(leds[i], HIGH);
    } else if (step == 2) {
      for (int i = 1; i <= 6; i++) digitalWrite(leds[i], HIGH);
    } else if (step == 3) {
      for (int i = 0; i < numberOfLEDs; i++) digitalWrite(leds[i], HIGH);
    }

    step++;
    if (step > 4) step = 0;
  }
}

void allOff() {
  for (int i = 0; i < numberOfLEDs; i++)
    digitalWrite(leds[i], LOW);
}
