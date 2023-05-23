#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "printArray.h"
#include "makeArray.h"
#include "randomNumber.h"

#include <sys/time.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a large gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Parallelize the insertion sort loop using OpenMP
        #pragma omp parallel for shared(arr, gap) private(i, j, temp)
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;

            // Shift elements until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}


int main() {

    struct timeval start_time, end_time;
    double elapsed_time;

    //starting measurment
    gettimeofday(&start_time, time);
    
    int n= 100000;//= randNumber();
    int arr[n]; // = {12, 34, 54, 2, 3};

    makeArray(arr,n);
    printf("Original array: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    gettimeofday(&end_time, NULL); 
    //end of the measurment 

    elapsed_time = (end_time.tv_sec - start_time.tv_sec)+(end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    printf("\nElapsed time: %f seconds\n", elapsed_time);

    return 0;
}
