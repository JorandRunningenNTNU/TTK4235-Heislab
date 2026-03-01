#include "testOutput.h"
void elevio_doorOpenLamp(int doorOpen){
    printf("apne dor %d \n", doorOpen);
}

void elevio_motorDirection(MotorDirection direction){
    printf("Motorrenting %d \n", direction);
}

void elevio_floorIndicator(int prewFloor){
    printf("Etasjelys %d \n", prewFloor);
}

void elevio_buttonLamp(int floor, ButtonType button, int value){
    printf("knapplys: etasje %d, knapptype %d, verdi %d \n", floor+1, button, value);
}

void elevio_stopLamp(int stop){
    printf("stopp %d \n", stop);
}