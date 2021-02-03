#include <stdio.h>

#define READ_TEMP 0
#define COOLING 1
#define HEATING 2
#define STANDBY 3

int HVACStatus;

HVACStatus = READ_TEMP;

int main()
{
    switch (HVACStatus)
    {
    case READ_TEMP:
        readTemp();
        break;
    case HEATING:
        heating();
        break;
    case COOLING:
        cooling();
        break;
    case STANDBY:
        standBy();
        break;
    default:
        break;
    }
}

int readTemp()
{
    float temp;

    printf("Set the your desired Temperature: \n");

    scanf("%f", &temp);

    if (temp >= 20)
    {
        cooling();
        return HVACStatus = COOLING;
    }
    else if (temp <= 16)
    {
        heating();
        return HVACStatus = HEATING;
    }
    else
    {
        standBy();
        return HVACStatus = STANDBY;
    }
}

int heating()
{
    printf("SYSTEM STATUS = HEATING");
    return HVACStatus = READ_TEMP;
}

int cooling()
{
    printf("SYSTEM STATUS = COOLING");
    return HVACStatus = READ_TEMP;
}

int standBy()
{
    printf("SYSTEM STATUS = STANDBY");
    return HVACStatus = READ_TEMP;
}
