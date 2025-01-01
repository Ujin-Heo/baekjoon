#include <stdio.h>
#include <stdlib.h>
/*
int main() {

	int M = 0, N = 0;
	scanf("%d %d", &M, &N);

	int* primes = (int*)malloc(sizeof(int) * N);
	int prime_i = 0;

	for (int target = 2; target <= N; target++) {
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
			if (M <= target && target <= N) {
				printf("%d\n", target);
			}
		}
	}

	return 0;
}
*/