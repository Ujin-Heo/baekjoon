#include <stdio.h>
#include <stdlib.h>
/*
int ascending(const void* a, const void* b) {
	int v1 = *(int*)a;
	int v2 = *(int*)b;

	return v1 - v2;

}

int main() {

	int N = 0;
	scanf("%d", &N);

	int* nums = (int*)malloc(sizeof(int) * N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &nums[i]);
	}
	qsort(nums, N, sizeof(int), ascending);

	int max = nums[N-1];

	int* primes = (int*)malloc(sizeof(int) * N);
	int prime_i = 0;

	for (int target = 2; target <= max; target++) {
		int isPrime = 1;
		for (int i = 0;i < prime_i;i++) {
			if (target % primes[i] == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			primes[prime_i] = target;
			prime_i += 1;
		}
	}

	int count = 0;
	int prime_j = 0;
	for (int i = 0;i < N;i++) {
		int num = nums[i];
		for (int j = prime_j;j < prime_i;j++) {
			if (num == primes[j]) {
				count++;
				prime_j = j;
				break;
			}
		}
	}

	printf("%d", count);

	return 0;
}
*/