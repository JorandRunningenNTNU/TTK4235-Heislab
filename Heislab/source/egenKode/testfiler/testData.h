#ifndef data
#define data

typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;


#define N_BUTTONS 3

typedef enum { 
    BUTTON_HALL_UP      = 0,
    BUTTON_HALL_DOWN    = 1,
    BUTTON_CAB          = 2
} ButtonType;

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
    Stopp = -2,
    PAUSE_DOOR_OPEN = -1,
    PAUSE_DOOR_CLOSED = 0,
    ETG_1 = 1,
    ETG_2 = 2,
    ETG_3 = 3,
    ETG_4 = 4
} Actions; 

#endif