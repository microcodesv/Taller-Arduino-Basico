int Potenciometro  = 0; // Conectar el potenciometro en el pin analogo 0
                        // Ademas se indica que el pin 0 se llamara "Potenciometro"
                                              
int led = 13;           // Conectar el LED en el pin 13
                        // Aqui al igual que el potenciometro decimos que el pin 13 se llame "led"

void setup() 
{
  pinMode(led, OUTPUT);
}

void loop() 
{
  int ValorPotenciometro;
  ValorPotenciometro = analogRead(Potenciometro); //Declaración de la vari  

  digitalWrite(led, HIGH);     // Turno del LED encendido
  delay(ValorPotenciometro);   //Pausar segun potenciometro
  
  digitalWrite(led, LOW);      // Turno del LED apagado
  delay(ValorPotenciometro);   //Pausar segun potenciometro
}

