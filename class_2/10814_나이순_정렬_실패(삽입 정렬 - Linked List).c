#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int age;
    char name[101];
    struct node *next;
} NODE;


void insert(NODE **head, NODE *pNew) {
    if (*head == NULL) {
        *head = pNew;
        return;
    }

    int newAge = pNew->age;
    NODE *pCur = *head;
    NODE *pPrev = NULL;

    if (newAge < pCur->age) {
        pNew->next = *head;
        *head = pNew;
        return;
    }

    while (pCur != NULL && newAge >= pCur->age) {
        pPrev = pCur;
        pCur = pCur->next;
    }
    pPrev->next = pNew;
    pNew->next = pCur;
    return;
}

int main() {

    int N = 0;
    scanf("%d", &N);

    NODE *head = NULL;
    for (int i = 0; i < N; i++) {
        NODE *pNew = (NODE*)malloc(sizeof(NODE));
        pNew->next = NULL;
        scanf("%d %s", &pNew->age, pNew->name);
        insert(&head, pNew);
    }

    NODE *toPrint = head;
    NODE *toFree = NULL;
    while (toPrint != NULL) {
        printf("%d %s\n", toPrint->age, toPrint->name);
        toFree = toPrint;
        toPrint = toPrint->next;
        free(toFree);
    }

    return 0;
}
