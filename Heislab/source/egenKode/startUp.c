#define test
#ifdef test
#include "testfiler/testStartUp.h"
#endif

#ifndef test
#include "startUp.h"
#endif

MotorDirection direction = DIRN_DOWN;
int floor = -1;

int startUpUpdate(){
    floor = elevio_floorSensor();
    if (floor != -1){
        direction = DIRN_STOP;
        return 1;
    }
    return 0;
}

MotorDirection startUpDirection(){
    return direction;
}