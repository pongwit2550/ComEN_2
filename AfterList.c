#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} type_node;

typedef type_node *type_nodePtr;


type_nodePtr newNode(int data) {
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


void insertAfter(int data, type_nodePtr point) {
    if (point == NULL) {
        printf("point is NULL, cannot insert\n");
        return;
    }

    type_nodePtr newNode = (type_nodePtr)malloc(sizeof(type_node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = point->next;   
    point->next = newNode;         
}


void deleteAfter(type_nodePtr point) {
    if (point == NULL || point->next == NULL) {
        printf("Cannot delete: no node after point\n");
        return;
    }

    type_nodePtr target = point->next;   
    point->next = target->next;         
    free(target);                        
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
    // สร้างลิสต์เริ่มต้น 1 -> 2 -> 3
    type_nodePtr head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);

    print(head);
    printf("--------------\n");

    insertAfter(6, head);
    print(head);

    insertAfter(7, head->next);
    print(head);

    deleteAfter(head);
    print(head);

    deleteAfter(head->next);
    print(head);

    freeList(head);   
    return 0;
}