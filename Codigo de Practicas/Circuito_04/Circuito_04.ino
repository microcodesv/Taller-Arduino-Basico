int ledPins[] = {2,3,4,5,6,7,8,9};

void setup()
{
  int index;
  for(index = 0; index <= 7; index++)
  {
    pinMode(ledPins[index],OUTPUT);
  }
}


void loop()
{
  oneAfterAnotherNoLoop();  
  
  //oneAfterAnotherLoop();  
  
  //oneOnAtATime();       
  
  //pingPong();             

  //marquee();              

  //randomLED();            
}

void oneAfterAnotherNoLoop()
{
  int delayTime = 100; 
  
  // Todos los led encendidos:

  digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (pin 2)
  delay(delayTime);               
  digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (pin 3)
  delay(delayTime);                
  digitalWrite(ledPins[2], HIGH);  //Turns on LED #2 (pin 4)
  delay(delayTime);                
  digitalWrite(ledPins[3], HIGH);  //Turns on LED #3 (pin 5)
  delay(delayTime);                
  digitalWrite(ledPins[4], HIGH);  //Turns on LED #4 (pin 6)
  delay(delayTime);                
  digitalWrite(ledPins[5], HIGH);  //Turns on LED #5 (pin 7)
  delay(delayTime);                
  digitalWrite(ledPins[6], HIGH);  //Turns on LED #6 (pin 8)
  delay(delayTime);                
  digitalWrite(ledPins[7], HIGH);  //Turns on LED #7 (pin 9)
  delay(delayTime);                
 
  //Todos los led apagados:
 
  digitalWrite(ledPins[7], LOW);   //Turn off LED #7 (pin 9)
  delay(delayTime);                
  digitalWrite(ledPins[6], LOW);   //Turn off LED #6 (pin 8)
  delay(delayTime);                
  digitalWrite(ledPins[5], LOW);   //Turn off LED #5 (pin 7)
  delay(delayTime);                
  digitalWrite(ledPins[4], LOW);   //Turn off LED #4 (pin 6)
  delay(delayTime);                
  digitalWrite(ledPins[3], LOW);   //Turn off LED #3 (pin 5)
  delay(delayTime);                
  digitalWrite(ledPins[2], LOW);   //Turn off LED #2 (pin 4)
  delay(delayTime);               
  digitalWrite(ledPins[1], LOW);   //Turn off LED #1 (pin 3)
  delay(delayTime);               
  digitalWrite(ledPins[0], LOW);   //Turn off LED #0 (pin 2)
  delay(delayTime);                
}

void oneAfterAnotherLoop()
{
  int index;
  int delayTime = 100; 
  for(index = 0; index <= 7; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);                
  }                                  

  for(index = 7; index >= 0; index--)
  {
    digitalWrite(ledPins[index], LOW);
    delay(delayTime);
  }               
}

void oneOnAtATime()
{
  int index;
  int delayTime = 100; 
  
  for(index = 0; index <= 7; index++)
  {
    digitalWrite(ledPins[index], HIGH); 
    delay(delayTime);                    
    digitalWrite(ledPins[index], LOW);   
  }
}

void pingPong()
{
  int index;
  int delayTime = 100;
  
  for(index = 0; index <= 7; index++)
  {
    digitalWrite(ledPins[index], HIGH);  
    delay(delayTime);                    
    digitalWrite(ledPins[index], LOW);   
  }
  
  for(index = 7; index >= 0; index--)
  {
    digitalWrite(ledPins[index], HIGH);  
    delay(delayTime);                    
    digitalWrite(ledPins[index], LOW);  
  }
}

void marquee()
{
  int index;
  int delayTime = 200; 
  
  for(index = 0; index <= 3; index++) 
  {
    digitalWrite(ledPins[index], HIGH);    
    digitalWrite(ledPins[index+4], HIGH);  
    delay(delayTime);                      
    digitalWrite(ledPins[index], LOW);     
    digitalWrite(ledPins[index+4], LOW);   
  }
}

void randomLED()
{
  int index;
  int delayTime;
  
  index = random(8);
  delayTime = 100;
	
  digitalWrite(ledPins[index], HIGH);  
  delay(delayTime);                    
  digitalWrite(ledPins[index], LOW);   
}


