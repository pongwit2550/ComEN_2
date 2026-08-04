#include <stdio.h>
#include <stdlib.h>

int main() {
    // Linked list implementation cod e goes here
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* head = NULL;

    // Function to add a new node at the beginning
    void push(int new_data) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = head;
        head = new_node;
    }

    // Function to print the linked list
    void printList() {
       struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    // Adding elements to the linked list
    push(10);
    push(20);
    push(30);

    // Print the linked list
    printList();

    return 0;
}