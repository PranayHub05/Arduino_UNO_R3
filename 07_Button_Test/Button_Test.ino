// Project 07: Two-pin push-button test
// D12 -> push button -> GND.
// Built-in L LED is on D13.

const int buttonPin = 12;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
