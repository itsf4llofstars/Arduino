/*
 * A simple sketch utilizing the light sensor
 * */

#define BAUD 9600

const uint8_t led = 13;
const uint8_t sensorPin = A0;

uint32_t lightClk = millis();
const uint32_t lightPer = 10;

void setup()
{
#ifdef BAUD
  Serial.begin(BAUD);
#endif

  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  uint16_t lightVal;

  if (millis() - lightClk >= lightPer)
  {
    lightVal = analogRead(sensorPin);
    lightClk = millis();
  }

  if (lightVal >= 100)
    digitalWrite(led, HIGH);
  else if (lightVal < 100)
    digitalWrite(led, LOW);

#ifdef BAUD
  Serial.println(lightVal);
#endif
}
