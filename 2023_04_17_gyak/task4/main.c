#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 4

int main() {
    // Random real values
    double array[ARRAY_SIZE];
    #pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = (double)rand() / 10; // Generate random values
    }

    // Calculate the element of the array in parallel
    double finalProduct = 1.0;
    #pragma omp parallel for reduction(* : finalProduct)
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        finalProduct *= array[i];
    }

    printf("Final product: %.2f\n", finalProduct);

    return 0;
}
