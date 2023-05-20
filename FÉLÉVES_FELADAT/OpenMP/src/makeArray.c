#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "makeArray.h"

void makeArray(int array[], int count){
    int i;
    int max, random;
    max=10;
    srand(time(NULL));
    

    for(i=0; i<count; i++){

        random=rand() % max+1;
        array[i]=random;
        //printf("%d. elemnet: %d\n", i+1,array[i]);

    }

}