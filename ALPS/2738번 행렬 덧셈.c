#include <stdio.h>
#include <malloc.h>
/*
int main() {

	int N = 0, M = 0;
	scanf("%d %d", &N, &M);

	int element = 0;

	int** A = (int**)malloc(sizeof(int*) * N);
	for (int row = 0;row < N;row++) {
		A[row] = (int*)malloc(sizeof(int) * M);
		for (int col = 0;col < M;col++) {
			scanf("%d", &element);
			A[row][col] = element;
		}
	}
	
	int** B = (int**)malloc(sizeof(int*) * N);
	for (int row = 0;row < N;row++) {
		B[row] = (int*)malloc(sizeof(int) * M);
		for (int col = 0;col < M;col++) {
			scanf("%d", &element);
			B[row][col] = element;
		}
	}

	for (int row = 0;row < N;row++) {
		for (int col = 0;col < M;col++) {
			printf("%d ", A[row][col] + B[row][col]);
		}
		printf("\n");
	}

	return 0;
}
*/