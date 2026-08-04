#include <stdio.h>
#include <stdlib.h>

int main() {
    // Doubly linked list implementation code goes here
    struct Node {
        int data;
        struct Node* next;
        struct Node* prev;
    };

    struct Node* head = NULL;

    // Function to add a new node at the beginning
    void push(int new_data) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = head;
        new_node->prev = NULL;

        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
    }

    // Function to print the doubly linked list
    void printList() {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    // Adding elements to the doubly linked list
    push(10);
    push(20);
    push(30);

    // Print the doubly linked list
    printList();

    return 0;
}