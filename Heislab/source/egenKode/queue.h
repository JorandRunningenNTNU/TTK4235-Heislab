#ifndef queue
#define queue
#include "data.h"

void queueUpdate();
Actions queueNext();

typedef enum {
    DOWN = 0,
    UP = 1,
} Direction;

#endif