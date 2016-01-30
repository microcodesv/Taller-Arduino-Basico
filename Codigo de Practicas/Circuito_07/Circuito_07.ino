//El sensor de temperatura se conecta al pin analogo 0
const int pinTemperatura = 0;

void setup() {
  //El puerto serie permite intercambiar informacion con la
  //computadora mediante el puerto USB. Para usarlo se debe
  //acceder al objeto "Serial" a traves de sus metodos.
  //Este puerto debe ser inicializado al comenzar el programa,
  //para ello se usa el metodo begin y se indica la velocidad
  //de comunicacion.
  Serial.begin(9600);
}

void loop() {
  //Las siguientes variables son usadas para leer y calcular
  //la temperatura
  float voltaje, gradosC, gradosF;

  //Primero se lee el voltaje que envia el sensor de
  //temperatura.
  voltaje = leerVoltaje(pinTemperatura);

  //Luego este voltaje se convierte a temperatura en grados
  //celsius aplicando la formula del conversion
  gradosC = (voltaje - 0.5) * 100.0;

  //Despues la temperatura se convierte de Farenheit a Celsius
  gradosF = gradosC * (9.0 / 5.0) + 32.0;

  //Finalmente se envian estos datos por el puerto serie. El
  //metodo "print" envia el mensaje pero no envia el fin de
  //linea, mientras que el metodo "println" si lo envia.
  Serial.print("voltage: ");
  Serial.print(voltaje);
  Serial.print("  deg C: ");
  Serial.print(gradosC);
  Serial.print("  deg F: ");
  Serial.print(gradosF);
  Serial.println(" ");

  //Se espera 1 segundo antes de repetir
  delay(1000);
}

float leerVoltaje(int pin) {
  //Esta funcion convierte la lectura del ADC a voltaje
  //aplicando una regla de 3.
  //  voltaje   lectura
  //  ------- = -------
  //    5V       1023
  //             5V
  //  voltaje = ---- * lectura
  //            1023
  //  voltaje = 0.0048875855 * lectura
  return (analogRead(pin) * 0.0048875855);
}
