/*
  CIRCUITO 06 - Resistencias sensibles a la luz.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -5 cable de prototipados
  -1 fotoresistencias de 1K Ohms
  -1 resistencia de 330 Ohms
  -1 LED
 */
//Pines usados para el sensor de luz y el LED
const int pinSensor = 0;
const int pinLed    = 9;

//Variables usadas para llevar control de la intensidad de luz
//y los valores maximo y minimo de luz registrados. Notese que
//el maximo se inicializa a 0 para permitir que incremente y el
//minimo a 1023 para permitir que decremente.
int nivelLuz, maximo = 0, minimo = 1023;

void setup() {
  //Se inicializa el pin del LED como salida
  pinMode(pinLed, OUTPUT);
}

void loop() {
  //Primero se lee el nivel de luz del sensor
  nivelLuz = analogRead(pinSensor);

  //Aca se realiza el ajuste del nivel de luz. Descomente solo
  //una de las funciones para ver su efecto.
  ajusteManual();
  //ajusteAutomatico();

  //Una vez ajustado el nivel de luz, se envia al LED ese nivel
  //mediante PWM
  analogWrite(pinLed, nivelLuz);
}

void ajusteManual() {
  //La funcion map permite convertir un rango numerico de
  //entrada en forma proporcional a un rango numerico de salida.
  //En el ajuste manual simplemente se cambia el rango de
  //entrada del sensor (0 a 1023) al rango de salida del PWM
  //(0 a 255). Intente ajustar el rango de entrada para mejorar
  //la sensibilidad.
  nivelLuz = map(nivelLuz, 0, 1023, 0, 255);

  //Una vez ajustado el rango numerico se usa la funcion
  //constrain para recortar posibles valores que excedan el
  //rango numerico de salida (la funcion map no hace recorte).
  //Si el rango de salida no se recorta el PWM puede comportarse
  //de forma erratica.
  nivelLuz = constrain(nivelLuz, 0, 255);
}

void ajusteAutomatico() {
  //Primeramente se actualiza el registro de los valores maximo
  //y minimo de luz observados. Notese que si un if solo
  //controla la ejecucion de una instruccion se pueden omitir
  //las llaves

  //Si el nivel es menor al minimo, este es el nuevo minimo
  if (nivelLuz < minimo)
    minimo = nivelLuz;

  //Si el nivel es mayor al maximo, este es el nuevo maximo
  if (nivelLuz > maximo)
    maximo = nivelLuz;

  //Con los niveles actualizados, se hace un mapeo de este rango
  //al rango de salida del PWM (se deja un margen de 30 unidades
  //para minimizar el efecto del ruido)
  nivelLuz = map(nivelLuz, minimo + 30, maximo - 30, 0, 255);

  //Finalmente se hace un recorte
  nivelLuz = constrain(nivelLuz, 0, 255);
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
