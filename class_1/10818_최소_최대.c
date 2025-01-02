#include <stdio.h>
int main() {
    int N, min=0, max=0, num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (!min || num < min) min = num;
        if (!max || num > max) max = num;
    }
    printf("%d %d", min, max);
}