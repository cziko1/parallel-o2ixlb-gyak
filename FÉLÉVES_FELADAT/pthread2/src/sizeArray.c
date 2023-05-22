#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sizeArray.h"



int sizeArray(){
    srand(time(NULL));
    
    int maxSize = 10;
    int size = rand() % maxSize + 5;

    return size;  
}
