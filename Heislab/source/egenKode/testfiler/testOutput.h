#define output
#ifdef output
#include <stdio.h>
#include "testData.h"
/*
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

*/

// out-funksjoner
void elevio_doorOpenLamp(int doorOpen);
void elevio_motorDirection(MotorDirection direction);
void elevio_floorIndicator(int prewFloor);
void elevio_buttonLamp(int floor, ButtonType button, int value);
void elevio_stopLamp(int stop);
#endif