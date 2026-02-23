#include "state.h"
#include "input.h"
#include "output.h"


int checkIsOnFloor();

int isOnFloor = 1;
int PrewFloor;
float Pos;
int doorOpen;

void stateUpdate(){
    int doorOpen = outputDoorOpen();
    
    int CurrentFloor = inputFloorSensor();

    if (CurrentFloor != -1){ 
        PrewFloor = CurrentFloor;
        Pos = CurrentFloor;
    }
    if (CurrentFloor == -1){
        MotorDirection CurrentDirection = stateDirection();
        if ((CurrentDirection == DIRN_UP) && (isOnFloor)){
            Pos = PrewFloor + 0.5;    //Viser at heisen er over Etasje x
        }
        else if ((CurrentDirection == DIRN_DOWN) && (isOnFloor)){
           Pos = PrewFloor -0.5;   //Viser at heisen er under Etasje x 
        }
    }

    isOnFloor = checkIsOnFloor();    

}

int statePrewFloor(){
    return PrewFloor;
}

float statePosition(){
    return Pos;
}

MotorDirection stateDirection(){
    return outputDirection();
}

int stateDoorOpen(){
    return doorOpen;
}

int checkIsOnFloor(){
    if (inputFloorSensor() == -1){return 0;}
    else if (inputFloorSensor() != -1){return 1;}
    return 0;
}