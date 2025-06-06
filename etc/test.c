#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findFactors(int num, int* factors, int* count_ptr) {
    
    int root = (int)sqrt(num);
    printf("\nroot of %d: %d\n", num, root);
    int count = 1;

    factors[0] = 1;
    for (int i = 2; i <= root; i++) {
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

    int* count = (int*)malloc(sizeof(int));
    int* factors = (int*)malloc(sizeof(int) * num); // 할당 수를 num보다 줄일 수도 있을 것 같은데..
    findFactors(num, factors, count);

    printf("factors of %d: ", num);
    int sum = 0;
    for (int i = 0; i < *count; i++) {
        sum += factors[i];
        printf("%d ", factors[i]);
    }
    printf("\n");

    int result = 0;
    printf("sum: %d, num: %d\n", sum, num);
    result = sum - num;

    free(count);
    free(factors);

    return result;
}

void printPerfect(int num) {
    int result = 0;
    result = checkPerfect(num);

    if (result < 0) {
        printf("Deficient\n");
    } else if (result > 0) {
        printf("Abundunt\n");
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