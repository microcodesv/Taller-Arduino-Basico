#include <Servo.h>

//Las librerias como Servo.h funcionan a traves de clases, de
//manera muy similar al puerto Serie. Para trabajar con ellas se
//deben crear objetos de las clases que exponen. Luego estos
//objetos se usan a traves de sus metodos.

//En este caso, el nombre "servo1" se usa como nombre de objeto
//para nuestro programa. Si se conectan multiples servos, se
//pueden crear mas objetos de esta clase con diferentes nombres.
Servo servo1;

void setup() {
  //Para inicializar un servo se indica el numero de pin al que
  //esta conectado con el metodo "attach"
  servo1.attach(9);

  //Inicializa la terminal serie
  Serial.begin(9600);
}

void loop() {
  //Descomente cada una de las rutinas para probarlas
  //movimientoDirecto();
  //movimientoContinuo();
  //controlSerie();
  anguloSerie();
}

void movimientoDirecto() {
  //Para establecer la posicion del servo basta con enviar el
  //angulo al que se debe posicionar mediante el metodo write.
  //El servo toma cierta cantidad de tiempo para girar, por lo
  //que se hace un retardo para esperarlo.
  servo1.write(90);   //Posicion de 90 grados
  delay(1000);

  servo1.write(160);  //Posicion de 160 grados
  delay(1000);

  servo1.write(20);   //Posicion de 20 grados
  delay(1000);

  //Nota: El rango de movimiento de muchos servos va de 0 a 180
  //grados, sin embargo algunos servos tienen menos rango, por
  //lo que se dejan 20 grados como margen de seguridad.
}

void movimientoContinuo() {
  int posicion;

  //Para mover lentamente el motor se puede hacer un lazo for,
  //el cual incrementa el angulo poco a poco y va intercalando
  //pausas.
  for (posicion = 20; posicion < 160; posicion += 2) {
    servo1.write(posicion);
    delay(20);
  }

  //Aca se mueve el motor todavia mas lentamente, pero de
  //regreso.
  for (posicion = 160; posicion >= 20; posicion -- ) {
    servo1.write(posicion);
    delay(20);
  }
}

void controlSerie() {
  char dato;

  //Se envian las indicaciones al usuario
  Serial.println("Seleccione una opcion");
  Serial.println("1- Posicion A");
  Serial.println("2- Posicion B");
  Serial.println("3- Posicion C");

  //La siguiente rutina se repite indefinidamente
  for (;;) {
    //Espera a que ingrese un dato por el puerto serie
    while (!Serial.available());

    //Cuando llega un dato, se lee en la variable
    dato = Serial.read();

    //Se decide que hacer en caso se reciba un caracter especifico
    switch (dato) {
      case '1':
        servo1.write(20);  //La posicion A es 20 grados
        break;
      case '2':
        servo1.write(90);  //La posicion B es 90 grados
        break;
      case '3':
        servo1.write(160); //La posicion C es 160 grados
        break;
    }
  }
}

void anguloSerie() {
  int angulo;

  //Se imprimen las indicaciones
  Serial.println("Escriba la posicion del servo en grados");

  for (;;) {
    //Espera a que ingrese un numero por el puerto serie
    while (!Serial.available());

    //Lee el siguiente numero entero del puerto serie
    angulo = Serial.parseInt();

    //Recorta el angulo en caso se salga de los valores limites
    angulo = constrain(angulo, 20, 160);

    //Confirma el angulo ingresado al usuario
    Serial.print("angulo: ");
    Serial.print(angulo);
    Serial.println(" grados");

    //Finalmente establece la posicion del servo
    servo1.write(angulo);
  }
}
