const int button1Pin = 3; 
//const int button2Pin = 3;  
const int ledPin =  13;    

void setup()
{
  pinMode(button1Pin, INPUT);
//  pinMode(button2Pin, INPUT);

  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  int button1State; 
  
  button1State = digitalRead (button1Pin);

  if ( button1State == LOW )
  {
    digitalWrite(ledPin, HIGH);  
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
//  button2State = digitalRead(button2Pin);
 
/*  if (((button1State == LOW) || (button2State == LOW))
      && !                                               
      ((button1State == LOW) && (button2State == LOW))) 
                                                        
  {
    digitalWrite(ledPin, HIGH);  
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }*/
}

void EncenderLED()
{
  digitalWrite(ledPin, HIGH);
}

