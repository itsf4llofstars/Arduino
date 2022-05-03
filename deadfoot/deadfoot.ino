/*
 * The dead foot switch.
 * This piece of code can be used to hold your arduino at the end of the
 * setup function until to through a switch or remove a wire from a pin. We
 * will look at the latter. This is good to prevent the loop from running
 * until
 * */

// #define BAUD 9600

const uint8_t touchPin = 12;
const uint8_t touchPinLed = 11;
const uint8_t pulsePin = 2;

const uint32_t ledPer = 1000;
uint32_t ledClk = millis();

void setup() {
#ifdef BAUD
  Serial.begin(BAUD);
#endif

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(touchPin, INPUT_PULLUP);
  pinMode(touchPinLed, OUTPUT);
  pinMode(pulsePin, INPUT_PULLUP);

  // dead foot code
  digitalWrite(touchPinLed, HIGH);

  // Checks for the pin to got from high to low
  do {} while (!pulseIn(pulsePin, HIGH, 1000));

  digitalWrite(touchPinLed, LOW);
}

void loop() {
  uint8_t touchPinVal = digitalRead(touchPin);

  digitalWrite(touchPinLed, (touchPinVal) ? HIGH : LOW);

  flashLed(millis(), &ledClk, ledPer, LED_BUILTIN);

#ifdef BAUD
  Serial.println(touchPinVal);
#endif
}

void flashLed(uint32_t mils, uint32_t *clk, uint32_t per, uint8_t pin) {
  if (mils - *clk >= per) {
    *clk = mils;
    digitalWrite(pin, !digitalRead(pin));
  }
}
