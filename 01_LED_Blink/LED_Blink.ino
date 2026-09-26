// Project 01: Basic LED Blink
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
