/*
 * A simple sketch utilizing the light sensor
 * */
const int baud = 9600;
const uint8_t sensorPin = A5;

int lightVal;

uint32_t lightClk = millis();
const uint32_t lightPer = 10;

const byte adc = 1;

void setup() {
  Serial.begin(baud);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensorPin, INPUT);

  lightVal = analogRead(sensorPin);
  delay(adc);
}

void loop() {
  if (millis() - lightClk >= lightPer) {
    lightVal = analogRead(sensorPin);
    lightClk = millis();
    Serial.println(lightVal);
  }
}
