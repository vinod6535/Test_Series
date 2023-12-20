#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure definition for the queue
typedef struct {
    int left;
    int right;
    int *arr;
    int size;
} MyQueue;

// Function to create a new queue
MyQueue* myQueueCreate() {
    MyQueue *ptr = (MyQueue *)malloc(sizeof(MyQueue));
    ptr->size = 100;
    ptr->left = 0;
    ptr->right = 0;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
    return ptr;
}

// Function to push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    obj->arr[obj->right] = x;
    obj->right++;
}

// Function to pop an element from the queue
int myQueuePop(MyQueue* obj) {
    int val = obj->arr[obj->left];
    obj->left++;
    return val;
}

// Function to peek at the front element of the queue
int myQueuePeek(MyQueue* obj) {
    return obj->arr[obj->left];
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return obj->left == obj->right;
}

// Function to free the memory allocated for the queue
void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    // Create a new queue
    MyQueue* obj = myQueueCreate();

    // Push elements into the queue
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePush(obj, 3);

    // Peek at the front element
    printf("Front element: %d\n", myQueuePeek(obj));

    // Pop elements from the queue
    printf("Popped element: %d\n", myQueuePop(obj));
    printf("Popped element: %d\n", myQueuePop(obj));

    // Check if the queue is empty
    if (myQueueEmpty(obj)) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    // Free the memory allocated for the queue
    myQueueFree(obj);

    return 0;
}
