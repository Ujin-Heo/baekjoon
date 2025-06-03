#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findFactors(int num, int* factors, int* count_ptr) {
    
    int root = (int)sqrt(num);
    // printf("\nroot of %d: %d\n", num, root);
    int count = 1;

    factors[0] = 1;
    for (int i = 2; i <= root; i++) { // for (i = 1; i * i < N; i++) 이런 방법도 있다.
        if (num % i == 0) {
            if (i == num / i) {
                factors[count] = i;
                count++;
            } else {
                factors[count] = i;
                factors[count + 1] = num / i;
                count += 2;
            }
        }
    }

    *count_ptr = count;
}

int checkPerfect(int num) {
    if (num == 1) {
        return -1;
    }

    int count = 0;
    int* factors = (int*)malloc(sizeof(int) * (int)(2 * sqrt(num) + 1)); // num의 약수 개수는 2 * sqrt(num) - 1 이하이지만, 2곱하고 int로 바꾸면서 소숫점 절삭되는 등 오차 커버 위해 +1로 씀.
    findFactors(num, factors, &count);

    // printf("factors of %d: ", num);
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += factors[i];
        // printf("%d ", factors[i]);
    }
    // printf("\n");

    int result = 0;
    // printf("sum: %d, num: %d\n", sum, num);
    result = sum - num;

    free(factors);

    return result;
}

void printPerfect(int num) {
    int result = 0;
    result = checkPerfect(num);

    if (result < 0) {
        printf("Deficient\n");
    } else if (result > 0) {
        printf("Abundant\n");
    } else {
        printf("Perfect\n");
    }
}

int main() {

    int T = 0;
    scanf("%d", &T);

    int* nums = (int*)malloc(sizeof(int) * T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < T; i++) {
        int num = nums[i];
        printPerfect(num);
    }

    free(nums);

    return 0;
}