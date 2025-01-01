#include <stdio.h>
#include <stdlib.h>

// binary search root: 지피티 코드
int sqrt_floor(int N) {
    int low = 1, high = N, root = 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (mid * mid <= N) {
            root = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return root;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int root = sqrt_floor(N);

    // int root = 1;
    // while(root * root < N) {
    //     root++;
    // }
    // if (root * root > N) {
    //     root--;
    // }

    // 소수 -> 0, 소수 아님 -> 1
    char* prime = (char*)calloc(N + 1, sizeof(char)); // calloc: 모든 값을 0으로 초기화
    if (!prime) {
        printf("Memory allocation error\n");
        return 1;
    }

    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2; i <= root; i++) {
        if (prime[i] == 0) { // i가 소수인 경우

            int cur = i * 2;
            while (cur <= N) {
                prime[cur] = 1; // i의 배수들을 소수 아님으로 표시
                cur += i;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (prime[i] == 0) {
            printf("%d\n", i);
        }
    }

    free(prime);
}