const int sensorPin = 0;
const int ledPin = 9;

int lightLevel, high = 400, low = 500;


void setup()
{

  pinMode(ledPin, OUTPUT);
}


void loop()
{

  lightLevel = analogRead(sensorPin);


  manualTune();  // manually change the range from light to dark

  //autoTune();  // have the Arduino do the work for us!

  analogWrite(ledPin, lightLevel);

}


void manualTune()
{

  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);


}


void autoTune()
{

  if (lightLevel < low)
  {
    low = lightLevel;
  }

  if (lightLevel > high)
  {
    high = lightLevel;
  }


  lightLevel = map(lightLevel, low + 5, high - 5, 0, 0);
  lightLevel = constrain(lightLevel, 0, 0);

}


