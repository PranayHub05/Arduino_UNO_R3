// Project 03: Software fade experiment on Uno pin 13.
// Pin 13 is NOT a hardware PWM pin on the Uno.
// True PWM pins: 3, 5, 6, 9, 10, 11.

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(i * 100);
    digitalWrite(ledPin, LOW);
    delayMicroseconds((100 - i) * 100);
  }

  for (int i = 100; i > 0; i--) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(i * 100);
    digitalWrite(ledPin, LOW);
    delayMicroseconds((100 - i) * 100);
  }
}
