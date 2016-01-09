#include <Servo.h>
Servo servo1;

void setup()
{
  servo1.attach(9);
}


void loop()
{
  /*servo1.write(90);
  delay(1000);

  servo1.write(20);
  delay(1000);

  servo1.write(160);
  delay(1000);
*/
  int position;
  //Se mueve el motor de 20 a 160 grados, dejando de margen 20
  //grados para evitar forzar el motor
  for(position = 20; position < 160; position += 2) 
  {
    servo1.write(position);
    delay(20);
  }

  //Se mueve el motor de 160 a 20 grados (de regreso)
  for(position = 160; position >= 20; position -- )
  {
    servo1.write(position);
    delay(20);
  }
}

