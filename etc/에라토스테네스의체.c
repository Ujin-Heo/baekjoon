#include <stdio.h>
#include <stdlib.h>

int main()  {

    int M, N;
    scanf("%d %d", &M, &N);

    char *flags = (char*)malloc(N+1);
    for (int i= 0; i < N+1; i++) {
        flags[i] = 0;  // 처음에 calloc으로 할당하면 자동으로 모든 값 0으로 초기화됨.
    }
    flags[1] = 1;

    for (int i = 2; i * i <= N; i++) {  // sqrt 쓸 필요 없이 i * i <= N으로 해도 됨. 
        if (flags[i] == 1) {
            continue;
        }

        int toCrossOut = i * 2;
        while (toCrossOut <= N) {
            flags[toCrossOut] = 1;
            toCrossOut += i;
        }
    }

    for (int i = M; i <= N; i++) {
        if (flags[i] != 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(flags);

    return 0;
}
