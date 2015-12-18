int Potenciometro  = 0; // Conectar el potenciometro en el pin analogo 0
                        // Ademas se indica que el pin 0 se llamara "Potenciometro"
                                              
int LED = 13;           // Conectar el LED en el pin 13
                        // Aqui al igual que el potenciometro decimos que el pin 13 se llame "LED"

void setup() 
{
  pinMode(LED, OUTPUT);
}

void loop() 
{
  int ValorPotenciometro;
  ValorPotenciometro = analogRead(Potenciometro); //Declaración de la variable  
  
  digitalWrite(LED, HIGH);     //Turno del LED encendido
  delay(ValorPotenciometro);   //Pausar segun potenciometro
  
  digitalWrite(LED, LOW);      // Turno del LED apagado
  delay(ValorPotenciometro);   //Pausar segun potenciometro
}

