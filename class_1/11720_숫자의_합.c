#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    char nums[105];
    scanf("%s", nums);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (int)(nums[i] - '0');
    }
    printf("%d", sum);
}