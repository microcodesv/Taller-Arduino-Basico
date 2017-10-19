/*
  CIRCUITO 02 - Implementando resistencias variables.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -6 cable de prototipados
  -1 LED
  -1 resistencia de 330 Ohms
  -1 Potenciometro de 1K Ohms
*/
//En la variable llamada "Potenciometro" se guarda el numero de pin
//donde se conecta el potenciometro, asi no hay que recordar el numero
//asignado y en caso de cambiarlo se cambia en un solo lugar
int Potenciometro  = 0; //El potenciometro va al pin analogo 0

//Usamos la misma tecnica para guardar el numero de pin donde va el LED
int LED = 13; //Se conecta el LED en el pin 13

void setup() {
  pinMode(LED, OUTPUT); //El pin del LED es una salida
  //NOTA: Los pines analogicos no se inicializan.
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
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
