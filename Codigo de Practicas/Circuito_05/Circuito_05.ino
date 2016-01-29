//Pines del LED RGB
const int pinRojo = 9;
const int pinVerde = 10;
const int pinAzul = 11;

void setup() {
  //Todos los pines del LED RGB se colocan como salidas
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  //Pueden comentarse y descomentarse las siguientes funciones
  //para ver lo que hacen:
  menuColores();
  //espectroCompleto();
}

//La siguiente funcion muestra colores de uno en uno
void menuColores() {

  //Apagado (Apagar todos los LEDS):
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
  delay(1000);

  //Rojo (Ajuste de leds para visualizar solo el rojo):
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
  delay(1000);

  //Verde (Ajuste de leds para visualizar solo el verde):
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);
  delay(1000);

  //Azul (Ajuste de leds para visualizar solo el azul):
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, HIGH);
  delay(1000);

  //Amarillo (Para lograr visualizar amarillo combinamos rojo y verde):
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);
  delay(1000);

  //Cyan (Para lograr visualizar cyan combinamos Verde y Azul):
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, HIGH);
  delay(1000);

  //Morado (Para lograr visualizar morado combinamos Rojo y Azul):
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, HIGH);
  delay(1000);

  //Blanco (Para lograr visualizar blanco combinamos rojo, azul y verde):
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, HIGH);
  delay(1000);
}

void espectroCompleto() {
  //Esta variable es usada para llevar la cuenta de
  //iteraciones (repeticiones del lazo)
  int x;

  //El siguiente lazo muestra todos los colores del arcoiris
  //en el LED RGB
  for (x = 0; x < 768; x++) {
    verRGB(x);
    delay(10);
  }
}

void verRGB (int color) {
  //Las siguientes variables sirven para guardar los valores
  //calculados de cada componente de color
  int IntesidadRojo;
  int IntesidadVerde;
  int IntesidadaAzul;

  //Los siguientes if calculan las componentes de color
  //dependiendo de la zona donde se encuentra el color buscado.
  if (color <= 255) {
    //Zona 1
    IntesidadRojo = 255 - color;          //Rojo disminuye
    IntesidadVerde = color;               //Verde aumenta
    IntesidadaAzul = 0;                   //Azul se mantiene
  }
  else if (color <= 511) {
    //Zona 2
    IntesidadRojo = 0;                    //Rojo se mantiene
    IntesidadVerde = 255 - (color - 256); //Verde disminuye
    IntesidadaAzul = (color - 256);       //Azul aumenta
  }
  else { //(color >= 512)
    //Zona 3
    IntesidadRojo = (color - 512);        //Rojo aumenta
    IntesidadVerde = 0;                   //Verde se mantiene
    IntesidadaAzul = 255 - (color - 512); //Azul disminuye
  }

  //Una vez calculadas las componentes de color, se usa PWM
  //para visualizarlas en el LED RGB
  analogWrite(pinRojo, IntesidadRojo);
  analogWrite(pinAzul, IntesidadaAzul);
  analogWrite(pinVerde, IntesidadVerde);
}
