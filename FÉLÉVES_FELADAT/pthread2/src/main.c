#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "insertionSort.h"
#include "printArray.h"
#include "sizeArray.h"
#include "randomArray.h"
#include "randomNumber.h"


// Structure for passing data to the thread
typedef struct {
    int* array;
    int start;
    int end;
} ThreadData;

void* shellSortThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int* array = data->array;
    int start = data->start;
    int end = data->end;

    int gap, i, j, temp;
    for (gap = (end - start) / 2; gap > 0; gap /= 2) {
        for (i = start + gap; i <= end; i++) {
            temp = array[i];
            j = i;
            while (j >= start + gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
    }

    return NULL;
}

void parallelShellSort(int array[], int n) {
    int num_threads;
    num_threads = randomNumber();

    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    int gap = n / num_threads;
    int i;
    for (i = 0; i < num_threads; i++) {
        thread_data[i].array = array;
        thread_data[i].start = i * gap;
        thread_data[i].end = (i == num_threads - 1) ? n - 1 : (i + 1) * gap - 1;
        pthread_create(&threads[i], NULL, shellSortThread, &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge the sorted subarrays
    int start = thread_data[0].start;
    int end = thread_data[num_threads - 1].end;
    int mid = thread_data[num_threads - 1].start;

    int* merged = (int*)malloc(n * sizeof(int));
    int left = start, right = mid + 1, k = start;

    while (left <= mid && right <= end) {
        if (array[left] <= array[right])
            merged[k++] = array[left++];
        else
            merged[k++] = array[right++];
    }

    while (left <= mid)
        merged[k++] = array[left++];
    while (right <= end)
        merged[k++] = array[right++];

    for (i = start; i <= end; i++)
        array[i] = merged[i];

    free(merged);
}


int main() {
    //int array[] = {64, 34, 25, 12, 22, 11, 90};
    //int n = sizeof(array) / sizeof(array[0]);
    int n=sizeArray();
    int array[n];

    n=sizeof(array) / sizeof(array[0]);

    printf("Array before sorting:\n");
    randomArray(array,n);

    parallelShellSort(array, n);

    printf("\nShell sorting:\n");
    printArray(array, n);


    free(array);
    return 0;
}
