#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} NODE;

typedef struct {
    int count;
    NODE* head;
    NODE* tail;
} QUEUE;

void push(QUEUE* que, int n) {

    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    pNew->data = n;
    pNew->prev = NULL;
    pNew->next = NULL;

    if (que->count == 0) {
        que->head = pNew;
        que->tail = pNew;
        que->count++;
        return;
    }

    pNew->prev = que->tail;
    que->tail->next = pNew;

    que->tail = pNew;
    que->count++;
    return;
}

int pop(QUEUE* que) {

    if (que->count == 0) {
        return -1;
    }

    int dataOut = que->head->data;
    NODE* toFree = que->head;

    if (que->count == 1) {
        que->head = NULL;
        que->tail = NULL;
        que->count--;
        return dataOut;
    }

    que->head = que->head->next;
    que->head->prev = NULL;
    que->count--;

    free(toFree);

    return dataOut;
}

int front(QUEUE* que) {
    if (que->count == 0) {
        return -1;
    }

    return que->head->data;
}

int back(QUEUE* que) {
    if (que->count == 0) {
        return -1;
    }

    return que->tail->data;
}

int main() {
    int N;
    scanf("%d", &N);

    QUEUE* que = (QUEUE*)malloc(sizeof(QUEUE));
    que->count = 0;
    que->head = NULL;
    que->tail = NULL;

    char com[10] = {0,};
    for (int i = 0; i < N; i++) {
        scanf("%s", com);

        if (strcmp(com, "push")==0) {
            int n = 0;
            scanf("%d", &n);
            push(que, n);
        } else if (strcmp(com, "pop")==0) {
            printf("%d\n", pop(que));
        } else if (strcmp(com, "size")==0) {
            printf("%d\n", que->count);
        } else if (strcmp(com, "empty")==0) {
            printf("%d\n", que->count == 0);
        } else if (strcmp(com, "front")==0) {
            printf("%d\n", front(que));
        } else if (strcmp(com, "back")==0) {
            printf("%d\n", back(que));
        }
    }
}
