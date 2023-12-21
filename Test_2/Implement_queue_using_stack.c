#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure definition for the stack
typedef struct {
    int top;
    int size;
    int* arr;
} MyStack;

// Function to create a new stack
MyStack* createStack(int size) {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(size * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(MyStack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(MyStack* stack) {
    return stack->top == stack->size - 1;
}

// Function to push an element onto the stack
void push(MyStack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

// Function to pop an element from the stack
int pop(MyStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int val = stack->arr[stack->top];
    stack->top--;
    return val;
}

// Structure definition for the queue
typedef struct {
    MyStack* stack1;
    MyStack* stack2;
} MyQueue;

// Function to create a new queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stack1 = createStack(100);
    queue->stack2 = createStack(100);
    return queue;
}

// Function to push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    while (!isEmpty(obj->stack1)) {
        push(obj->stack2, pop(obj->stack1));
    }
    push(obj->stack1, x);
    while (!isEmpty(obj->stack2)) {
        push(obj->stack1, pop(obj->stack2));
    }
}

// Function to pop an element from the queue
int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->stack1)) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = pop(obj->stack1);
    return val;
}

// Function to peek at the front element of the queue
int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->stack1)) {
        printf("Queue is empty\n");
        return -1;
    }
    return obj->stack1->arr[obj->stack1->top];
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stack1);
}

// Function to free the memory allocated for the queue
void myQueueFree(MyQueue* obj) {
    free(obj->stack1->arr);
    free(obj->stack1);
    free(obj->stack2->arr);
    free(obj->stack2);
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
