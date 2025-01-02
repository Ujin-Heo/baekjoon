#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct {
    NODE* head;
} LIST;

NODE* search(LIST* pList, int key) {

    if (!pList->head) {
        return pList->head;
    }

    NODE* cur = pList->head;
    NODE* prev = NULL;

    while (cur->data < key) {
        prev = cur;
        cur = cur->next;
        if(!cur) break;
    }

    return prev;
}

void insert (LIST* pList, NODE* pPre, NODE* pNew) {

    if (!pPre) {
        pNew->next = pList->head;
        pList->head = pNew;
        return;
    }

    pNew->next = pPre->next;
    pPre->next = pNew;
}

int main() {

    int N = 0;
    scanf("%d", &N);

    LIST* pList = (LIST*)malloc(sizeof(LIST));
    pList->head = NULL;

    for (int i = 0; i < N; i++) {
        NODE* pNew = (NODE*)malloc(sizeof(NODE));
        scanf("%d", &pNew->data);
        pNew->next = NULL;

        NODE* pPre = search(pList, pNew->data);
        insert(pList, pPre, pNew);
    }

    NODE* cur = pList->head;
    NODE* temp = NULL;
    while(cur != NULL) {
        temp = cur;
        printf("%d\n", cur->data);
        cur = cur->next;
        free(temp);
    }
    free(pList);

}