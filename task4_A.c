#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    int max;
    int min;
    int n;

    printf("give me the minimum number?\n");
    scanf("%d", &min);
    printf("give me the maximum number?\n");
    scanf("%d", &max);

    n=rand()%(max-min+1)+min;
    printf("random number: %d",n);

    return 0;
}