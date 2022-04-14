/*
 * Name: push-button.ino
 * Description: Example of using a momentary digital push button switch on a
 * pin that is set as an input pullup. With debounce of the push button, and
 * the input pin as an INPUT_PULLUP.
 * */

const byte ledPin = 13;
const byte buttonPin = 4;

byte ledState = LOW;
byte buttonState = HIGH;
byte lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPin, ledState);
}

void loop()
{
  byte reading = digitalRead(buttonPin);

  lastDebounceTime = (reading != lastButtonState) ? millis() : lastDebounceTime;

  if (millis() - lastDebounceTime > debounceDelay)
    if (reading != buttonState)
    {
      buttonState = reading;

      // Do Something Code
      ledState = (buttonState == LOW) ? !ledState : ledState;
    }

  digitalWrite(ledPin, ledState);

  lastButtonState = reading;
}

