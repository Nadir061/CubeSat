#include "..\include\Cube_Sat_GY86.h"


MS5x msBar(&Wire);
MPU6050 mpu6050(Wire);

void initMS(int addrMS){
    Wire.begin();
    msBar.setI2Caddr(addrMS);
    while(msBar.connect()>0) {};
}

void initMPU(){
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
}
void initGY86(){
    initMS(ADDR_MS);
    initMPU();
}


dataMS getDataMS(double press_sea){
     dataMS data_ms;
    msBar.checkUpdates();
    if (msBar.isReady())
    {
        data_ms.temp = msBar.GetTemp();
        data_ms.pressure = msBar.GetPres();
        if(data_ms.pressSea == 0){
            data_ms.pressSea = msBar.getSeaLevel(press_sea);
        }
        data_ms.alt = msBar.getAltitude(true);
        return data_ms;
    }
    return data_ms;
}

dataMPU getDataMPU(){
    dataMPU data_mpu;
    mpu6050.update();
    data_mpu.accX = mpu6050.getAccX();
    data_mpu.accY = mpu6050.getAccY();
    data_mpu.accZ = mpu6050.getAccZ();
    data_mpu.gyroX = mpu6050.getGyroX();
    data_mpu.gyroY = mpu6050.getGyroY();
    data_mpu.gyroZ = mpu6050.getGyroZ();
    data_mpu.angleAccX = mpu6050.getAccAngleX();
    data_mpu.angleAccY = mpu6050.getAccAngleY();
    data_mpu.angleGyroX = mpu6050.getGyroAngleX();
    data_mpu.angleGyroY = mpu6050.getGyroAngleY();
    data_mpu.angleGyroZ = mpu6050.getGyroAngleZ();
    data_mpu.angleX = mpu6050.getAngleX();
    data_mpu.angleY = mpu6050.getAngleY();
    data_mpu.angleZ = mpu6050.getAngleZ();

}