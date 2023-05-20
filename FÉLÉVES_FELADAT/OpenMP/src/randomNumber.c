#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "randomNumber.h"

int randNumber()
{   
    int random, max, min;

    max=20;
    min=10;
    
    srand(time(NULL));

    random = rand()%max-min;
    
    return random;
}
