#include "thermo.h"

#define BAUD 9600

const uint8_t thermoPin = A0;

uint32_t thermoClk = millis();
const uint32_t thermoPer = 10;

uint32_t ledClk = millis();
const uint32_t ledPer = 1000;

void setup()
{
#ifdef BAUD
  Serial.begin(BAUD);
#endif

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(thermoPin, INPUT);
}

void loop()
{
  int16_t thermoVal;

  if (millis() - thermoClk >= thermoPer)
  {
    thermoVal = checkTemp(thermoPin);
    updateClk(&thermoClk, millis());
  }

  flashOnBoardLed(&ledClk, ledPer, LED_BUILTIN, millis());

#ifdef BAUD
  Serial.println(thermoVal);
#endif
}
