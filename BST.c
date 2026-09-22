#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;

} Node;

typedef struct Node *TYPE_NODEPTR;

int addB(TYPE_NODEPTR T, int Data) {



}


int main(){


    TYPE_NODEPTR T = NULL;
    T = MakeT(T,3);InOrder(T); printf("\n"); addB(T,7);InOrder(T); printf("\n"); addB(T,6);InOrder(T); printf("\n");
    addB(T,2); InOrder(T); printf("\n"); 
    addB(T,1); InOrder(T); printf("\n"); 
    addB(T,8); InOrder(T); printf("\n"); 
    addB(T,-4); InOrder(T); printf("\n");
}