/*
  CIRCUITO 04 - Arreglo de ledes.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -10 cable de prototipados
  -8 LED
  -8 resistencia de 330 Ohms
*/
//Los arreglos permiten guardar simultaneamente varios datos a
//la vez bajo un solo nombre de variable. En este caso se
//guardan todos los numeros de los pines conectados a los LEDs.
int pinLed[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

void setup() {
  //Una tecnica muy comun usada en los lazos for consiste en
  //usar la variable local de nombre "i" que significa "indice"
  //o "iterador", ya que se usa para ir contando en el lazo.
  int i;

  //El lazo for permite repetir el mismo codigo en muchas
  //ocasiones sin tener que repetir las lineas. Aca se
  //inicializan todos los pines del arreglo como salidas,
  //usando una unica instruccion que se repite para cada pin.
  for (i = 0; i <= 7; i++) {
    pinMode(pinLed[i], OUTPUT);
  }
}

void loop()
{
  //Un truco muy util para desactivar lineas de codigo sin
  //tener que borralas es comentarlas. Asi el compilador las
  //ignora y podemos conservarlas como referencia.

  //Las siguientes llamadas de funcion permiten generar
  //animaciones distintas. Descomente una funcion a la vez
  //para ver su efecto.

  unoTrasOtroSinLazo();
  //unoTrasOtroConLazo();
  //unoEncendidoCadaVez();
  //pingPong();
  //marquesina();
  //ledAlAzar();
}

void unoTrasOtroSinLazo() {
  //Tiempo de espera entre LEDs
  const int tiempoRetardo = 1000;

  //Se encendien los LEDs de uno en uno, dejandolos encendidos.
  digitalWrite(pinLed[0], HIGH);  //Enciende LED #0 (pin 2)
  delay(tiempoRetardo);
  digitalWrite(pinLed[1], HIGH);  //Enciende LED #1 (pin 3)
  delay(tiempoRetardo);
  digitalWrite(pinLed[2], HIGH);  //Enciende LED #2 (pin 4)
  delay(tiempoRetardo);
  digitalWrite(pinLed[3], HIGH);  //Enciende LED #3 (pin 5)
  delay(tiempoRetardo);
  digitalWrite(pinLed[4], HIGH);  //Enciende LED #4 (pin 6)
  delay(tiempoRetardo);
  digitalWrite(pinLed[5], HIGH);  //Enciende LED #5 (pin 7)
  delay(tiempoRetardo);
  digitalWrite(pinLed[6], HIGH);  //Enciende LED #6 (pin 8)
  delay(tiempoRetardo);
  digitalWrite(pinLed[7], HIGH);  //Enciende LED #7 (pin 9)
  delay(tiempoRetardo);

  //Ahora se van apagando los LEDs de uno en uno, en orden
  //inverso.
  digitalWrite(pinLed[7], LOW);   //Apaga LED #7 (pin 9)
  delay(tiempoRetardo);
  digitalWrite(pinLed[6], LOW);   //Apaga LED #6 (pin 8)
  delay(tiempoRetardo);
  digitalWrite(pinLed[5], LOW);   //Apaga LED #5 (pin 7)
  delay(tiempoRetardo);
  digitalWrite(pinLed[4], LOW);   //Apaga LED #4 (pin 6)
  delay(tiempoRetardo);
  digitalWrite(pinLed[3], LOW);   //Apaga LED #3 (pin 5)
  delay(tiempoRetardo);
  digitalWrite(pinLed[2], LOW);   //Apaga LED #2 (pin 4)
  delay(tiempoRetardo);
  digitalWrite(pinLed[1], LOW);   //Apaga LED #1 (pin 3)
  delay(tiempoRetardo);
  digitalWrite(pinLed[0], LOW);   //Apaga LED #0 (pin 2)
  delay(tiempoRetardo);
}

void unoTrasOtroConLazo() {
  //Esta funcion hace exactamente lo mismo que la anterior,
  //pero emplea lazos for para reducir el codigo
  //considerablemente
  int i;
  const int tiempoRetardo = 100;

  //Aca se encienden los LEDs uno a uno, dejandolos encendidos
  for (i = 0; i <= 7; i++) {
    digitalWrite(pinLed[i], HIGH);
    delay(tiempoRetardo);
  }

  //Luego se apagan los LEDs en orden inverso. Para invertir
  //el orden se cuenta hacia atras en el lazo.
  for (i = 7; i >= 0; i--) {
    digitalWrite(pinLed[i], LOW);
    delay(tiempoRetardo);
  }
}

void unoEncendidoCadaVez() {
  int i;
  const int tiempoRetardo = 100;

  //Se encienden los LED en orden ascendente de uno en uno.
  //Para conseguir que se mire solo uno encendido a la vez se
  //coloca un retardo despues de encender cada LED pero no tras
  //apagarlo. Como no existe retardo tras apagar cada LED el
  //lazo for se repite de inmediato y enciende el siguiente LED
  //instantaneamete
  for (i = 0; i <= 7; i++) {
    digitalWrite(pinLed[i], HIGH);
    delay(tiempoRetardo);
    digitalWrite(pinLed[i], LOW);
  }
}

void pingPong() {
  int i;
  const int tiempoRetardo = 100;

  //Se encienden los LEDs en orden ascendente de forma identica
  //a la animacion anterior.
  for (i = 0; i <= 7; i++) {
    digitalWrite(pinLed[i], HIGH);
    delay(tiempoRetardo);
    digitalWrite(pinLed[i], LOW);
  }

  //A continuacion se apagan los LEDs en forma descendente,
  //siempre de uno en uno.
  for (i = 7; i >= 0; i--) {
    digitalWrite(pinLed[i], HIGH);
    delay(tiempoRetardo);
    digitalWrite(pinLed[i], LOW);
  }
}

void marquesina() {
  int i;
  const int tiempoRetardo = 200;

  //En esta ocasion se encienden los LEDs en forma ascendente
  //y de dos en dos. Como se duplica la cantidad de LEDs
  //actualizados solo se itera la mitad de las ocasiones
  for (i = 0; i <= 3; i++) {
    //Enciende el LED en la posicion i
    digitalWrite(pinLed[i], HIGH);
    //Enciende el LED 4 posiciones adelante de i
    digitalWrite(pinLed[i + 4], HIGH);

    delay(tiempoRetardo);

    //Apaga los mismos 2 LEDs que se encendieron
    digitalWrite(pinLed[i], LOW);
    digitalWrite(pinLed[i + 4], LOW);
  }
}

void ledAlAzar() {
  int numeroLed;
  int tiempoRetardo;

  //Se genera un numero al azar entre 0 y 7 para decidir cual
  //LED encender
  numeroLed = random(8);

  tiempoRetardo = 100;

  //Se enciende el LED al azar por un momento, luego se apaga
  digitalWrite(pinLed[numeroLed], HIGH);
  delay(tiempoRetardo);
  digitalWrite(pinLed[numeroLed], LOW);
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
