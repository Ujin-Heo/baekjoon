#include <stdio.h>
int main() {
    int N, min, max, num;
    scanf("%d", &N);

    scanf("%d", &num);
    min = max = num;

    for (int i = 1; i < N; i++) {
        scanf("%d", &num);
        if (num < min) min = num;
        if (num > max) max = num;
    }
    printf("%d %d", min, max);
}