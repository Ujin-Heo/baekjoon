#include <stdio.h>

#define RANGE 10000

int main() {

    int N = 0;
    scanf("%d", &N);

    int count[RANGE+1] = {0,};

    int n = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        count[n]++;
    }

    for (int i = 1; i <= RANGE; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d\n", i);
        }
    }

}
