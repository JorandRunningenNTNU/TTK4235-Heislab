#include "input.h"

#define test
#ifdef test
#include <stdio.h>
#endif

//va bug her med redefinition av floor igjen....

static int stop = 0;
static int floor = -1;
static int obstruction = 0;
static UpButtons upButtons = {{0, 0, 0}};
static DownButtons downButtons = {{0, 0, 0}};
static ElevatorButtons elevatorButtons = {{0, 0, 0, 0}};

#ifndef test
void inputUpdate(){
    stop = elevio_stopButton();
    floor = elevio_floorSensor();
    obstruction = elevio_obstruction();

    for (int i = 0; i < 4; i++){
        if (i != 3){
            upButtons.buttons[i] = elevio_callButton(i, BUTTON_HALL_UP);
        }

        if (i != 0){
            downButtons.buttons[i-1] = elevio_callButton(i, BUTTON_HALL_DOWN);
        }

        elevatorButtons.buttons[i] = elevio_callButton(i, BUTTON_CAB);
    }
}
#endif

#ifdef test
void inputUpdate(){
    FILE* fptr;
    char in[100];
    fptr = fopen("source/egenKode/testfiler/testInputData.txt", "r");
    
    fgets(in, 100, fptr);
    stop = (int)in[0] -48;

    fgets(in, 100, fptr);
    floor = (int)in[0] -48;

    fgets(in, 100, fptr);
    obstruction = (int)in[0] -48;

    for (int i = 0; i<3; i++){
        fgets(in, 100, fptr);
        upButtons.buttons[i] = (int)in[0] -48;
    }

    for (int i = 0; i<3; i++){
        fgets(in, 100, fptr);
        downButtons.buttons[i] = (int)in[0] -48;
    }

    for (int i = 0; i<4; i++){
        fgets(in, 100, fptr);
        elevatorButtons.buttons[i] = (int)in[0] -48;
    }

    fclose(fptr); 
}
#endif

int inputStopp(){return stop;}

int inputFloorSensor(){return floor;}

int inputObstruction(){return obstruction;}

UpButtons inputUpButtons(){return upButtons;}

DownButtons inputDownButtons(){return downButtons;}

ElevatorButtons inputElevatorButtons(){return elevatorButtons;}
