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
