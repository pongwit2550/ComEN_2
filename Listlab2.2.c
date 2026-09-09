#include <stdio.h>
#include <stdlib.h>

//Node liniked list
typedef struct Node { 
        int data;
        struct Node *next;
} TYPE_NODE;
typedef struct Node *type_nodePtr;

struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *q;


type_nodePtr NewNode(int new_data, TYPE_NODE *next){
    if(head == NULL){
        type_nodePtr new_node = (type_nodePtr)malloc(sizeof(TYPE_NODE));
        new_node->data = new_data;
        new_node->next = next;
        head = new_node;
        tail = head;
    }else{
        type_nodePtr new_node = (type_nodePtr)malloc(sizeof(TYPE_NODE));
        new_node->data = new_data;
        new_node->next = next;
        head = new_node;
    }
}

void printList(TYPE_NODE *n ){
   
    while ( n != NULL)
    {
       printf(" Head : -> %d \n", n->data);
       n = n->next;
    }
}

void printTialandQ(TYPE_NODE *t , TYPE_NODE *q){
  
    while ( t != NULL && q != NULL)
    {
       printf(" Tail : -> %d \n", t->data);
       t = t->next;
       printf(" Q : -> %d \n", q->data);
       q = q->next;
    }
}

void mergQtoList(TYPE_NODE *nq){
    tail->next = nq;   
    tail = nq;        
}

void print(TYPE_NODE *head){
    TYPE_NODE *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    NewNode(1,head);
    NewNode(2,head);
    NewNode(3,head);

    for (int i = 4; i <= 5; i++) {
        NewNode(i, head);
    }

    printList(head);
    print(head);

    type_nodePtr tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}