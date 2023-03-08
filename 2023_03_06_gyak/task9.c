#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrf(int arr[], int N);
void speedf();

int main(){

    clock_t t;
    t=clock();
    speedf();
        
    int N;
    printf("Enter to the length: ");
    scanf("%d", &N);
    
    int arr[N];
    arrf(arr,N);
    
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("speedf() took %f seconds to execute\n", time_taken);
   
    return 0;
}

void arrf(int arr[], int N){

    int i, min, max;
    printf("Max: ");
    scanf("%d", &max);
    printf("Min: ");
    scanf("%d", &min);

    for ( i = 0; i < N; i++)
    {
        arr[i]=rand()%(max-min+1)+min;
        printf("%d. element:  %d\n", i+1, arr[i]);
    }    
    
}
void speedf(){
    printf("speedf() start\n");
    printf("press enter to stop speed\n");

    while(1){
        if(getchar())
        break;
    }
    printf("speedf() end \n");
}

