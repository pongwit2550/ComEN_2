#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* Mother;
}Treenode;

struct TreeNode* CreateNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
    newNode->data = data; 
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Mother = NULL;
    return newNode;
}

struct TreeNode* insert_left(struct TreeNode* root, int data){
    if(root == NULL){
        return CreateNode(data);
    }
    root->left = insert_left(root->left, data);
    root->Mother = root;
    return root;
}
struct TreeNode* insert_right(struct TreeNode* root, int data){
    if(root == NULL){
        return CreateNode(data);
    }
    root->right = insert_right(root->right, data);
    root->Mother = root;
    return root;
}

void gotoLeft(struct TreeNode* root){
    if(root->left == NULL){
        printf("No left Child! \n");
        return;
    }
    if(root->left != NULL){
        printf(" %d -> ", root->left->data);
        gotoLeft(root->left);
    }else{
        printf("Null! \n");
        return;
    }
}

void gotoRight(struct TreeNode* root){
    if(root->right == NULL){
        printf("No right Child! \n");
        return;
    }
    if(root->right != NULL){
        printf(" %d -> ", root->right->data);
        gotoRight(root->right);
    }else{
        printf("Null! \n");
        return;
    }
}

void gotoMother(struct TreeNode* root){
    if(root->Mother == NULL){
        printf("No Mother! \n");
        return;
    }
    printf("Mother: %d \n", root->Mother->data);
}

void Displaytree(struct TreeNode* root){
    if(root != NULL){
        Displaytree(root->left);
        printf(" %d -> ", root->data);
        Displaytree(root->right);
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {     
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//Pre-Order Traversal
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    struct TreeNode* root = NULL;
    root = insert_left(root, 50);
    insert_left(root, 30);
    insert_left(root, 70);
    insert_right(root, 20);
    insert_right(root, 40);
    insert_right(root, 60);

    //printf("RootMother is -> %d  \n", root->data);
    //gotoLeft(root);
    //gotoRight(root);
    //gotoMother(root);
    //Displaytree(root);
    preOrderTraversal(root);
    return 0;
}
