#include "startUp.h"

static MotorDirection direction = DIRN_DOWN;
static int floor = -1;

#define test
#ifndef test
int startUpUpdate(){
    floor = elevio_floorSensor();
    if (floor != -1){
        direction = DIRN_STOP;
        return 1;
    }
    return 0;
}
#endif

#ifdef test
#include <stdio.h>
int startUpUpdate(){
    FILE* fptr;
    char input[100];
    fptr = fopen("source/egenKode/testfiler/testInputData.txt", "r");
    
    fgets(input, 100, fptr);
    fgets(input, 100, fptr);
    floor = (int)input[0] -48;
    fclose(fptr); 
    
    if (floor != -1){
        direction = DIRN_STOP;
        return 1;
    }
    return 0;
}
#endif

MotorDirection startUpDirection(){
    return direction;
}