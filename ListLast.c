#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} type_node;

typedef type_node *type_nodePtr;


type_nodePtr createNode(int data) {
    type_nodePtr newNode = (type_nodePtr)malloc(sizeof(type_node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void print(type_nodePtr head) {
    type_nodePtr cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

type_nodePtr insertLast(int data, type_nodePtr head) {
    type_nodePtr newNode = (type_nodePtr)malloc(sizeof(type_node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {          
        return newNode;
    }

    type_nodePtr cur = head;
    while (cur->next != NULL) {  
        cur = cur->next;
    }
    cur->next = newNode;         

    return head;                 
}


type_nodePtr deleteLast(type_nodePtr head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->next == NULL) {    
        free(head);
        return NULL;
    }

    type_nodePtr cur = head;
    while (cur->next->next != NULL) {  
        cur = cur->next;
    }
    free(cur->next);             
    cur->next = NULL;        

    return head;
}


void freeList(type_nodePtr head) {
    type_nodePtr cur = head;
    while (cur != NULL) {
        type_nodePtr temp = cur;
        cur = cur->next;
        free(temp);
    }
}


int main() {
    type_nodePtr head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    print(head);
    printf("--------------\n");

    head = insertLast(6, head);
    print(head);

    head = insertLast(7, head);
    print(head);

    head = deleteLast(head);
    print(head);

    head = deleteLast(head);
    print(head);

    freeList(head);
    return 0;
}