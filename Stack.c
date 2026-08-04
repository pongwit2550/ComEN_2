#include <stdio.h>

int main() {
    //Stack implementation code goes here
    int stack[100];//arr
    int top = -1;//top of stack

    // Push operation
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    // Pop operation
    int popped = stack[top--];

    // Print the popped element
    printf("Popped element: %d\n", popped);

    return 0;
}