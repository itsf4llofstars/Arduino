/*
 * Name: push-button.ino
 * Description: Example of using a momentary digital push button switch on a
 * pin that is set as an input pullup. With debounce of the push button.
 * */

const byte ledPin = 13;
const byte buttonPin = 4;

byte ledState = LOW;
byte buttonState = HIGH;
byte lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 20;

unsigned long foo = millis();
unsigned long bar = 500;

void setup()
{
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPin, ledState);
}

void loop()
{
  byte reading = digitalRead(buttonPin);

  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
    Serial.print("lDT: ");
    Serial.println(lastDebounceTime);
  }

  if (millis() - lastDebounceTime > debounceDelay)
  {
    Serial.print("millis() - lDT > dbD: ");
    Serial.println(millis() - lastDebounceTime);
    if (reading != buttonState)
    {
      buttonState = reading;
      Serial.print("bS: ");
      Serial.println(buttonState);

      if (buttonState == LOW)
      {
        ledState = !ledState;
        Serial.print("lS: ");
        Serial.println(ledState);
      }
    }
  }

  digitalWrite(ledPin, ledState);

  lastButtonState = reading;

  // if (millis() - foo >= bar)
  // {
  //   printVals(reading);
  //   foo = millis();
  // }
}

void printVals(byte readPin)
{
  Serial.print("ledSta: ");
  Serial.println(ledState);
  Serial.print("butSta: ");
  Serial.println(buttonState);
  Serial.print("lButSt: ");
  Serial.println(lastButtonState);
  Serial.print("lDbTme: ");
  Serial.println(lastDebounceTime);
  Serial.print("dbDlay: ");
  Serial.println(debounceDelay);
  Serial.print("readin: ");
  Serial.println(readPin);
  Serial.println();
}
