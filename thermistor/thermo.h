#ifndef THERMO_H
#define THERMO_H

int checkTemp(uint8_t pin)
{
  return analogRead(pin);
}

void updateClk(uint32_t *pClk, uint32_t milliSecs)
{
  pClk = milliSecs;
}

void flashOnBoardLed(uint32_t *pClk, uint32_t per, uint8_t pin,
                     uint32_t milliSecs)
{
  if (milliSecs - *pClk >= per)
  {
    digitalWrite(pin, !digitalRead(pin));
    *pClk = milliSecs;
  }
}
#endif

