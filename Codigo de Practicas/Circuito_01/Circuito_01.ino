/*
  CÓDIGO 01 - Parpadeo de LED.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -1 cable de prototipado
  -1 LED
  -1 resistencia de 330 Ohms
*/

//La funcion setup se ejecuta solo una vez cuando inicia el
//programa. Aca normalmente se colocan las rutinas de
//inicializacion, tales como la configuracion de pines y otros
//perifericos.

void setup() {
  pinMode(13, OUTPUT);      //Se coloca el pin como salida
}

//La funcion loop se ejecuta de forma repetida despues de que
//termina setup. Siempre que esta funcion termina vuelve a
//ejecutarse desde el principio. Aca se coloca la logica
//principal de los programas.
void loop() {
  digitalWrite(13, HIGH);   //Enciende el LED
  delay(1000);              //Espera un segundo

  digitalWrite(13, LOW);    //Apaga el LED
  delay(1000);              //Espera un segundo
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA
*/
