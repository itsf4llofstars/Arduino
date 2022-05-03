/*
 * The dead foot switch.
 * This piece of code can be used to hold your arduino at the end of the
 * setup function until to through a switch or remove a wire from a pin. We
 * will look at the latter. This is good to prevent the loop from running
 * until
 * */
const uint8_t pulsePin = 2;

const uint32_t ledPer = 1000;
uint32_t ledClk = millis();

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pulsePin, INPUT_PULLUP);

  do {} while (!digitalRead(pulsePin));
}

void loop() {
  flashLed(millis(), &ledClk, ledPer, LED_BUILTIN);

  Serial.println(digitalRead(pulsePin));
}

void flashLed(uint32_t mils, uint32_t *clk, uint32_t per, uint8_t pin) {
  if (mils - *clk >= per) {
    *clk = mils;
    digitalWrite(pin, !digitalRead(pin));
  }
}
