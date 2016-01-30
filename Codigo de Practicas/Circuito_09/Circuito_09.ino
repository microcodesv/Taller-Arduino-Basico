#include <Servo.h>

//Instancia de clase usada para controlar el servo
Servo servo1;
//Pin conectado al sensor flexible
const int pinFlex = 0;

void setup()  {
  //Se inicializan el puerto serie y el servo
  Serial.begin(9600);
  servo1.attach(9);
}


void loop()
{
  int posicionFlex;
  int posicionServo;

  //Primero se lee la posicion del flex (rango de 0 a 1023)
  posicionFlex = analogRead(pinFlex);

  //Se usa la funcion map para ajustar la escala del sensor
  //flexible (el cual tipicamente anda entre 600 y 900) al rango
  //de angulos del servo (0 a 180 grados, menos margen de 20
  //grados)
  posicionServo = map(posicionFlex, 600, 900, 20, 160);

  //Luego se emplea la funcion constrain para asegurarse que el
  //servo no se salga del margen permitido
  posicionServo = constrain(posicionServo, 20, 160);

  //Una vez determinada la posicion del servo, se escribe
  servo1.write(posicionServo);

  //Ahora se envia la lectura del sensor y la posicion del servo
  //por el puerto serie
  Serial.print("sensor: ");
  Serial.print(posicionFlex);
  Serial.print("  servo: ");
  Serial.println(posicionServo);

  //Finalmente se hace un breve retardo antes de repetir
  delay(20);
}
