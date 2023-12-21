#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->front = -1;
    obj->rear = -1;
    obj->size = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == -1 && obj->rear == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->size) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    } else if (myCircularQueueIsEmpty(obj)) {
        obj->front++;
        obj->rear++;
        obj->arr[obj->rear] = value;
        return true;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    } else if (obj->rear == obj->front) {
        obj->rear = -1;
        obj->front = -1;
        return true;
    }
    obj->front = (obj->front + 1) % obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

int main() {
    // Create a circular queue with a capacity of 5
    MyCircularQueue* obj = myCircularQueueCreate(5);

    // Enqueue some elements
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 2);
    myCircularQueueEnQueue(obj, 3);

    // Display front and rear
    printf("Front: %d\n", myCircularQueueFront(obj)); // Output: 1
    printf("Rear: %d\n", myCircularQueueRear(obj));   // Output: 3

    // Dequeue an element
    myCircularQueueDeQueue(obj);

    // Display front and rear after dequeue
    printf("Front after dequeue: %d\n", myCircularQueueFront(obj)); // Output: 2
    printf("Rear after dequeue: %d\n", myCircularQueueRear(obj));   // Output: 3

    // Check if the circular queue is full or empty
    printf("Is full: %d\n", myCircularQueueIsFull(obj));   // Output: 0 (Not full)
    printf("Is empty: %d\n", myCircularQueueIsEmpty(obj)); // Output: 0 (Not empty)

    // Free the memory
    myCircularQueueFree(obj);

    return 0;
}
