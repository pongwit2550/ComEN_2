#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Info;
    int H;    // ความสูงของ subtree ที่ node นี้เป็นราก (ใช้คำนวณ BF เท่านั้น ไม่ print)
    int BF;   // Balance Factor = height(Left) - height(Right)
    int Hi;   // Level = ระดับความลึกจาก root (root อยู่ level 0)
    struct Node *Left;
    struct Node *Right;
    struct Node *Mother;
} TYPE_NODE;

typedef struct Node *TYPE_NODEPTR;

int height(TYPE_NODEPTR N) {
    if (N == NULL) {
        return 0;
    }
    return N->H;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int get_Balance(TYPE_NODEPTR N) {
    if (N == NULL) {
        return 0;
    }
    return height(N->Left) - height(N->Right);
}

// สร้าง node ใหม่พร้อม level ที่รู้อยู่แล้วตอนแทรก
TYPE_NODEPTR MakeT(int data, int level) {
    TYPE_NODEPTR new_T = (TYPE_NODEPTR)malloc(sizeof(TYPE_NODE));
    new_T->Info = data;
    new_T->H = 1;
    new_T->BF = 0;
    new_T->Hi = level;
    new_T->Left = NULL;
    new_T->Right = NULL;
    new_T->Mother = NULL;
    return new_T;
}

// หลังแทรก node ใหม่ ไล่ย้อนขึ้นไปถึง root ผ่าน Mother
// อัปเดต H กับ BF ของทุก node บนเส้นทางนี้
// (มีแค่ node บนเส้นทางจาก node ใหม่ถึง root เท่านั้นที่ค่าจะเปลี่ยน
//  node กิ่งอื่นที่ไม่เกี่ยวข้องกับการแทรกครั้งนี้ไม่ต้องแตะ)
void updatePathToRoot(TYPE_NODEPTR N) {
    while (N != NULL) {
        N->H  = 1 + max(height(N->Left), height(N->Right));
        N->BF = get_Balance(N);
        N = N->Mother;
    }
}

int addB(TYPE_NODEPTR T, TYPE_NODEPTR Q, int Data) {
    TYPE_NODEPTR P, N;
    P = T;
    int level = 0;

    while (P != NULL) {
        if (Data == P->Info) {
            return 0; 
        }
        Q = P;
        level++;
        if (Data < P->Info) {
            P = P->Left;
        } else {
            P = P->Right;
        }
    }

    N = MakeT(Data, level);
    N->Mother = Q;

    if (Data < Q->Info) {
        Q->Left = N;
    } else {
        Q->Right = N;
    }

    updatePathToRoot(N);
    return 1;
}

void InOrder(TYPE_NODEPTR T) {
    if (T != NULL) {
        InOrder(T->Left);
        printf("[%d %d %d] ", T->Info, T->BF, T->Hi);
        InOrder(T->Right);
    }
}

int main() {
    TYPE_NODEPTR T = NULL;
    T = MakeT(3, 0);
    InOrder(T); printf("\n");

    addB(T, T, 6); InOrder(T); printf("\n");
    addB(T, T, 7); InOrder(T); printf("\n");
    addB(T, T, 2); InOrder(T); printf("\n");

    return 0;
}