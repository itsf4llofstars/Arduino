/*
 * Name: irdetect.ino
 * Description: IR (Flame) detector
 * Note: The use of an analog read of an analog pin will require a deylay of
 *       at least 1 milli-second between analog reads.
 * */
#define BAUD 9600

const uint8_t DIG_IR_DETECT = 4;
const uint8_t LOG_IR_DETECT = A0;

uint32_t ledClk = millis();
const uint32_t ledPer = 1000;

void setup()
{
#ifdef BAUD
  Serial.begin(BAUD);
#endif

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  uint16_t digIr = digitalRead(DIG_IR_DETECT);
  uint16_t logIr = analogRead(LOG_IR_DETECT);

#ifdef BAUD
  Serial.print(digIr);
  Serial.print(" : ");
  Serial.println(logIr);
#endif

  flashLed(millis(), &ledClk, ledPer, LED_BUILTIN);
  delay(1);
}

void flashLed(uint32_t ms, uint32_t *clk, uint32_t per, uint8_t pin)
{
  if (ms - *clk >= per)
  {
    digitalWrite(pin, !digitalRead(pin));
    *clk = ms;
  }
}
