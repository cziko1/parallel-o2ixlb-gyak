#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 4
#define NUM_THREADS 2

// Thread data
struct ThreadData {
    double* values;
    int size;
    double result;
};

// Thread function to multiply values
void* multiplyValues(void* arg) {
    struct ThreadData* data = (struct ThreadData*)arg;
    double product = 1.0;
    for (int i = 0; i < data->size; ++i) {
        product *= data->values[i];
    }
    data->result = product;
    pthread_exit(NULL);
}

int main() {
    // Create an array
    double array[ARRAY_SIZE] = {1.2, 2.5, 3.7, 4.1};

    // Divide the array into segments for each thread
    struct ThreadData threadData[NUM_THREADS];
    int segmentSize = ARRAY_SIZE / NUM_THREADS;
    int remainingSize = ARRAY_SIZE % NUM_THREADS;
    int startIndex = 0;

    // Initialize thread datas
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        int size = segmentSize;
        if (i < remainingSize) {
            size++;
        }

        threadData[i].values = &array[startIndex];
        threadData[i].size = size;
        startIndex += size;

        pthread_create(&threads[i], NULL, multiplyValues, (void*)&threadData[i]);
    }

    // Wait for finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Calculate
    double finalProduct = 1.0;
    for (int i = 0; i < NUM_THREADS; ++i) {
        finalProduct *= threadData[i].result;
    }

    printf("Final product: %.2f\n", finalProduct);

    return 0;
}
