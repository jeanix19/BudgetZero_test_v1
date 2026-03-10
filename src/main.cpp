//config





#include <Arduino.h>
#include <menu.h>


#define IR_O = 6
#define IR_I = 7



void setup()
{
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  
  Serial.begin(115200);

  setupMenu();
}

void loop()
{
  
}
