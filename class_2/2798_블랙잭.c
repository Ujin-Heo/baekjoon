#include <stdio.h>
#include <stdlib.h>

// 오름차순
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b ;
}

int find_biggest_number_Within_M (int *nums, int N, int M) {
    int first = 0, second = 0, third = 0;
    int max = 0, sum = 0;
    for (int i = 0; i <= N-3; i++) {
        first = nums[i];
        for (int j = i+1; j <= N-2; j++) {
            second = nums[j];
            for (int k = j+1; k <= N-1; k++) {
                third = nums[k];
                sum = first + second + third;
                if (sum > max) {
                    if (sum == M) {
                        return sum;
                    } else if (sum < M) {
                        max = sum;
                    }
                }
            }
        }
    }
    return max;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *nums = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    
    qsort(nums, N, sizeof(int), compare);

    printf("%d", find_biggest_number_Within_M(nums, N, M));

    free(nums);
}
