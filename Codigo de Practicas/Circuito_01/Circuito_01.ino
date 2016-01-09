void setup() {
  pinMode(13, OUTPUT);      //Se coloca el pin como salida
}

void loop() {
  digitalWrite(13, HIGH);   //Enciende el LED
  delay(1000);              //Espera un segundo

  digitalWrite(13, LOW);    //Apaga el LED
  delay(1000);              //Espera un segundo
}
