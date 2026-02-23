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
int doorOpen = 0;



void queueUpdate(){
    checkOrders();
    doorOpen = stateDoorOpen();
    position = statePosition();

    // stopp sletter ordre og next skal da være stop. 
    if (stop){
        deleteAllOrders();
        next = STOP;
        return;
    }
    
    // obstruksjon reseter doorOpen tiden om døren er åpen
    if (obstruction && doorOpen){
        timeDoor = getTime();
    }
    
    // Døren lukkes når tiden er uten
    if (doorOpen){
        if ((getTime() - timeDoor) > 3){
            next = PAUSE_DOOR_CLOSED;
            return;
        }
        next = PAUSE_DOOR_OPEN;
        return;
    }

    // betjene ordre når heisen er i DOWN modus
    if (direction == DOWN){
        ordersUnder(position);

        // betjene ordre i etasjen man er
        if (next == position){
            next = PAUSE_DOOR_OPEN;
            timeDoor = getTime();
            
            // sletter alle ordre i etasjen
            if (position != 4){up.buttons[(int)position - 1] = 0;}
            if (position != 1){down.buttons[(int)position - 2] = 0;}
            elevator.buttons[(int)position - 1] = 0;
        }
        return;
    }
    
    // betjene ordre om heisen er i UP-modus
    else {
        ordersUnder(position);

        // betjene ordre i etasjen man er
        if (next == position){
            next = PAUSE_DOOR_OPEN;
            timeDoor = getTime();

            // sletter alle ordre i etasjen
            if (position != 4){up.buttons[(int)position - 1] = 0;}
            if (position != 1){down.buttons[(int)position - 2] = 0;}
            elevator.buttons[(int)position - 1] = 0;
            
        }
        return;
    }
    // når ingenting skjer kommer heisen til å oscillere mellom up og down modus
}  

Actions queueNext(){
    return next;
}

UpButtons queueUpOrdrs(){
    return up;
}

DownButtons queueDownOrdrs(){
    return down;
}

ElevatorButtons queueElevatorOrdrs(){
    return elevator;
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
//EMMAS ENDRING: LIKER IKKE AT I ER DEFINERT FLERE GANGER, ENDRET DEN ENE TIL J
    // sjekke etter folk som skal opp
    int j = level;
    while (j>0){
        if ((j<4) && (up.buttons[j-1])){
            next = j;
            return;
            }
        j--;
    }

    // sette renting til oppover
    direction = UP;

    // Skrur på ingenting-ordre til ny bestilling kommer
    next = PAUSE_DOOR_CLOSED;
}

void ordersOver(float position){
    // Sjekker oppover og finner nærmest etasje der folk i heisen skal av, eller folk skal 
    //    oppover. Dersom dette ikke finnes ser den etter folk i etasjene over som skal ned. 
    //    Dersom dette ikke finnes settes directopn til DOWN. 
    int level = (int)ceil(position);

    // sjekke etter folk som skal opp
    int l = level;
    while (l<5){
        if (((l < 4) && (up.buttons[l-1])) ||
            (elevator.buttons[l-1])){
                next = l;
                return;
            }
        l++;
    }
    
    // sjekke etter folk som skal ned
    int k =level;
    while (k<5){
        if ((k>1) && down.buttons[k-2]){
            next = k;
            return;
            }
        k++;
    }

    // sette renting til nedover
    direction = DOWN;

    // Skrur på ingenting-ordre til ny bestilling kommer
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

    // Når stopp slås av skal det ta 3 sekudner før dørene lukkes
    if (!newStop && stop){
        timeDoor = getTime();
    }
    stop = newStop;

    obstruction = newObstruction;
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


