#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

// stack 안에 base가 아니라 top을 저장하자! -> 새로 삽입된 node가 새로운 top이 됨.
typedef struct {
    int count;
    NODE* base;
} QUEUE;

void push(STACK* stack, int n) {

    NODE* pNew = (NODE*)malloc(sizeof(NODE));
    pNew->data = n;
    pNew->next = NULL;

    if (stack->count == 0) {
        stack->base = pNew;
        stack->count++;
        return;
    }

    NODE* cur = stack->base;
    NODE* prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = pNew;   
    stack->count++;

}

int pop(STACK* stack) {

    if (stack->count == 0) {
        return -1;
    }
    
    NODE* cur = stack->base;
    NODE* prev = NULL;
    for (int i = 0; i< stack->count - 1; i++) {
        prev = cur;
        cur = cur->next;
    }
    int dataOut = cur->data;
    free(cur);
    if (prev != NULL) prev->next = NULL;
    stack->count--;
    return dataOut;
}

int top(STACK* stack) {
    if (stack->count == 0) {
        return -1;
    }
    
    NODE* cur = stack->base;
    NODE* prev = NULL;
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
    }

    return prev->data;
}

int main() {
    int N;
    scanf("%d", &N);

    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->count = 0;

    char com[10] = {0,};
    for (int i=0; i<N; i++) {
        scanf("%s", com);

        if (strcmp(com, "push")==0) {
            int n;
            scanf("%d", &n);
            push(stack, n);
        } else if (strcmp(com, "pop")==0) {
            printf("%d\n", pop(stack));
        } else if (strcmp(com, "size")==0) {
            printf("%d\n", stack->count);
        } else if (strcmp(com, "empty")==0) {
            printf("%d\n", stack->count == 0);
        } else if (strcmp(com, "top")==0) {
            printf("%d\n", top(stack));
        }
    }
}