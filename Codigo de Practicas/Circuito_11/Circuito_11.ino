#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);

  lcd.begin(16, 2);

  lcd.clear();  
  lcd.print("BIENVENIDOS!");
}

void loop()
{
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000); 
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);

  lcd.setCursor(0,1);
  lcd.print(millis()/1000);

}

