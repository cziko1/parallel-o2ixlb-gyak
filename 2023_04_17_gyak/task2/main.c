#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOF 10

float RNG_Double(float min, float max);
float rec_mult(float * arr, int size);

int main(int arc, char **argv)
{
    srand(time(NULL));
    float arr[NOF];
    int i;

    for (i=0; i<NOF; i++)
        arr[i] = RNG_Double(0.0,100.0);
    printf("Recursive multiplied: %.2f\n", rec_mult(arr, NOF));
}

float RNG_Double(float min, float max)
{
    float element = ((float)rand()) / RAND_MAX;
    float num = element * (max - min) + min;
    return num;
}

float rec_mult(float * arr, int size)
{
    float lhalf = 1;
    float rhalf = 1;
    if (size == 1){
        return arr[0];
    }
    else
    {
        lhalf = rec_mult(arr, size/2);
        rhalf = rec_mult(arr+(size/2), size-(size/2));
        return lhalf*rhalf;
    }
}