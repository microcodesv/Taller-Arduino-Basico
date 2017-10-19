/*
  CIRCUITO 10 - Resistencia Suave.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -8 cable de prototipados
  -1 sensor suave o tactil
  -1 LED RGB
  -3 resistencias 330 Ohms
 */
//Se definen los pines conectados al led RGB
const int pinLedRojo  = 2;
const int pinLedVerde = 3;
const int pinLedAzul  = 4;

//Tambien se define el pin conectado al potenciometro suave
const int pinSensor = 0;

//En estas variables se guardan los valores de intensidad para
//los colores
int valorRojo, valorVerde, valorAzul;

void setup() {
  //En esta ocasion no se inicializa nada, porque ni el ADC ni
  //el PWM necesitan inicializacion.
}

void loop() {
  int valorSensor;
  valorSensor = analogRead(pinSensor);

  establecerColor(valorSensor);
}

void establecerColor(int posicionRGB) {
  //Estas variables son usadas para los calculos de color
  int mapeoRGB1, mapeoRGB2, recorte1, recorte2;

  //Este mapeo calcula el nivel de rojo para el primer tercio
  //del rango de entrada, el cual va en disminucion desde el
  //maximo (255) al minimo (0).
  mapeoRGB1 = map(posicionRGB, 0, 341, 255, 0);
  //Este recorte se asegura que la salida no exceda el rango
  //del PWM
  recorte1 = constrain(mapeoRGB1, 0, 255);

  //Nota: En el segundo tercio no se hace nada porque el rojo
  //debe estar apagado.

  //El segundo mapeo calcula el rojo en ascenso para el tercer
  //tercio.
  mapeoRGB2 = map(posicionRGB, 682, 1023, 0, 255);
  //Tambien aca se hace recorte
  recorte2 = constrain(mapeoRGB2, 0, 255);

  //El valor de rojo final se obtiene sumando ambos mapeos
  valorRojo = recorte1 + recorte2;

  //El color verde se calcula con el mismo metodo de mapeo y
  //recorte que el rojo, solo que se evita usar las variables
  //intermedias al combinar todas las funciones. Aca el primer
  //tercio es de ascenso, el segundo es de descenso y el tercero
  //es de apagado.
  valorVerde =
      constrain(map(posicionRGB, 0, 341, 0, 255),   0, 255)
    - constrain(map(posicionRGB, 341, 682, 0, 255), 0, 255);

  //En el azul se usa el mismo metodo que el verde. El primer
  //tercio es apagado, el segundo es de ascenso y el tercero
  //es de descenso.
  valorAzul =
      constrain(map(posicionRGB, 341, 682, 0, 255),  0, 255)
    - constrain(map(posicionRGB, 682, 1023, 0, 255), 0, 255);

  //Con los valores de las 3 componentes de color calculadas,
  //se envian las intensidades al led RGB mediante PWM.
  analogWrite(pinLedRojo,  valorRojo);
  analogWrite(pinLedVerde, valorVerde);
  analogWrite(pinLedAzul,  valorAzul);
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
