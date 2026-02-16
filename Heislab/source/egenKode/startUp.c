#include "startUp.h"
#include "testfiler/testStartUp.h"

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