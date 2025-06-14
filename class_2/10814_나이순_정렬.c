#include <stdio.h>
#include <stdlib.h>

// 버킷 정렬 사용함. 1~200살에 대해 버킷을 만들고, 각각의 버킷 안에서 연결 리스트 생성함. 새로 들어오는 NODE가 연결 리스트의 제일 끝에 가게 함.
// 일종의 해시 맵이라고 볼 수도 있음. NODE *bucket = buckets[pNew->age]; 부분에서 hash(age) -> age 형태의 아주 간단한 해시 함수 사용.
// 시간 복잡도: 입력: O(N), 출력: O(N + Kmax) = O(N) (N 회원수가 Kmax 나이 수 보다 훨씬 크므로)
// 전체 시간 복잡도: O(N)

typedef struct node {
    int age;
    char name[101];
    struct node *next;
} NODE;

void _insert_into_bucket(NODE **bucket, NODE **bucket_tail, NODE *pNew) {
    if (*bucket == NULL) {
        *bucket = *bucket_tail = pNew;
        return;
    }

    (*bucket_tail)->next = pNew;
    *bucket_tail = pNew;
    return;
}

void insert(NODE **buckets, NODE **bucket_tails, NODE *pNew) {
    NODE *bucket = buckets[pNew->age];
    NODE *bucket_tail = bucket_tails[pNew->age];
    _insert_into_bucket(&bucket, &bucket_tail, pNew);
    buckets[pNew->age] = bucket;
    bucket_tails[pNew->age] = bucket_tail;
    return;
}

int main() {

    int N = 0;
    scanf("%d", &N);

    NODE **buckets = (NODE**)malloc(sizeof(NODE*) * 201); // 0살 ~ 200살: 0살은 사용 x
    NODE **bucket_tails = (NODE**)malloc(sizeof(NODE*) * 201);
    for (int i = 1; i <= 200; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < N; i++) {
        NODE *pNew = (NODE*)malloc(sizeof(NODE));
        pNew->next = NULL;
        scanf("%d %s", &pNew->age, pNew->name);
        insert(buckets, bucket_tails, pNew);
    }

    for (int i = 1; i <= 200; i++) {
        NODE *toPrint = buckets[i];
        NODE *toFree = NULL;
        while (toPrint != NULL) {
            printf("%d %s\n", toPrint->age, toPrint->name);
            toFree = toPrint;
            toPrint = toPrint->next;
            free(toFree);
        }
    }
    free(buckets);
    free(bucket_tails);

    return 0;
}
