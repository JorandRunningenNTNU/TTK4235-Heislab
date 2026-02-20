#ifndef data
#define data
#include "../driver/elevio.h"

typedef struct{
    int buttons[3]; // etasje 1, 2, 3
} UpButtons;

typedef struct{
    int buttons[3]; // etasje 2, 3, 4
} DownButtons;

typedef struct{
    int buttons[4]; // etasje 1, 2, 3, 4
} ElevatorButtons;

typedef enum{
    STOP = -2,
    PAUSE_DOOR_OPEN = -1,
    PAUSE_DOOR_CLOSED = 0,
    ETG_1 = 1,
    ETG_2 = 2,
    ETG_3 = 3,
    ETG_4 = 4
} Actions; 

#endif