#include <stdio.h>
#include "output.h"
#include "startUp.h"
#include "control.h"
#include "state.h"

// lokale funksjoner
void checkBetweenFloors(float position);
void changeDirection(MotorDirection newDirection);

// variabler
MotorDirection direction = DIRN_STOP;
int doorOpen = 1; // 0 er lukket, 1 er åpen, intielt skal døren være åpen se outp.upd.startUp()
int stop = 0; 
int prewFloor = 0;
int betweenFloors = 0;
UpButtons upButtons = {0, 0, 0};
DownButtons downButtons = {0, 0, 0};
ElevatorButtons elevatorButtons = {0, 0, 0, 0};


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
    // oppdatere all informasjon om posisjon
    float position = statePosition();
    checkBetweenFloors(position);
    
    if (betweenFloors == 0){
        prewFloor = (int) position;
    }

    // Sette motorretning
    MotorDirection newDirection = controlDirection();
    changeDirection(newDirection);
    
    // åpne dør
    // mangler støtte for å vite om døren skal være åpen fra control

    
    UpButtons newUpButtons = controlUpButtons();
    DownButtons newDownButtons = controlDownButtons();
    ElevatorButtons newElevatorButtons = controlElevatorButtons();

    //stopp
    int stop = controlStopp();
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
