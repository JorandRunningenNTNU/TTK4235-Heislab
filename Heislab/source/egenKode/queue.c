#include "queue.h"
#include "input.h"
#include "state.h"
#include "math.h"
#include <stdio.h>
#include <time.h>

void ordersOver(float position);
void ordersUnder(float position);
void checkOrders();
void deleteAllOrders();
double getTime();


Actions next = PAUSE_DOOR_CLOSED;
Direction direction = DOWN;
DownButtons down = {0, 0, 0};
UpButtons up = {0, 0, 0};
ElevatorButtons elevator = {0, 0, 0, 0};
float position;
int obstruction = 0;
int stop = 0;
int wait = 0;
double timeDoor = 0;
double timeObstruction = 0;



void queueUpdate(){
    checkOrders();

    // stopp sletter ordre og next skal da være stop. 
    if (stop){
        deleteAllOrders();
        next = STOP;
        return;
    }
    
    // obstruksjon beholder døren åpen
    if (obstruction){

    }

    //
    position = statePosition();
    if (direction == DOWN){
        // inluderer etasjen man er i
        ordersUnder(position);

        // betjene ordre i etasjen man er
        if (next = position){
            next = PAUSE_DOOR_OPEN;
        }
    }
    
    if (direction == UP){
        ordersOver(position);
    }
}  

Actions queueNext(){
    return next;
}

void ordersUnder(float position){
    // Sjekker nedover og finner nærmest etasje der folk i heisen skal av, eller folk skal 
    //    nedover. Dersom dette ikke finnes ser den etter folk i etasjene under som skal opp. 
    //    Dersom dette ikke finnes settes directopn til UP. 
    int level = (int)floor(position);
    
    // sjekke etter folk som skal ned
    int i = level;
    while (i>0){
        if (((i > 1) && (down.buttons[i-2])) ||
            (elevator.buttons[i-1])){
            next = i;
            return;
            }
        i--;
    }

    // sjekke etter folk som skal opp
    int i = level;
    while (i>0){
        if ((i<4) && (up.buttons[i-1])){
            next = i;
            return;
            }
        i--;
    }

    // sette renting til oppover
    direction = UP;
    next = PAUSE_DOOR_CLOSED;
}

void ordersOver(float position){
    // Sjekker oppover og finner nærmest etasje der folk i heisen skal av, eller folk skal 
    //    oppover. Dersom dette ikke finnes ser den etter folk i etasjene over som skal ned. 
    //    Dersom dette ikke finnes settes directopn til DOWN. 
    int level = (int)ceil(position);
    
    // sjekke etter folk som skal opp
    int i = level;
    while (i<5){
        if (((i < 4) && (up.buttons[i-1])) ||
            (elevator.buttons[i-1])){
                next = i;
                return;
            }
        i++;
    }

    // sjekke etter folk som skal ned
    int i = level;
    while (i<5){
        if ((i>1) && down.buttons[i-2]){
            next = i;
            return;
            }
        i++;
    }

    // sette renting til nedover
    direction = DOWN;
    next = PAUSE_DOOR_CLOSED;
}

void checkOrders(){
    UpButtons newUp = inputUpButtons();
    DownButtons newDown = inputDownButtons();
    ElevatorButtons newElevator = inputElevatorButtons();
    int newStop = inputStopp();
    int newObstruction = inputObstruction();

    for (int i=0; i<3; i++){
        up.buttons[i] = up.buttons[i] || newUp.buttons[i];
        down.buttons[i] = down.buttons[i] || newDown.buttons[i];
    }
    for (int i=0; i<4; i++){
        elevator.buttons[i] = elevator.buttons[i] || newElevator.buttons[i];
    }

    stop = newStop;

    // nullstiller obstruksjonstiden så lenge knappen holdes inne
    if (newObstruction){
        timeObstruction = getTime();
    }
    obstruction = newObstruction || obstruction;
}

void deleteAllOrders(){
    for (int i=0; i<3; i++){
        down.buttons[i] = 0;
        up.buttons[i] = 0;
    }
    
    for (int i=0; i<4; i++){
        elevator.buttons[i] = 0;
    }

}

double getTime(){
    return clock() / CLOCKS_PER_SEC;
}

