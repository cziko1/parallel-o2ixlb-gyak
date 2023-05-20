#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "randomNumber.h"
#include "makeArray.h"
#include "printArray.h"

void shellSort(int array[], int count) {
    int gap, i, j, temp;


    for (gap = count / 2; gap > 0; gap /= 2) {
        // Parallelize the insertion sort loop what is using OpenMP
        #pragma omp parallel for shared(array, gap) private(i, j, temp)
        for (i = gap; i < count; i++) {
            temp = array[i];
            j = i;
            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }
    }
}


int main(){
    int i, count;
    count=randNumber();
    int array[count];
    makeArray(array, count);
    printArray(array, count);
    shellSort(array, count);
    printf("\nShell sort:\n");
    printArray(array, count);
    
    return 0;
}