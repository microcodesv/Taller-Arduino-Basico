/*
  CIRCUITO 03 - Compuertas lógicas con botones.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -3 cable de prototipados
  -1 LED
  -2 botones
  -1 resistencia de 330 Ohms
  -2 resistencia de 1k Ohms

  Aca vamos acerca de las compuertas logicas y comparadores por
  medio de la implementación de botones.
*/
//Los siguientes pines se manejan como constantes. La ventaja
//de las constantes es que sus valores no se pueden modificar
//accidentalmente.
const int pinBoton1 = 2;
const int pinBoton2 = 3;
const int pinLed =  13;

void setup() {
  //Los pines de los botones se configuran como entradas
  pinMode(pinBoton1, INPUT);
  pinMode(pinBoton2, INPUT);

  //El pin del LED se configura como salida
  pinMode(pinLed, OUTPUT);
}

void loop() {
  //Estas variables guardan el estado de cada boton
  int estadoBoton1, estadoBoton2;

  //Se lee el estado de cada boton y se guardan en las variables
  estadoBoton1 = digitalRead(pinBoton1);
  estadoBoton2 = digitalRead(pinBoton2);

  //A continuacion se verifican las condiciones necesarias para
  //encender el LED si y solo si se presiona exactamente un
  //boton a la vez. Esto se conoce como operacion OR exclusiva
  //(abreviado XOR).
  //  a xor b = (a or b) and not (a and b)
  //Que significa "presionar el boton a o b, pero no ambos a
  //la vez". Recuerdese que los botones se conectan a tierra,
  //asi que se consideran activos si estan en nivel BAJO.
  if (((estadoBoton1 == LOW) || (estadoBoton2 == LOW))
      && !
      ((estadoBoton1 == LOW) && (estadoBoton2 == LOW)))
  {
    digitalWrite(pinLed, HIGH);  //Enciende el LED
  }
  else {
    digitalWrite(pinLed, LOW);   //Apaga el LED
  }
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA
*/
