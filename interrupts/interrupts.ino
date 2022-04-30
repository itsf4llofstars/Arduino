/*
 * Example of using interrputs and theri pins
 **/

#define BAUD 9600

const byte ledPin = 13;
const byte interruptPin2 = 2;
const byte nterruptPin3 = 3;
const byte ledPin4 = 4;
const byte ledPin5 = 5;

volatile bool flag2 = false;
volatile bool flag3 = false;

void setup() {
  Serial.begin(BAUD);

  for (byte i = 0; i < 14; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin2), interruptTwo, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), interruptThree, FALLING);

  flag2 = false;
  flag3 = false;
}

void loop() {

}

void interruptTwo() {
  flag2 = true;
}

void interruptThree() {
  flag3 = true;
}
