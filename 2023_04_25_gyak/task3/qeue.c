#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
    int size;
} queue;

// function to create a new empty queue
queue *create_queue() {
    queue *new_queue = malloc(sizeof(queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

// function to destroy a queue and free all associated memory
void destroy_queue(queue *q) {
    node *current = q->front;
    while (current != NULL) { // loop through each node in the queue
        node *next = current->next;
        free(current); // free the current node
        current = next; // move to the next node
    }
    free(q); // free the queue struct itself
}

// function to add an element to the back of a queue
void enqueue(queue *q, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->front == NULL) { // if the queue is currently empty
        q->front = new_node; // set both front and rear to the new node
        q->rear = new_node;
    } else {
        q->rear->next = new_node; // add the new node to the rear of the queue
        q->rear = new_node; // update the rear pointer
    }
    q->size++; // increment the size of the queue
}

// function to remove and return the element at the front of a queue
int dequeue(queue *q) {
    if (q->front == NULL) { // if the queue is currently empty
        printf("Error: queue is empty\n");
        exit(1);
    }
    int data = q->front->data;
    node *temp = q->front;
    q->front = q->front->next; // remove the front node from the queue
    free(temp); // free the removed node
    q->size--; // decrement the size of the queue
    return data;
}

// function to print the contents of a queue
void print_queue(queue *q) {
    node *current = q->front;
    printf("[");
    while (current != NULL) { // loop through each node in the queue
        printf("%d", current->data); // print the node's data
        if (current->next != NULL) {
            printf(", "); // print a comma and space unless this is the last node
        }
        current = current->next; // move to the next node
    }
    printf("]\n");
}

int main() {
    queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    dequeue(q);
    dequeue(q);

    enqueue(q, 4);
    enqueue(q, 5);

    print_queue(q);

    destroy_queue(q);

    return 0;
}
