#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 4

int main() {
    // Create an array of random real values
    double array[ARRAY_SIZE];
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = (double)rand() / RAND_MAX; // Generate the random values between it 0-10
    }

    // Calculate the array of the elements
    double finalProduct = 1.0;
    #pragma omp parallel for reduction(* : finalProduct) // Reduction
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        finalProduct *= array[i];
    }

    printf("Final product: %.2f\n", finalProduct);

    return 0;
}
