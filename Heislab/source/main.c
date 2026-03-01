#include "egenKode/startUp.h"
#include "egenKode/input.h"
#include "egenKode/state.h"
#include "egenKode/queue.h"
#include "egenKode/control.h"
#include "egenKode/output.h"



int main(){
    char c;
    printf("start");
    c = getchar();

    // oppstart
    while (!startUpUpdate()){
        outputUpdateStartUp();
        printf("fortsett oppstart \n");
        c = getchar();
    }

    // videre kjøring
    while(1){
        printf("fortsett hoved \n");
        c = getchar();
        inputUpdate();
        stateUpdate();
        queueUpdate();
        controlUpdate();
        outputUpdate();
    }
    printf("%c", c);
    return 0;
}
