const int pinRojo = 9;
const int pinVerde = 10;
const int pinAzul = 11;

int verTiempo = 100;  // en milisegundos


void setup()
{
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}


void loop()
{
  //menuColores();
  espectroCompleto();

}

void menuColores()
{
  // Apagado (Apagar todos los LEDS):

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);

  delay(1000);

  // Rojo (Ajuste de leds para visualizar solo el rojo):

  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);

  delay(1000);

  // Verde (Ajuste de leds para visualizar solo el verde):

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);

  delay(1000);

  // Azul (Ajuste de leds para visualizar solo el azul):

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, HIGH);

  delay(1000);

  // Amarillo (Ajuste de leds para visualizar solo el amarillo):

  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);

  delay(1000);

  // Cyan (Para lograr visualizar cyan combinamos Verde y Azul):

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, HIGH);

  delay(1000);

  // Morado (Para lograr visualizar morado combinamos Rojo y Azul):

  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, HIGH);

  delay(1000);

  // Blanco (Para lograr visualizar blanco combinamos rojo, azul y verde):

  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, HIGH);

  delay(1000);
}

void espectroCompleto()
{
  int x; 
  for (x = 0; x < 768; x++) 
  {
    verRGB(x); 
    delay(10); 
  }
}


void verRGB (int color)
{

  int IntesidadRojo;
  int IntesidadVerde;
  int IntesidadaAzul;

  if (color <= 255)          // zona 1
  {
    IntesidadRojo = 255 - color;  
    IntesidadVerde = color;        
    IntesidadaAzul = 0;             
  }
  else if (color <= 511)     // zona 2
  {
    IntesidadRojo = 0;                    
    IntesidadVerde = 255 - (color - 256); 
    IntesidadaAzul = (color - 256);        
  }
  //else  (color >= 512)     // zona 3
  {
    IntesidadRojo = (color - 512);        
    IntesidadVerde = 0;                   
    IntesidadaAzul = 255 - (color - 512);  
  }
  analogWrite(pinRojo, IntesidadRojo);
  analogWrite(pinAzul, IntesidadaAzul);
  analogWrite(pinVerde, IntesidadVerde);
}

