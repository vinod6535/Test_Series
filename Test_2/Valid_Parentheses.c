
#include <stdio.h>
#include <stdbool.h>

struct Stack {
    int top;
    char *arr;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack, int size) {
    stack->top = -1;
    stack->arr = (char *)malloc(size * sizeof(char));
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char data) {
    stack->top++;
    stack->arr[stack->top] = data;
}

// Function to pop an element from the stack
char pop(struct Stack *stack) {
    char val = stack->arr[stack->top];
    stack->top--;
    return val;
}

// Function to check if the given expression has valid parentheses
bool isValid(char *expression) {
    int size = strlen(expression);
    struct Stack stack;
    initializeStack(&stack, size);

    for (int i = 0; i < size; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        } else if (!isEmpty(&stack) && ((ch == ')' && pop(&stack) == '(') || (ch == ']' && pop(&stack) == '[') || (ch == '}' && pop(&stack) == '{'))) {
            // Check if stack is not empty before pop
        } else {
            free(stack.arr);
            return false; // Invalid parentheses
        }
    }

    bool result = isEmpty(&stack);
    free(stack.arr);
    return result;
}