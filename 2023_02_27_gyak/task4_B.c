#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    float max_rand = 500;
  	float max=1000;   //  random little help ':D 
    float n;    // the random number 
    float random;   // little help
    //algorithm for creating a random number 
	//(float cast) (float cast)	(RAND_MAX) is a costant included in the lib time.h
    random=((float)rand()/(float)(RAND_MAX)) * max_rand; //it's a number between 0 and 500
    
    n=max-random; //tha random number 500 and 1000 

    printf("The number between 500 and 1000: %f", n);
    
    return 0;
}
