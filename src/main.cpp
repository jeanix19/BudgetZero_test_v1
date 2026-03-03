//config

int TouchValue = 40000;



#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <menu.h>

#define SDA_PIN 4
#define SCL_PIN 5
#define IR_O = 6
#define IR_I = 7

LiquidCrystal_I2C lcd(0x27,  16, 2);

int MenuPos = 1;

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);

  Wire.begin(SDA_PIN, SCL_PIN);

  lcd.init();
  lcd.backlight();
  
  Serial.begin(115200);
}

void loop()
{
  if(touchRead(9) > TouchValue)
  {
    if(MenuPos > 1)
    {
      MenuPos -= 1;
      delay(300);
    }
  }
  else if(touchRead(10) > TouchValue)
  {
    if(MenuPos < 5)
    {
      MenuPos += 1;
      delay(300);
    }
  }

  switch (MenuPos)
  {
  case 1:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1. something");
    break;

  case 2:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("2. something");
    break;

  case 3:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("3. something");
    break;

  case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("4. something");
      break;

  case 5:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("5. something");
      break;

  default:
    break;

  }

  Serial.println(MenuPos);
  delay(100);
}
