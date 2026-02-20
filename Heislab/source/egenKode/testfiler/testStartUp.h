#include "../startUp.h"
#include "output.h"

int main(){
    while (!startUpUpdate()){
        outputUpdateStartUp();
    }
    
    return 0;
}