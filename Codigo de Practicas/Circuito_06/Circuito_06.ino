const int sensorPin = 0;
const int ledPin = 2;

int lightLevel, high = 215, low = 130;


void setup()
{

  pinMode(ledPin, OUTPUT);
  Serial.begin (9600);
}


void loop()
{

  lightLevel = analogRead(sensorPin);


  //manualTune();

  autoTune();

  analogWrite(ledPin, lightLevel);

}


void manualTune()
{

  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);

  Serial.println(lightLevel);
  delay (100);
  
}


void autoTune()
{

  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);

if (lightLevel >= 130);
{
 pinMode(ledPin,HIGH);
}
else
{
  pinMode(ledPin, LOW);
} 

}





