#include <stdio.h>
#include <stdlib.h>

//define a struct to store the dynamic array's data
typedef struct {
    int *array;  
    int size;   
    int capacity; 
} dynamic_array;

//function creat a dynamic aarray with initial capacity
dynamic_array* create_dynamic_array(int initial_capacity) {
    dynamic_array *arr = malloc(sizeof(dynamic_array)); //allopcate memory
    if (arr == NULL) {
        return NULL;   //allocate faild, return NULL
    }
    arr->array = malloc(sizeof(int) * initial_capacity); // underlying array
    if (arr->array == NULL) {
        free(arr); // if allocation faild, free the metadata struct and return NULL
        return NULL;
    }
    arr->size = 0; // initialize the size to 0
    arr->capacity = initial_capacity; // initialize the capacity 
    return arr; // return to the newly dynamic array
}

// function too destroy a dynamic array and free to the memory
void destroy_dynamic_array(dynamic_array *arr) {
    free(arr->array);
    free(arr);
}

//function to the append a new element to the end of a dynamic array
int dynamic_array_append(dynamic_array *arr, int value) {
    if (arr->size == arr->capacity) {
        int *new_array = realloc(arr->array, sizeof(int) * arr->capacity * 2);
        if (new_array == NULL) {
            return 0;
        }
        arr->array = new_array;
        arr->capacity *= 2;
    }
    arr->array[arr->size] = value;
    arr->size++;
    return 1;
}

int main() {
    dynamic_array *arr = create_dynamic_array(10);
    for (int i = 0; i < 20; i++) {
        dynamic_array_append(arr, i);
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
    destroy_dynamic_array(arr);
    return 0;
}
