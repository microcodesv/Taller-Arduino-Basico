void setup()
{
  pinMode(13, OUTPUT);      //Declaracion de pin
}

void loop()
{
  digitalWrite(13, HIGH);   // Turno de LED encendido
  delay(1000);              // Esperar un segundo
  
  digitalWrite(13, LOW);    // Turno de LED apagado
  delay(1000);              // Esperar un segundo
}

