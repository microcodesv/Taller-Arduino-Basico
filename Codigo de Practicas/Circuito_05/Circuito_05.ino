/*
  CIRCUITO 05 - Compuertas lógicas con botones.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -15 cable de prototipados
  -1 LED RGB
  -3 resistencia de 330 Ohms
  -3 potenciometros 1k Ohms
*/
//Pines del LED RGB
const int pinRojo  = 9;
const int pinVerde = 10;
const int pinAzul  = 11;

//Pines de los potenciometros
const int potRojo  = A0;
const int potVerde = A1;
const int potAzul  = A2;

void setup() {
  //Todos los pines del LED RGB se colocan como salidas
  pinMode(pinRojo,  OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul,  OUTPUT);
}

void loop() {
  //Pueden comentarse y descomentarse las siguientes funciones
  //para ver lo que hacen:
  secuenciaColores();
  //mezclaRGB();
}

//La siguiente funcion muestra colores de uno en uno
void secuenciaColores() {

  //Apagado (Apagar todos los LEDS):
  digitalWrite(pinRojo,  LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul,  LOW);
  delay(1000);

  //Rojo (Ajuste de leds para visualizar solo el rojo):
  digitalWrite(pinRojo,  HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul,  LOW);
  delay(1000);

  //Verde (Ajuste de leds para visualizar solo el verde):
  digitalWrite(pinRojo,  LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul,  LOW);
  delay(1000);

  //Azul (Ajuste de leds para visualizar solo el azul):
  digitalWrite(pinRojo,  LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul,  HIGH);
  delay(1000);

  //Amarillo (Para lograr visualizar amarillo combinamos rojo y verde):
  digitalWrite(pinRojo,  HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul,  LOW);
  delay(1000);

  //Cyan (Para lograr visualizar cyan combinamos Verde y Azul):
  digitalWrite(pinRojo,  LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul,  HIGH);
  delay(1000);

  //Morado (Para lograr visualizar morado combinamos Rojo y Azul):
  digitalWrite(pinRojo,  HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul,  HIGH);
  delay(1000);

  //Blanco (Para lograr visualizar blanco combinamos rojo, azul y verde):
  digitalWrite(pinRojo,  HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul,  HIGH);
  delay(1000);
}

//Esta funcion permite mezclar el color que uno desee a travez
//de los potenciometros
void mezclaRGB() {
  //Variables con los valores de cada componente de color
  int intensidadRojo;
  int intensidadVerde;
  int intensidadAzul;

  //Se leen las intensidades de las componentes de color desde
  //los canales de ADC. Como el ADC da un rango de 0 - 1023, se
  //divide entre 4 para reducirlo al rango 0 - 255.
  intensidadRojo  = analogRead(potRojo)  / 4;
  intensidadVerde = analogRead(potVerde) / 4;
  intensidadAzul  = analogRead(potAzul)  / 4;

  //Finalmente se usa PWM para visualizar las componentes de
  //color en el LED RGB
  analogWrite(pinRojo,  intensidadRojo);
  analogWrite(pinAzul,  intensidadAzul);
  analogWrite(pinVerde, intensidadVerde);
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
