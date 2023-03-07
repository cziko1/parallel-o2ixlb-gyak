#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void int_arrf(int arr[], int n);
int length_arr(int max, int min); 
void double_arrf(double arr[], int n);
long int findSize(char file_name[]);


int main(){
    int n;
    int max, min;

    printf("Maximum: "); // maximum beolvasasa
    scanf("%d", &max);
    
    printf("Minimum: "); // minmum beolvasasa
    scanf("%d", &min);

    n=length_arr(max,min); // tomb hossza

    printf("max and min: %d, %d\n", max, min);  // maximum & minimum
    printf("The length of the array: %d\n", n); // tomb hossza kirasa

    int arr[n]; //A tomb dekralalasa
    int_arrf(arr,n); // tomb fugvenye
    double darr[n];
    double_arrf(darr,n);

    FILE *f = fopen("arr.file", "wb");          //fajlba iras
    fwrite(arr, sizeof(char), sizeof(arr), f);    
    fclose(f);

    char file_name[] ={"arr.file"};
    long int res=findSize(file_name);
    if(res!=-1)
        printf("Size of the file is %ld bytes\n", res);
    return 0;
}
long int findSize(char file_name[]){
    FILE* fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("File not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    //kiszamolja a fájl meretet
    long int res = ftell(fp);
    
    //bezarja a fajlt
    fclose(fp);

    return res;
}

int length_arr(int max, int min){   // tomb hossza fogveny ket bekert szelso ertek kozott es ez randomizalva
    int n;
    n=(rand()%(max-min+1)+min);
    return n; 
}
void int_arrf(int arr[], int n){    //tomb fuggvenye
    int i;
    int max, min;       // segedvaltozok

    printf("Enter the interall!\n"); //random szamok intervallum
    printf("Max: ");
    scanf("%d", &max);
    printf("Min: ");
    scanf("%d", &min);

    for ( i = 0; i < n; i++)
    {
        arr[i]=rand()%(max-min+1)+min;  // random szamok generalas
        printf("%d. element: %d\n", i+1, arr[i]+1);
    }
}

void double_arrf(double arr[], int n){    //tomb fuggvenye
    int i;
    double max, min, random;       // segedvaltozok

    printf("Enter the interall!\n"); //random szamok intervallum
    printf("Max: ");
    scanf("%lf", &max);
    printf("Min: ");
    scanf("%lf", &min);

    for ( i = 0; i < n; i++)
    {
        random=((double)rand()/(double)(RAND_MAX))*min; // double tipusu szamok random szamok generalas
        arr[i]=(max-random);
        printf("%d. element: %lf\n", i+1, arr[i]);
    }
}



