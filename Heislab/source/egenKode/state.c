#include "state.h"
#include "input.h"
#include "output.h"


static int checkIsOnFloor();

static int isOnFloor = 1;
static int PrewFloor;
static float Pos;
static int doorOpen;

void stateUpdate(){
    doorOpen = outputDoorOpen();
    
    int CurrentFloor = inputFloorSensor();

    if (CurrentFloor != -1){ 
        // sensoren har 0 som første etasje, mens resten av systemet har 1 som førsteetaje
        PrewFloor = CurrentFloor+1;
        Pos = CurrentFloor+1;
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

static int checkIsOnFloor(){
    if (inputFloorSensor() == -1){return 0;}
    else if (inputFloorSensor() != -1){return 1;}
    return 0;
}