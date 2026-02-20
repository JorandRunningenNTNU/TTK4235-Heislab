#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "startUp.h"
#include "input.h"
#include "state.h"
#include "queue.h"
#include "control.h"
#include "output.h"



int main(){
    elevio_init();

    // oppstart
    while (!startUpUpdate()){
        outputUpdateStartUp();
    }

    // videre kjøring
    while(1){
        inputUpdate();
        stateUpdate();
        queueUpdate();
        controlUpdate();
        outputUpdate();
    }
    return 0;
}
