#include "control.h"
#include "queue.h"
#include "state.h"

int stop = 0;
int door = 0;
Direction direction;
UpButtons up = {0, 0, 0};
DownButtons down = {0, 0, 0};
ElevatorButtons elevator = {0, 0, 0, 0};

void controlUpdate(){
    Actions next = queueNext();

    switch (next)
    {
    case STOP:
        stop = 1;
        direction = DIRN_STOP;
        up = queueUpOrdrs();
        down = queueDownOrdrs();
        elevator = queueElevatorOrdrs();
        
        // døra skal være åpen om man stopper i en etasje
        if ((int)statePosition() == statePosition()){door = 1;}
        else{door = 0;}
        break;
    
    
    case PAUSE_DOOR_OPEN:
        stop = 0;
        direction = DIRN_STOP;
        up = queueUpOrdrs();
        down = queueDownOrdrs();
        elevator = queueElevatorOrdrs();
        door = 1;
        break;
    
    case PAUSE_DOOR_CLOSED:
        stop = 0;
        direction = DIRN_STOP;
        up = queueUpOrdrs();
        down = queueDownOrdrs();
        elevator = queueElevatorOrdrs();
        door = 0;
        break;
    
    // default er å bevege seg i retning av en etasje
    default:
        stop = 0;
        up = queueUpOrdrs();
        down = queueDownOrdrs();
        elevator = queueElevatorOrdrs();
        door = 0;

        if (statePosition() > next){direction = DIRN_DOWN;}
        else {direction = DIRN_UP;}
    }
}

int controlStopp(){return stop;}

int controlDoor(){return door;}

UpButtons controlUpButtons(){return up;}

DownButtons controlDownButtons(){return down;}

ElevatorButtons controlElevatorButtons(){return elevator;}

MotorDirection controlDirection(){return direction;}