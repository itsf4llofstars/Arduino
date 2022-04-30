/*
 * This documentation is in no way ment to clear and concise
 *
 * Simple, non-clean, nor fancy example of using interrupts pins 2 and 3
 * on the Arduino UNO board
 *
 * It's easy to see after changing the led period (interrupt pin two)
 * to a longer period to reset (interrupt pin three) while one or more
 * led's are on.
 **/

#define BAUD 9600

const byte ledPin = 13;
const byte interruptPin2 = 2;
const byte interruptPin3 = 3;
const byte ledPin4 = 4;
const byte ledPin5 = 5;

// normally constant (const)
unsigned long led13Per = 125;
unsigned long led4Per = 250;
unsigned long led5Per = 500;

unsigned long led13Clk = millis();
unsigned long led4Clk = millis();
unsigned long led5Clk = millis();

volatile bool flag2 = false;
volatile bool flag3 = false;

void setup() {
  Serial.begin(BAUD);

  for (byte i = 0; i < 6; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin2), stateTwo, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), stateThree, FALLING);

  // Most likely not needed
  flag2 = false;
  flag3 = false;
  delay(125);
}

void loop() {
  flashLed(millis(), &led13Clk, led13Per, ledPin);
  flashLed(millis(), &led4Clk, led4Per, ledPin4);
  flashLed(millis(), &led5Clk, led5Per, ledPin5);

  Serial.print(digitalRead(interruptPin2));
  Serial.print(" ");
  Serial.print(digitalRead(interruptPin3));
  Serial.print(" ");
  Serial.print(flag2);
  Serial.print(" ");
  Serial.println(flag3);

  if (flag2) {
    flag2 = false;

    for (byte i = 4; i < 14; ++i) {
      digitalWrite(i, LOW);
    }

    led13Clk = millis();
    led4Clk = millis();
    led5Clk = millis();

    led13Per = 1250;
    led4Per = 2500;
    led5Per = 5000;
  }

  if (flag3) {
    flag3 = false;

    for (byte i = 4; i < 14; ++i) {
      digitalWrite(i, LOW);
    }

    led13Clk = millis();
    led4Clk = millis();
    led5Clk = millis();

    led13Per = 125;
    led4Per = 250;
    led5Per = 500;
  }
}

void stateTwo() {
  flag2 = true;
}

void stateThree() {
  flag3 = true;
}

void flashLed(unsigned long mils, unsigned long *clk, unsigned long per, byte pin) {
  if (mils - *clk >= per) {
    *clk = mils;
    digitalWrite(pin, !digitalRead(pin));
  }
}
