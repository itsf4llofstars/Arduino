/*
 * Name: push-button.ino
 * Description: Example of using a momentary digital push button switch on a
 * pin that is set as an input pullup.
 * */
#define BAUD 9600

byte pinFour = 4;

uint32_t ledClk = millis();
const uint32_t ledPer = 1000;

void setup()
{
#ifdef BAUD
  Serial.begin(BAUD);
#endif

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinFour, INPUT_PULLUP);
}

void loop()
{
  byte four = digitalRead(pinFour);

  if (four)
    digitalWrite(LED_BUILTIN, !HIGH);
  else if (!(four))
    digitalWrite(LED_BUILTIN, HIGH);

#ifdef BAUD
  Serial.println(four);
#endif

  // flashLed(millis(), &ledClk, ledPer, LED_BUILTIN);
}

void flashLed(uint32_t ms, uint32_t *clk, uint32_t per, uint8_t pin)
{
  if (ms - *clk >= per)
  {
    digitalWrite(pin, !digitalRead(pin));
    *clk = ms;
  }
}
