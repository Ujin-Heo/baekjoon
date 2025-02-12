#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int numerator = 1;
    for (int i = 0; i < K; i++) {
        numerator *= N;
        N--;
    }

    int denominator = 1;
    for (int i = 1; i <= K; i++) {
        denominator *= i;
    }

    int result = numerator / denominator;
    printf("%d", result);

}