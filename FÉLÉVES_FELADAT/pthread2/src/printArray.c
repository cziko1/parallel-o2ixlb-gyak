#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "printArray.h"

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}