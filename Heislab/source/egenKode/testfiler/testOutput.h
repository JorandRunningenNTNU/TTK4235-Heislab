#include <stdio.h>
#include "testData.h"

void outputUpdate();

int main(){
    outputUpdate();
}

// inn-data
MotorDirection testDirection = DIRN_DOWN;
float testPosition = 1;
int testDoor = 0;
UpButtons testUpButtons = {0, 0, -1};
DownButtons testDownButtons = {0, -1, 0};
ElevatorButtons testElevatorButtons = {-1, 0, 0, 0};
int testStop = 1;


// inn-funksjoner
MotorDirection startUpDirection(){
    return testDirection;
}

float statePosition(){
    return testPosition;
}

MotorDirection controlDirection(){
    return testDirection;
}

int controlDoor(){
    return testDoor;
}

UpButtons controlUpButtons(){
    return testUpButtons;
}

DownButtons controlDownButtons(){
    return testDownButtons;
}

ElevatorButtons controlElevatorButtons(){
    return testElevatorButtons;
}

int controlStopp(){
    return testStop;
}



// out-funksjoner
void elevio_doorOpenLamp(int doorOpen){
    printf("åpne dør %d \n", doorOpen);
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
