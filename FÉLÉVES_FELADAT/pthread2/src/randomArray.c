#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "randomArray.h"

void randomArray(int arr[], int n){
    int i;
    int max, min, random;
    max=10;
    srand(time(NULL));
    

    for(i=0; i<n; i++){

        random=rand() % max+1;
        arr[i]=random;
        printf("%d. elemnet: %d\n", i+1,arr[i]);

    }

}