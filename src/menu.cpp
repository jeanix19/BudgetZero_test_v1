//config

int menuLenght = 5;


#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 4
#define SCL_PIN 5

int rotation = 0; //0 = no ritation, -1 = left rotation, 1 = right rotation. Value will be reset to 0 after use
int menuPos = 1;



void setupMenu()
{
    LiquidCrystal_I2C lcd(0x27,  16, 2);
    Wire.begin(SDA_PIN, SCL_PIN);

    lcd.init();
    lcd.backlight();

    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
}

void checkRotation()
{
    
}

void updateMenu()
{
    menuPos += rotation;
    rotation = 0;

    if(menuPos < 1)
    {
        menuPos = menuLenght;
    }
    else if(menuPos > menuLenght)
    {
        menuPos = 1;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1. something");
}