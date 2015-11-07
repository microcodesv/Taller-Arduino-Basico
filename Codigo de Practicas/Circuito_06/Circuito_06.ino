const int sensorPin = 0;
const int ledPin = 9;

int lightLevel, high = 400, low = 500;


void setup()
{

  pinMode(ledPin, OUTPUT);
  Serial.begin (9600);
}


void loop()
{

  lightLevel = analogRead(sensorPin);


  manualTune();

  //autoTune();

  //PruebaMap();

  analogWrite(ledPin, lightLevel);

}


void manualTune()
{

  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  //lightLevel = constrain(lightLevel, 0, 255);

  Serial.println(lightLevel);
  delay (100);
  
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

void PruebaMap()
{

  int valor = 0;
  int potPin = 0;

  valor = analogRead(potPin);
  valor = map (valor, 0, 1023, 100, 500);

  Serial.println(valor);
  delay (1000);

} //fin PruebaMap();



