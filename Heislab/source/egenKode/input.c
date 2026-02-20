#include "input.h"

//#define test
#ifdef test
#include "testfiler/testInput.h"
#endif

int stop = 0;
int floor = -1;
int obstruction = 0;
UpButtons upButtons = {0, 0, 0};
DownButtons downButtons = {0, 0, 0};
ElevatorButtons elevatorButtons = {0, 0, 0, 0};

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

int inputStopp(){return stop;}

int inputFloorSensor(){return floor;}

int inputObstruction(){return obstruction;}

UpButtons inputUpButtons(){return upButtons;}

DownButtons inputDownButtons(){return downButtons;}

ElevatorButtons inputElevatorButtons(){return elevatorButtons;}
