#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //(RS, Enable, D4, D5, D6, D7)

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  //contador();
  //scrollDerecho();
  scrollIzquierdo();
  //Autoscroll();
}

void contador()
{
  lcd.setCursor(0, 0);
  lcd.print("Contador Aqui");

  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}

void scrollDerecho()
{
  lcd.setCursor(0, 0);
  lcd.print("Muevete -->");

  for (int positionCounter = 0; positionCounter < 10; positionCounter++)
  {
    lcd.scrollDisplayRight();
    delay(150);
  }
}

void scrollIzquierdo()
{
  lcd.setCursor(0, 0);
  lcd.print("<-- Muevete");

  lcd.setCursor(7, 1);
  lcd.print("Yo te sigo");

  for (int positionCounter = 0; positionCounter < 10; positionCounter++)
  {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

void Autoscroll()
{
  lcd.setCursor(0, 0);

  for (int caracter = 0; caracter < 10; caracter++) {
    lcd.print(caracter);
    delay(500);
  }

  lcd.setCursor(16, 1);
  lcd.autoscroll();

  for (int caracter = 0; caracter < 10; caracter++) {
    lcd.print(caracter);
    delay(500);
  }

  lcd.noAutoscroll();
  lcd.clear();
}



