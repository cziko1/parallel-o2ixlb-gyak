#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "randomNumber.h"

int randomNumber(){
    int random, max, min;
    max=100;
    min=50;
    srand(time(NULL));
    random=rand() % max+min;
    return random;
}