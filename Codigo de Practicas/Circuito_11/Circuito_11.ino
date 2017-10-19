/*
  CIRCUITO 11 - Pantalla LCD.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -17 cable de prototipados
  -1 pantalla LCD 16x2
  -1 potenciometro 1K Ohms
 */
#include <LiquidCrystal.h>

//La libreria para pantalla LCD tambien opera con clases,
//similar al puerto serie y la libreria de servo. Aca la
//diferencia es que cuando se declara el objeto de la pantalla
//se indican entre parentesis los numeros de pin que se usan
//para conectarla.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Orden de los pines: RS, Enable, D4, D5, D6, D7

void setup() {
  //Para inicializar la pantalla se usa el metodo "begin", al
  //cual se le deben pasar las dimensiones de la pantalla.
  //(En este caso 16 columnas por 2 filas).
  lcd.begin(16, 2);

  //El metodo "clear" limpia cualquier texto que pudiera estar
  //en la pantalla
  lcd.clear();
}

void loop() {
  //En esta ocasion se cuenta con varias funciones para probar
  //la pantalla. Pruebe cada una de ellas descomentando las
  //lineas.

  contador();
  //scrollDerecho();
  //scrollIzquierdo();
  //autoScroll();
}

void contador() {
  //La pantalla siempre escribe a continuacion de la ultima
  //posicion donde se escribio la vez anterior. El metodo
  //"setCursor" permite irse a cualquier posicion. La posicion
  //(0, 0) corresponde a la esquina superior izquierda.
  lcd.setCursor(0, 0);
  //Para enviar texto a la pantalla se usa el metodo "print".
  lcd.print("Contador Aqui");

  //La posicion (0, 1) es la esquina inferior izquierda.
  lcd.setCursor(0, 1);
  //El metodo print tambien puede usarse con valores numericos.
  lcd.print(millis() / 1000);

  //Nota: La funcion "millis" devuelve la cantidad de milesimas
  //de segundo que han pasado desde que el arduino comenzo a
  //correr el programa. Esto es util para llevar la cuenta del
  //tiempo.
}

void scrollDerecho() {
  //Imprime el mensaje arriba a la izquierda.
  lcd.setCursor(0, 0);
  lcd.print("Muevete -->");

  //Tip: Puede declararse la variable de iteracion dentro del
  //parentesis del lazo for, ahorrandose la linea de
  //declaracion al inicio.
  for (int posicion = 0; posicion < 10; posicion++) {
    //El metodo "scrollDisplayRight" mueve todo el texto en la
    //pantalla una posicion hacia la derecha. Con esto se logra
    //el efecto de marquesina.
    lcd.scrollDisplayRight();
    delay(150);
  }
}

void scrollIzquierdo() {
  //Imprime el mensaje en la esquina superior izquierda.
  lcd.setCursor(0, 0);
  lcd.print("<-- Muevete");

  //Imprime el mensaje casi a la mitad de la segunda fila.
  lcd.setCursor(7, 1);
  lcd.print("Yo te sigo");

  //En esta ocasion se usa el metodo "scrollDisplayLeft"
  //para mover el texto hacia la izquierda.
  for (int posicion = 0; posicion < 10; posicion++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

void autoScroll() {
  //Coloca el cursor en la esquina superior izquierda, para que
  //el siguiente texto aparezca ahi
  lcd.setCursor(0, 0);

  //Imprime los numeros del 0 al 9, con pausas entre numero
  //y numero.
  for (int caracter = 0; caracter < 10; caracter++) {
    lcd.print(caracter);
    delay(500);
  }

  //Coloca el cursor en la esquina inferior derecha.
  lcd.setCursor(16, 1);
  //Enciende el auto scroll con el metodo "autoscroll"
  lcd.autoscroll();

  //Nota: El auto scroll (desplazamiento automatico) causa que
  //la pantalla corra todo el texto a la izquierda cada vez que
  //se imprimen caracteres nuevos. Esto es util para crear
  //efectos de marquesina con mensajes largos.

  //A continuacion se vuelve a imprimir los numeros del 0 al 9
  //con pausas, pero como el auto scroll esta encendido movera
  //los digitos anteriores fuera de pantalla.
  for (int caracter = 0; caracter < 10; caracter++) {
    lcd.print(caracter);
    delay(500);
  }

  //Apaga el auto scroll y limpia la pantalla para la siguiente
  //iteracion.
  lcd.noAutoscroll();
  lcd.clear();
}

/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
