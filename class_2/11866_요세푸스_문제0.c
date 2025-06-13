#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    char removed;
    struct node *next;
} NODE;


int main() {

    int N = 0, K = 0;
    scanf("%d %d", &N, &K);

    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->data = 1;
    head->removed = 0;
    head->next = NULL;

    NODE *tail = NULL;
    NODE *pPre = head;
    for (int i = 2; i <= N; i++) {
        NODE *pNew = (NODE*)malloc(sizeof(NODE));
        pNew->data = i;
        pNew->removed = 0;
        pNew->next = NULL;
        
        pPre->next = pNew;
        pPre = pNew;

        if (i == N) {
            tail = pNew;
        }
    }
    if (N == 1) {
        tail = head; 
    }
   tail->next = head;

    int *results = (int*)malloc(sizeof(int) * N);
    int count = 0;
    NODE *cur = tail;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cur = cur->next;
            if (cur->removed == 1) {
                j--;
                // printf("skipped %d\n", cur->data);
            }
        }
        results[count] = cur->data;
        cur->removed = 1;
        // printf("%d %d\n", cur->data, cur->removed);
        count++;
        if (count == N) {
            break;
        }
    }

    printf("<");
    for (int i = 0; i < N-1; i++) {
        printf("%d, ", results[i]);
    }
    printf("%d>\n", results[N-1]);

    int freeCount = 0;
    NODE *toFree = head;
    NODE *temp = NULL;
    while (freeCount < N) {
        temp = toFree;
        toFree = toFree->next;
        free(temp);
        freeCount++;
    }
    free(results);

    return 0;
}
