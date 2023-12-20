#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Stack data structure
struct Stack {
    char *arr;
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack, int size) {
    stack->arr = (char *)malloc(size * sizeof(char));
    stack->top = -1;
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

// Function to peek the top element of the stack
char peek(struct Stack *stack) {
    return stack->arr[stack->top];
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to remove duplicate letters from a string
char* removeDuplicateLetters(char* s) {
    int freq[26] = {0};  // Array to store the frequency of each character
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    bool exist[26] = {false};  // Array to check if a character already exists in the stack
    struct Stack st;
    initializeStack(&st, n);

    for (int i = 0; i < n; i++) {
        char ele = s[i];
        freq[ele - 'a']--;

        if (exist[ele - 'a']) {
            continue;
        }

        while (!isEmpty(&st) && peek(&st) > ele && freq[peek(&st) - 'a'] > 0) {
            exist[pop(&st) - 'a'] = false;
        }

        push(&st, ele);
        exist[ele - 'a'] = true;
    }

    char* ans = (char*)malloc((st.top + 2) * sizeof(char));  // Allocate memory for the result string
    int index = 0;

    while (!isEmpty(&st)) {
        ans[index++] = pop(&st);
    }

    ans[index] = '\0';

    // Reverse the result string
    for (int i = 0; i < index / 2; i++) {
        char temp = ans[i];
        ans[i] = ans[index - i - 1];
        ans[index - i - 1] = temp;
    }

    return ans;
}

int main() {
    char s[] = "bcabc";
    char* result = removeDuplicateLetters(s);
    printf("%s\n", result);

    free(result);  // Free the dynamically allocated memory

    return 0;
}
