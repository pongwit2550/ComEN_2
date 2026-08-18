#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- 1. โครงสร้างข้อมูล ---------- */
typedef struct node {
    char name[20];      /* 1. ข้อมูลชื่อ */
    int  age;            /* 2. ข้อมูลอายุ */
    struct node *next;   /* ตัวชี้ไปยัง node ถัดไป */
} type_node;

typedef type_node *nodeptr;

nodeptr head = NULL;   /* หัวลิสต์ */

/* ---------- 2. ฟังก์ชันเพิ่มข้อมูล (Insert ท้ายลิสต์) ---------- */
void insertNode(const char *name, int age) {
    nodeptr n = (nodeptr) malloc(sizeof(type_node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(n->name, name);
    n->age = age;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        nodeptr temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

/* ---------- 3. ฟังก์ชันแสดงข้อมูลทั้งหมด ---------- */
void displayAll(void) {
    printf("========\n");
    printf("Name  Age\n");
    printf("========\n");
    nodeptr temp = head;
    while (temp != NULL) {
        printf("%s  %d\n", temp->name, temp->age);
        temp = temp->next;
    }
}

/* ---------- 4. ฟังก์ชันลบข้อมูลตามชื่อ ---------- */
void deleteNode(const char *name) {
    nodeptr temp = head;
    nodeptr prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Not found: %s\n", name);
        return;
    }

    if (prev == NULL) {
        head = temp->next;   /* ลบ node แรก */
    } else {
        prev->next = temp->next;
    }

    printf("Delete %s\n", temp->name);
    free(temp);
}

/* ---------- main ---------- */
int main(void) {
    char nameA[20], nameB[20];
    int ageA, ageB;

    printf("Insert name A: ");
    scanf("%s", nameA);
    printf("Insert age A: ");
    scanf("%d", &ageA);
    insertNode(nameA, ageA);

    printf("Insert name B: ");
    scanf("%s", nameB);
    printf("Insert age B: ");
    scanf("%d", &ageB);
    insertNode(nameB, ageB);

    displayAll();

    deleteNode(nameA);
    deleteNode(nameB);

    return 0;
}