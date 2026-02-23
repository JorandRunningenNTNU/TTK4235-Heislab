#define test
#ifdef test
#include "testfiler/testStartUp.h"
#endif

#ifndef test
#include "startUp.h"
#endif

MotorDirection direction = DIRN_DOWN;
int Cfloor = -1;

int startUpUpdate(){
    Cfloor = elevio_floorSensor();
    if (Cfloor != -1){
        direction = DIRN_STOP;
        return 1;
    }
    return 0;
}

MotorDirection startUpDirection(){
    return direction;
}