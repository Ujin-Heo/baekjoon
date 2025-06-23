#include <stdio.h>
#include <stdlib.h>

// 내장 qsort 라이브러리로 풂. qsort는 quick sort를 기반으로 하되, 여러 다른 정렬 알고리즘을 함께 사용하여 항상 O(NlogN)의 시간 복잡도를 보장하도록 함.
// 다음번에 heap sort 혹은 merge sort를 코드로 직접 구현해서 풀어보자.
// 계수정렬로 10^5 * 10^5 2차원 배열을 만들면 메모리 초과로 stack overflow가 일어남.

typedef struct {
    int x;
    int y;
} POINT;

int compare(const void *a, const void *b) {
    int x1 = ((POINT *)a)->x;
    int y1 = ((POINT *)a)->y;

    int x2 = ((POINT *)b)->x;
    int y2 = ((POINT *)b)->y;

    if (x1 != x2) {
        return x1 - x2;
    } else {
        return y1 - y2;
    }
}

int main() {

    int N = 0;
    scanf("%d", &N);

    POINT *pPoints = (POINT*)malloc(sizeof(POINT)*N);
    if (!pPoints) fprintf(stderr, "failed to allocate points.");

    for (int i=0; i<N; i++) {
        scanf("%d %d", &pPoints[i].x, &pPoints[i].y);
    }

    qsort(pPoints, N, sizeof(POINT), compare);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", pPoints[i].x, pPoints[i].y);
    }

    free(pPoints);
}
