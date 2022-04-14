/*
 * Name: push-button.ino
 * Description: Example of using a momentary digital push button switch on a
 * pin that is set as an input pullup. With debounce of the push button, and
 * the input pin as an INPUT_PULLUP.
 * */

const byte ledPin = 13;
const byte btnPin = 4;

byte ledSt = LOW;
byte btnSt = HIGH;
byte lastBtnSt = HIGH;

unsigned long lastDbT = 0;
unsigned long dbD = 50;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);

  digitalWrite(ledPin, ledSt);
}

void loop()
{
  byte pinVal = digitalRead(btnPin);

  lastDbT = (pinVal != lastBtnSt) ? millis() : lastDbT;

  if (millis() - lastDbT > dbD)
    if (pinVal != btnSt)
    {
      btnSt = pinVal;

      // Do Something after delay has been met
      ledSt = (btnSt == LOW) ? !ledSt : ledSt;
    }

  digitalWrite(ledPin, ledSt);

  lastBtnSt = pinVal;
}

