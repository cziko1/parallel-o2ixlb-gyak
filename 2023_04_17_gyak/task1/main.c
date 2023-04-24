#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOF 10
float RNG_Double(float min, float max);

int main(int arc, char **argv)
{
    srand(time(NULL));
    float arr[NOF];
    int i;
    float multiplicate = 1.0;

    for (i=0; i<NOF; i++)
        arr[i] = RNG_Double(0.0,100.0);
    for (i=0; i<NOF; i++)
        multiplicate = multiplicate * arr[i];
    printf("Multiplied: %.2f\n", multiplicate);
}

float RNG_Double(float min, float max)
{
    float element = ((float)rand()) / RAND_MAX;
    float num = element * (max - min) + min;
    return num;
}