#include <stdio.h>

#define OFFSET 1000000

// 일반적인 BST -> 랜덤한 입력에 대해서는 N개 입력 시간 복잡도가 O(NlogN)이지만, 정렬된 입력에 대해서는 O(N^2)임. -> 시간 초과 발생
// AVL Tree, Heap Sort, Counting Sort(계수 정렬) 중 하나를 사용.
// 계수 정렬이 코드가 제일 간단함.

int main() {

    int N = 0;
    scanf("%d", &N);

    char flags[2*OFFSET+1] = {0,};

    int n = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        flags[n+OFFSET] = 1;
    }

    for (int i = 0; i <= 2*OFFSET; i++) {
        if (flags[i]) {
            printf("%d\n", i-OFFSET);
        }
    }

}