#include <stdio.h>
int main() {
    int max=0, num, idx;
    for (int i = 1; i <= 9; i++) {
        scanf("%d", &num);
        if (num > max) {
            max = num;
            idx = i;
        };
    }
    printf("%d\n%d", max, idx);
}