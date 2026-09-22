#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} TypeNode;

typedef struct Node *TYPE_NODEPTR;


//NewNode FUnc
TYPE_NODEPTR MakeT(TYPE_NODEPTR T , int data){
    T = (TYPE_NODEPTR)malloc(sizeof(TypeNode));
    T->data = data;
    T->left = NULL;
    T->right = NULL;

    return T ;
}

TYPE_NODEPTR addB(TYPE_NODEPTR T, int data) {
    //T = (TYPE_NODEPTR)malloc(sizeof(TypeNode));
    if (T == NULL){
        //printf("Node is empty ! \n please Make a Node!");
        return MakeT(T, data);
    }

    if(data < T->data  ){
        T->left = addB(T->left, data);
    }else {
        T->right = addB(T->right, data);
    }
    
    return T;

}

void InOrder(TYPE_NODEPTR T){
  if (T != NULL) {
        InOrder(T->left);
        printf("%d -> ", T->data);
        InOrder(T->right);
    }
}

int BstSearch(TYPE_NODEPTR T, int data){
    
    if (T == NULL){
        printf("Not Found!");
        return 0;
    }

    if (data == T->data) {
        printf("Found!\n");
        return 1;
    }else if (data < T->data) {
        //printf(" | ");
        return BstSearch(T->left, data);
    }else {
        //printf(" | ");
        return BstSearch(T->right, data);
    }


}


int main(){


    TYPE_NODEPTR T = NULL;
    T = MakeT(T,3);
    addB(T,7);
    addB(T,6);
    addB(T,2);  InOrder(T); printf("\n");
    BstSearch(T, 6);
    BstSearch(T, 5);
}