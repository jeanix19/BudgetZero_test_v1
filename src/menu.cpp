//config

int menuLenght = 5;


#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 4
#define SCL_PIN 5

int rotation = 0; //0 = no ritation, -1 = left rotation, 1 = right rotation. Value will be reset to 0 after use
int menuPos = 1;


LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastState = digitalRead(9);
int currentState;

void setupMenu()
{
    lcd.init();
    lcd.backlight();

    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    
}

void checkRotation()
{
    currentState = digitalRead(9);
    if(currentState != lastState)
    {
        if(digitalRead(10))
        {
            rotation = 1; //right
        }
        else
        {
            rotation = -1; //left
        }
    }
    
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
    lcd.print(menuPos);
}