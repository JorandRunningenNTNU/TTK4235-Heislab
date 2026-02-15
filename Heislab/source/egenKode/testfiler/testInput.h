#ifndef testInput
#define testInput
#include "..\egenKode\data.h"
#include <stdio.h>
#include <time.h>

int main(){
    // gjør én utskriving av input hvert 5 sekund 4 ganger. 
    time_t start = time(NULL);
    time_t tid = time(NULL);
    int n = 1;
    while (((int)tid - (int)start) < 22){
        tid = time(NULL);
        if (((int)tid - (int)start) > n){
            inputUpdate();
            
            printf("Stopp %d \n", inputStopp());
            printf("Obstrksjon %D \n", inputObstruction());
            printf("Oppknapper %d, %d, %d \n", inputUpButtons().buttons[0],
                                               inputUpButtons().buttons[1],
                                               inputUpButtons().buttons[2]);
            printf("nedknapper %d, %d, %d \n", inputDownButtons().buttons[0],
                                               inputDownButtons().buttons[1],
                                               inputDownButtons().buttons[2]);
            printf("heisknapper %d, %d, %d, %d \n", inputElevatorButtons().buttons[0],
                                                    inputElevatorButtons().buttons[1],
                                                    inputElevatorButtons().buttons[2],
                                                    inputElevatorButtons().buttons[3]);
            
            n += 5;
        }
        
    }
    return 0;
}

#endif