/*
  CIRCUITO 07 - Sensor de temperatura y humedad.
  Para armar este circuito necesitaras:
  -1 Tarjeta Arduino
  -1 Breadboard
  -1 cable USB
  -5 cable de prototipados
  -1 sensor de temperatura DHT22
  -1 resistencia de 1KOhms
*/
//cargamos la librería DHT
#include <DHT.h>
//Seleccionamos el pin en el que se conectará el sensor
#define  DHTPIN 2
//Se selecciona el DHT22(existen otros DHT)
#define  DHTTYPE DHT22
//Se inicia una variable que será usada por
//Arduino para comunicarse con el sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //El puerto serie permite intercambiar informacion con la
  //computadora mediante el puerto USB. Para usarlo se debe
  //acceder al objeto "Serial" a traves de sus metodos.
  //Este puerto debe ser inicializado al comenzar el programa,
  //para ello se usa el metodo begin y se indica la velocidad
  //de comunicacion.
  Serial.begin(9600);
  dht.begin(); //Es necesario inicializar el sensor DHT
}

void loop() {
  float h = dht.readHumidity(); //Se lee la humedad
  float t = dht.readTemperature(); //Se lee la temperatura
  //Se imprimen las variables
  Serial.println("Humedad: ");
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay(2000); //Se espera 2 segundos para seguir leyendo datos
}
/*
   Código realizado por Joksan Alvarado en colaboración con
   Karla Hernandez para el proyecto de educación en tecnologias
   Microcode impartido desde el LabCT, en El Salvador.

   Este material se encuentra bajo licencia Creative Commons 4.0
   CC-BY-SA y GNU General public license 3.0
*/
