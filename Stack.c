#include <stdio.h>

int main() {
    //Stack implementation code goes here
    char stack[100];//arr
    int top = -1;//top of stack

    // Push operation
    stack[++top] = 'A';
    stack[++top] = 'B';
    stack[++top] = 'C';

    // Pop operation
    char popped = stack[top--];

    // Print the popped element
    printf("Popped element: %c\n", popped);

    return 0;
}