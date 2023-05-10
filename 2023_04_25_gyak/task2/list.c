#include <stdio.h>
#include <stdlib.h>

// define a struct to store each node of the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// define a struct to store the linked list's metadata
typedef struct {
    node *head;
    int size;
} linked_list;

// function to create a new empty linked list
linked_list* create_linked_list() {
    linked_list *list = malloc(sizeof(linked_list)); // allocate memory for the metadata struct
    if (list == NULL) {
        return NULL; // if allocation failed, return NULL
    }
    list->head = NULL; 
    list->size = 0; 
    return list; 
}

// function to destroy a linked list and free its memory
void destroy_linked_list(linked_list *list) {
    node *current = list->head;
    while (current != NULL) { 
        node *next = current->next; 
        free(current); 
        current = next; 
    }
    free(list); 
}

// function to add a new element to the beginning of a linked list
void linked_list_prepend(linked_list *list, int value) {
    node *new_node = malloc(sizeof(node)); // allocate memory for the new node
    if (new_node == NULL) {
        return; // if allocation failed, return without modifying the list
    }
    new_node->data = value; 
    new_node->next = list->head; 
    list->head = new_node; 
    list->size++;
}

// function to add a new element to the end of a linked list
void linked_list_append(linked_list *list, int value) {
    node *new_node = malloc(sizeof(node)); // allocate memory for the new node
    if (new_node == NULL) {
        return; // if allocation failed, return without modifying the list
    }
    new_node->data = value; 
    new_node->next = NULL; 
    if (list->head == NULL) { 
        list->head = new_node; 
    } else {
        node *current = list->head;
        while (current->next != NULL) {
            current = current->next; 
        }
        current->next = new_node; 
    }
    list->size++; 
}

// function to remove the first element of a linked list
void linked_list_remove_first(linked_list *list) {
    if (list->head == NULL) { 
        return; 
    }
    node *old_head = list->head; 
    list->head = old_head->next; 
    free(old_head); 
    list->size--;
}
// function to remove the last element of a linked list
void linked_list_remove_last(linked_list *list) {
if (list->head == NULL) {
return; 
} 
else if (list->head->next == NULL) { 
free(list->head); 
list->head = NULL; 
list->size--; 
return;
}
node *current = list->head;
while (current->next->next != NULL) { 
current = current->next; 
}
free(current->next); 
current->next = NULL; 
list->size--; 
}

// function to print the contents of a linked list
void linked_list_print(linked_list *list) {
node *current = list->head;
printf("[");
while (current != NULL) { 
printf("%d", current->data); 
if (current->next != NULL) {
printf(", "); 
}
current = current->next; // move to the next node
}
printf("]\n");
}

int main(){
    linked_list *list=create_linked_list();
    linked_list_prepend(list, 1);
    linked_list_prepend(list, 2);
    linked_list_prepend(list, 3);

    linked_list_append(list, 4);
    linked_list_append(list, 5);
    linked_list_append(list, 6);

    linked_list_remove_first(list);
    linked_list_remove_last(list);

    linked_list_print(list);

    destroy_linked_list(list);

    return 0;

}

/*
    This implementation creates a linked list that can store integer values, 
    and provides functions to create and destroy the list,
    add elements to the beginning and end of the list, 
    remove elements from the beginning and end of the list,
    and print the contents of the list.
*/