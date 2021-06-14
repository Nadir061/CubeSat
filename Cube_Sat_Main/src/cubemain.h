#include ".\include\writeOnCard.h"
#include ".\include\Cube_Sat_LoRa.h"
#include ".\include\Cube_Sat_BN880.h"
#include ".\include\Cube_Sat_ACS712.h"
#include ".\include\CubeSat_DS18B20.h"
#include ".\include\Cube_Sat_GY86.h"

struct dataLoRa{
    struct tempData temps;
    struct currentData currents;
    struct gpsData GPS;
};
struct dataSD{
    struct dataLoRa dataL;
    double voltage_solar;
};


void getInt();
double getSolarVoltage();