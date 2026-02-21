#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "egenKode/startUp.h"
#include "egenKode/input.h"
#include "egenKode/state.h"
#include "egenKode/queue.h"
#include "egenKode/control.h"
#include "egenKode/output.h"



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
