#include <stdio.h>

#include "printArray.h"

void printArray(int array[], int count) {
    int i;
    for (i = 0; i < count; i++)
        printf("%d. element %d\n", i+1, array[i]);
}