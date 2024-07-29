#include <Arduino.h>
#line 1 "C:\\Users\\PC-P005\\Documents\\Arduino\\Collabs\\Develop\\SPP\\SPP.ino"
int menu, a, b, c, d, e, f = 0;

#line 3 "C:\\Users\\PC-P005\\Documents\\Arduino\\Collabs\\Develop\\SPP\\SPP.ino"
void setup();
#line 18 "C:\\Users\\PC-P005\\Documents\\Arduino\\Collabs\\Develop\\SPP\\SPP.ino"
void loop();
#line 31 "C:\\Users\\PC-P005\\Documents\\Arduino\\Collabs\\Develop\\SPP\\SPP.ino"
void pneumatic();
#line 3 "C:\\Users\\PC-P005\\Documents\\Arduino\\Collabs\\Develop\\SPP\\SPP.ino"
void setup()
{
    for (int bootInput = 2; bootInput <= 3; bootInput++)
    {
        pinMode(bootInput, INPUT_PULLUP);
    }
    for (int bootOutput = 4; bootOutput <= 9; bootOutput++)
    {
        pinMode(bootOutput, OUTPUT);
        digitalWrite(bootOutput, LOW);
        delay(500);
        digitalWrite(bootOutput, HIGH);
        delay(1000);
    }
}
void loop()
{
    if (digitalRead(2) == HIGH)
    {
        menu++;
        if (menu > 4)
        {
            menu = 0;
        }
    pneumatic();
    }
}

void pneumatic()
{
    switch (menu)
    {
    case 0:
        for (int i = 4; i <= 9; i++)
        {
            digitalWrite(i, HIGH);
            delay(50);
        }
        break;
    case 1:
        digitalWrite(4, LOW);
        delay(3000);
        digitalWrite(5, LOW);
        delay(5000);
        if(digitalRead(3)==HIGH){
            menu++;
            pneumatic();
        }
        break;
    case 2:
        digitalWrite(4, HIGH);
        delay(3000);
        digitalWrite(5, HIGH);
        break;
    case 3:
        menu = 0;
        break;
    case 4:
        break;
    }
}
