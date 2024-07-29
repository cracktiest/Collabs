# 1 "C:\\Users\\PC-P005\\Documents\\Arduino\\Collabs\\Develop\\SPP\\SPP.ino"
int menu, a, b, c, d, e, f = 0;

void setup()
{
    for (int bootInput = 2; bootInput <= 3; bootInput++)
    {
        pinMode(bootInput, 0x2);
    }
    for (int bootOutput = 4; bootOutput <= 9; bootOutput++)
    {
        pinMode(bootOutput, 0x1);
        digitalWrite(bootOutput, 0x0);
        delay(500);
        digitalWrite(bootOutput, 0x1);
        delay(1000);
    }
}
void loop()
{
    if (digitalRead(2) == 0x1)
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
            digitalWrite(i, 0x1);
            delay(50);
        }
        break;
    case 1:
        digitalWrite(4, 0x0);
        delay(3000);
        digitalWrite(5, 0x0);
        delay(5000);
        if(digitalRead(3)==0x1){
            menu++;
            pneumatic();
        }
        break;
    case 2:
        digitalWrite(4, 0x1);
        delay(3000);
        digitalWrite(5, 0x1);
        break;
    case 3:
        menu = 0;
        break;
    case 4:
        break;
    }
}
