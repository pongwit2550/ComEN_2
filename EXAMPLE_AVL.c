#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node { 
	int Info; 
   struct Node *Left; 
   struct Node *Right; 
	struct Node *Mother; 
}TYPE_NODE; 
typedef struct Node *TYPE_NODEPTR; 
int addB(TYPE_NODEPTR T,int Data); 
int BstSearch(TYPE_NODEPTR, int data); 
TYPE_NODEPTR MakeT(TYPE_NODEPTR T,int Data); 
void InOrder(TYPE_NODEPTR T); 
int main(void) { 
    TYPE_NODEPTR T,P; 
    T=NULL; 
    T = MakeT(T,3); 
    addB(T,7); 
    addB(T,6); 
    addB(T,2);  InOrder(T); printf("\n"); 
    BstSearch(T, 6); 
    BstSearch(T, 5); 
    return 0; 
} 
int addB(TYPE_NODEPTR T,int Data) { 
    TYPE_NODEPTR P, Q, N; 
    P = T; 
    while (P != NULL) { 
        if (Data == P -> Info){
            return(0);
        }  

        Q = P; 
        if (Data < P -> Info) {

            P = P -> Left; 
        }else {

            P = P -> Right; 
        }
    } 
    N = MakeT(N,Data); 
    if (Data < Q -> Info){

            Q -> Left = N; 
    }else {
            
            Q -> Right = N; 
            N->Mother = Q; 
   }
}
 
TYPE_NODEPTR MakeT(TYPE_NODEPTR T,int Data) { 
	T = (TYPE_NODEPTR) malloc(sizeof(TYPE_NODE)); 
	T->Info=Data; 
	T->Left=NULL; 
	T->Right=NULL; 
	T->Mother=NULL; 
	return T; 
} 
void InOrder(TYPE_NODEPTR T) { 
	if(T!=NULL) 
	{ 
		InOrder(T->Left); 
		printf("%d ",T->Info); 
		InOrder(T->Right); 
	} 
}