//En la variable llamada "Potenciometro" se guarda el numero de pin
//donde se conecta el potenciometro, asi no hay que recordar el numero
//asignado y en caso de cambiarlo se cambia en un solo lugar
int Potenciometro  = 0; //El potenciometro va al pin analogo 0

//Usamos la misma tecnica para guardar el numero de pin donde va el LED
int LED = 13; //Se conecta el LED en el pin 13

void setup() {
  pinMode(LED, OUTPUT); //El pin del LED es una salida
  //NOTA: Los pines analogicos no se inicializan
}

void loop() {
  //Esta otra variable guarda el valor leido del potenciometro
  int ValorPotenciometro;

  //Se lee el valor del potenciometro desde el pin analogico. El dato
  //solo puede estar entre 0 y 1023
  ValorPotenciometro = analogRead(Potenciometro);

  digitalWrite(LED, HIGH);     //Enciende el LED
  delay(ValorPotenciometro);   //Pausa segun potenciometro

  digitalWrite(LED, LOW);      //Apaga el LED
  delay(ValorPotenciometro);   //Pausa segun potenciometro
}
