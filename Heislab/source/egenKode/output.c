#include <stdio.h>

//#define test

#ifdef test
#include "testfiler\testOutput.h"
#endif

#ifndef test
#include "output.h"
#include "startUp.h"
#include "control.h"
#include "state.h"
#endif

// lokale funksjoner
void checkBetweenFloors(float position);
void changeDirection(MotorDirection newDirection);
void changeDoor(int newDoorOpen);
void changeButtonLight(UpButtons newUpButtons, 
                       DownButtons newDownButtons,
                       ElevatorButtons newElevatorButtons);
void changeStop(int newStop);

// variabler
MotorDirection direction = DIRN_STOP;
int doorOpen = 1; // 0 er lukket, 1 er åpen, intielt skal døren være åpen se outp.upd.startUp()
int stop = 0; 
int prewFloor = 0;
int betweenFloors = 0;
UpButtons upButtons = {-1, -1, -1};
DownButtons downButtons = {-1, -1, -1};
ElevatorButtons elevatorButtons = {-1, -1, -1, -1};


void outputUpdateStartUp(){
    // sikre at døren er lukket under initialisering
    if (doorOpen){
        doorOpen = 0;
        elevio_doorOpenLamp(doorOpen);
    }
    
    // kjøre heisen så lenge startUp ønsker, ingen sikkerhetstiltak, startUp må ha kontroll
    direction = startUpDirection();
    elevio_motorDirection(direction);
}

void outputUpdate(){
    // oppdatere all informasjon om posisjon og sette etasjelys
    float position = statePosition();
    checkBetweenFloors(position);
    
    if (betweenFloors == 0){
        if (prewFloor != (int) position){
            prewFloor = (int) position;
            elevio_floorIndicator(prewFloor);
        }
    }

    // Dør
    int newDoorOpen = controlDoor();
    changeDoor(newDoorOpen);

    // Sette motorretning
    MotorDirection newDirection = controlDirection();
    changeDirection(newDirection);
    

    // bestillingsknapper
    UpButtons newUpButtons = controlUpButtons();
    DownButtons newDownButtons = controlDownButtons();
    ElevatorButtons newElevatorButtons = controlElevatorButtons();
    changeButtonLight(newUpButtons, newDownButtons, newElevatorButtons);

    //stopp
    int newStop = controlStopp();
    changeStop(newStop);
}

MotorDirection outputDirection(){
    return direction;
}

int outputDoorOpen(){
    return doorOpen;
}

void checkBetweenFloors(float position){
    if ((position - (int)position) > 0.4){
        betweenFloors = 1;
    }
    else {
        betweenFloors = 0;
    }
}

void changeDirection(MotorDirection newDirection){
    int sendChangeToIO = 0; // sender kun forespørsel til IO ved nye rentinger

    // endre motorreting
    if (newDirection != direction){
        // kan alltid starte opp i en hvilken som helst retning, sikre at heisen er innefor område gjøres lengre ned
        if (direction == DIRN_STOP){
            direction = newDirection;
        }

        else if ((betweenFloors == 1) && (newDirection != DIRN_STOP)) {
            printf("Kan ikke endre motorretning mellom etasjer");
        }

        else {
            direction = newDirection;
        }
        sendChangeToIO = 1;
    }
    
    // Sørge for at heisen ikke kjører utenfor områdene sine
    if ((newDirection == DIRN_DOWN) && (prewFloor == 1)){
        if (direction != DIRN_STOP){
            direction = DIRN_STOP;
            sendChangeToIO = 1;
        }
        printf("Kan ikke kjøre nedover fra første etasje");
    }

    else if ((newDirection == DIRN_UP) && (prewFloor == 4)){
        if (direction != DIRN_STOP){
            direction = DIRN_STOP;
            sendChangeToIO = 1;
        }
        printf("Kan ikke kjøre oppover fra fjerde etasje");
    }


    // stå stille om døren er åpen
    if (doorOpen && (direction != DIRN_STOP)){
        direction = DIRN_STOP;
        printf("Kan ikke kjøre med åpen dør");
        sendChangeToIO = 1;
    }


    if (sendChangeToIO){
        elevio_motorDirection(direction);
    }
}

void changeDoor(int newDoorOpen){
    if (newDoorOpen &&
        (direction == DIRN_STOP) &&
        (betweenFloors == 0) && 
        (doorOpen != newDoorOpen)){
            doorOpen = newDoorOpen;
            elevio_doorOpenLamp(doorOpen);
        }
    
    if (newDoorOpen && (direction != DIRN_STOP)){
        printf("kan ikke åpne dør i fart");
    }

    if (newDoorOpen && betweenFloors){
        printf("kan ikke åpne dør mellom etasjer");
    }

    // lukke dør
    if ((newDoorOpen == 0) && doorOpen){
        doorOpen = newDoorOpen;
        elevio_doorOpenLamp(doorOpen);
    }
}

void changeButtonLight(UpButtons newUpButtons, 
                       DownButtons newDownButtons,
                       ElevatorButtons newElevatorButtons){
    for (int i = 0; i < 3; i++){
        if (newDownButtons.buttons[i] != downButtons.buttons[i]){
            downButtons.buttons[i] = newDownButtons.buttons[i];
            elevio_buttonLamp(i+1, BUTTON_HALL_DOWN, downButtons.buttons[i]);
        }
    }

    for (int i = 0; i < 3; i++){
        if (newUpButtons.buttons[i] != upButtons.buttons[i]){
            upButtons.buttons[i] = newUpButtons.buttons[i];
            elevio_buttonLamp(i, BUTTON_HALL_UP, upButtons.buttons[i]);
        }
    }

    for (int i = 0; i < 4; i++){
        if (newElevatorButtons.buttons[i] != elevatorButtons.buttons[i]){
            elevatorButtons.buttons[i] = newElevatorButtons.buttons[i];
            elevio_buttonLamp(i, BUTTON_CAB, elevatorButtons.buttons[i]);
        }
    }
}

void changeStop(int newStop){
    if (newStop != stop){
        stop = newStop;
        elevio_stopLamp(stop);
    }
}
