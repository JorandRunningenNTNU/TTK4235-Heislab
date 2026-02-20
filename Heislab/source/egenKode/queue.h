#ifndef queue
#define queue
#include "data.h"

void queueUpdate();
Actions queueNext();
UpButtons queueUpOrdrs();
DownButtons queueDownOrdrs();
ElevatorButtons queueElevatorOrdrs();

typedef enum {
    DOWN = 0,
    UP = 1,
} Direction;

#endif