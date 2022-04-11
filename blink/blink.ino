/*
 * Simple blink sketch. To use the blink with millis() function, delete the
 * two line of code under the void loop() call and call the blinkMillis();
 * function. You will need to set the ledPer variable to your on/off times.
 * setting ledPer = 1000; is a one second on one second off flash rate.
 * */

unsigned long ledClk = millis();
const unsigned long ledPer = 1000;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(333);

  // blinkMillis();
}

void blinkMillis()
{
  if (millis() - ledClk >= ledPer)
  {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    ledClk = millis();
  }
}

