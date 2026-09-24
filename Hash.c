#include <stdio.h>
#include <stdlib.h>

//#define  HASH_SET_SIZE 10;
void select_func();
void show_hash();
typedef struct Node { 
	int info;
	struct Node *Next;
} TYPE_NODE;

typedef struct Node *type_nodeptr,type_node;
type_nodeptr node[10];

void create_hash(){
    for (int i = 0; i < 10; i++)
    {
        node[i] = NULL;
    }
    return show_hash();
}

void show_hash(){
    int i ; 
    type_nodeptr current;
     for ( i = 0; i < 10; i++){
        current = node[i];

        printf("basket[%d]-> ",i);
        if (current == NULL){
            printf(" NULL ");
        }
        
        
        while (current != NULL){
            printf("%d->", current->info);
            current = current->Next;
        }
        printf("\n");
     }
     printf(">>>Hash Table <<<\n");
     return select_func();
}

void insert_data(int data){
    type_nodeptr current;
    
    int h = data%10;
    type_nodeptr newnode = (type_nodeptr)malloc(sizeof(type_node));
    newnode->info = data;
    newnode->Next = NULL;

    if (node[h] == NULL){
        node[h] = newnode;
    } else {
        type_nodeptr current = node[h];
        while (current->Next != NULL){
            current = current->Next;
        }
        current->Next = newnode;
    }
    printf("===============================\n");
    printf("Insert %d into basket[%d]\n", data, h);
    printf("===============================\n");
    return select_func();   
}

void search(int data){
    
    int h = data%10;
    type_nodeptr current = node[h];

    while (current != NULL){

        if (current->info == data){
            printf("===============================\n");
            printf("data found in basket[%d] \n",h);
            printf("Amount %d \n",node[h]->info);
            printf("===============================\n");
            return select_func();
        }
        current = current->Next;
    }
    printf("Not Found!");
    return select_func();

}

void select_func(){
    printf("1.Hash Table \n" );
    printf("2.Insert Data \n");
    printf("3.Search Data \n");
    int choice = 0;

    printf("Switch : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        show_hash();
        break;
    case 2:
        int data = 0;
        printf("What value do you want to : ");
        scanf("%d", &data);
        insert_data(data);
        break;
    case 3:
        int num = 0;
        printf("search: ");
        scanf("%d", &num);
        search(num);
        break;
    default:
        printf("Invalid Choice!");
        return select_func();
        break;
    }
}
int main(){
    

    select_func();



    return 0;
}