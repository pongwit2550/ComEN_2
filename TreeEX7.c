#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* Mother;
}Treenode;
typedef struct TreeNode *TYPE_NODEPTR;

TYPE_NODEPTR root = NULL;      // ตัวจริง คงที่ตลอดโปรแกรม ใช้ตอน exit/free เท่านั้น
TYPE_NODEPTR roottmp = NULL;   // cursor ตำแหน่งปัจจุบัน ใช้กับทุกคำสั่ง

int running = 1;

TYPE_NODEPTR CreateNode(int data) {
    if (root != NULL) {
        printf("The tree already has a root node!\n");
        return root;
    }

    TYPE_NODEPTR newNode = (TYPE_NODEPTR)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Mother = NULL;

    root = newNode;
    roottmp = newNode;
    printf("Create First Node Successfully!\n");
    return root;
}

TYPE_NODEPTR insert_left(TYPE_NODEPTR t, int data){
    if (t == NULL) {
        printf("!! ERROR: no root yet, please create the first node !!\n");
        return NULL;
    }
    if (t->left != NULL) {
        printf("(left child already exists: %d)\n", t->left->data);
        return t;
    }

    TYPE_NODEPTR newNode = (TYPE_NODEPTR)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Mother = t;

    t->left = newNode;
    roottmp = newNode;   // cursor เดินตาม node ที่เพิ่ง insert
    return t;
}

TYPE_NODEPTR insert_right(TYPE_NODEPTR t, int data){
    if (t == NULL) {
        printf("!! ERROR: no root yet, please create the first node !!\n");
        return NULL;
    }
    if (t->right != NULL) {
        printf("(right child already exists: %d)\n", t->right->data);
        return t;
    }

    TYPE_NODEPTR newNode = (TYPE_NODEPTR)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->Mother = t;

    t->right = newNode;
    roottmp = newNode;   // cursor เดินตาม node ที่เพิ่ง insert
    return t;
}

void Displaytree(TYPE_NODEPTR node){
    if (node != NULL) {
        Displaytree(node->left);
        printf(" %d ->", node->data);
        Displaytree(node->right);
    }
}

TYPE_NODEPTR gotoLeft(TYPE_NODEPTR t){
    if (t->left == NULL) {
        printf("No left child!\n");
        return NULL;
    }
    roottmp = t->left;
    printf("Now at node: %d\n", roottmp->data);
    return roottmp;
}

TYPE_NODEPTR gotoRight(TYPE_NODEPTR t){
    if (t->right == NULL) {
        printf("No right child!\n");
        return NULL;
    }
    roottmp = t->right;
    printf("Now at node: %d\n", roottmp->data);
    return roottmp;
}

TYPE_NODEPTR gotoMother(TYPE_NODEPTR t){
    if (t->Mother == NULL) {
        printf("No mother (already at root)!\n");
        return NULL;
    }
    roottmp = t->Mother;
    printf("Now at node: %d\n", roottmp->data);
    return roottmp;
}

void freeTree(TYPE_NODEPTR node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

void preOrderTraversal(TYPE_NODEPTR node) {
    if (node != NULL) {
        printf(" %d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void inorderTraversal(TYPE_NODEPTR node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf(" %d ", node->data);
        inorderTraversal(node->right);
    }
}

void postOrderTraversal(TYPE_NODEPTR node) {
    if (node != NULL) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf(" %d ", node->data);
    }
}

void printMenu(void){
    const char *Select[12] = {
        "Exit The Program (Enter 0)",
        "Create Root Node",
        "Insert Left Node",
        "Insert Right Node",
        "Go to Left",
        "Go to Right",
        "Go to Mother",
        "Display Tree (from current position)",
        "Pre-Order Traversal (whole tree)",
        "In-Order Traversal (whole tree)",
        "Post-Order Traversal (whole tree)",
        "option 11;"
    };

    printf("\n==================================================\n");
    printf("|                SELECT FUNCTION                 |\n");
    printf("==================================================\n");
    for (int i = 0; i < 12; i++) {
        printf(" %2d) %s\n", i , Select[i]);
    }
    if (roottmp != NULL) {
        printf("--------------------------------------------------\n");
        printf(" Current position: %d\n", roottmp->data);
    }
    printf("==================================================\n");
    printf("Enter your choice: ");
}

void funcSelect() {
    int choice = 0;
    int data = 0;

    printMenu();
    if (scanf("%d", &choice) != 1) {
        // เคลียร์ input ที่ parse ไม่ได้ (เช่น user พิมพ์ตัวอักษร)
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid input, please enter a number.\n");
        return;
    }

    
    if (choice >= 2 && choice <= 10 && roottmp == NULL) {
        printf("!! Please create the root node first (option 1) !!\n");
        return;
    }

    switch (choice) {
        case 0:
            printf("Exit the program!\n");
            freeTree(root);
            root = NULL;
            roottmp = NULL;
            running = 0;
            break;

        case 1:
            printf("Enter data to create first node: ");
            scanf("%d", &data);
            CreateNode(data);
            break;

        case 2:
            printf("Enter data to insert left of %d: ", roottmp->data);
            scanf("%d", &data);
            insert_left(roottmp, data);
            break;

        case 3:
            printf("Enter data to insert right of %d: ", roottmp->data);
            scanf("%d", &data);
            insert_right(roottmp, data);
            break;

        case 4:
            printf("Go to Left:\n");
            gotoLeft(roottmp);
            break;

        case 5:
            printf("Go to Right:\n");
            gotoRight(roottmp);
            break;

        case 6:
            printf("Go to Mother:\n");
            gotoMother(roottmp);
            break;

        case 7:
            printf("Display Tree (in-order, from current position):\n");
            Displaytree(roottmp);
            printf("\n");
            break;

        case 8:
            printf("Pre-Order Traversal:\n");
            preOrderTraversal(roottmp);
            printf("\n");
            break;

        case 9:
            printf("In-Order Traversal:\n");
            inorderTraversal(roottmp);
            printf("\n");
            break;

        case 10:
            printf("Post-Order Traversal:\n");
            postOrderTraversal(roottmp);
            printf("\n");
            break;
        case 11:
            insert_left(roottmp,4);  
            inorderTraversal(roottmp); 
            printf("\n");
            
            insert_right(roottmp,12);  
            inorderTraversal(roottmp); 
            printf("\n");

            roottmp = gotoLeft(roottmp);
            insert_left(roottmp,2);  
            inorderTraversal(roottmp); 
            printf("\n");

            insert_right(roottmp,6);  
            inorderTraversal(roottmp); 
            printf("\n");

            roottmp = gotoMother(roottmp);
            roottmp = gotoRight(roottmp);
            insert_left(roottmp,10);  
            inorderTraversal(roottmp); printf("\n");
            insert_right(roottmp,14);  
            inorderTraversal(roottmp); printf("\n");
            break;

        default:
            printf("--------------------------------------\n");
            printf("| Invalid choice! Please select again! |\n");
            printf("--------------------------------------\n");
    }
}

int main(){
    while (running) {
        funcSelect();
    }
    return 0;
}