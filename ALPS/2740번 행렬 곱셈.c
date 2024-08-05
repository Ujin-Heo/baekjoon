#include <stdio.h>
#include <malloc.h>
/*
int main() {

	int N = 0, M = 0, K = 0;
	int element = 0;

	scanf("%d %d", &N, &M);
	int** A = (int**)malloc(sizeof(int*) * N);
	for (int row = 0;row < N;row++) {
		A[row] = (int*)malloc(sizeof(int) * M);
		for (int col = 0;col < M;col++) {
			scanf("%d", &element);
			A[row][col] = element;
		}
	}

	scanf("%d %d", &M, &K);
	int** B = (int**)malloc(sizeof(int*) * M);
	for (int row = 0;row < M;row++) {
		B[row] = (int*)malloc(sizeof(int) * K);
		for (int col = 0;col < K;col++) {
			scanf("%d", &element);
			B[row][col] = element;
		}
	}

	for (int row = 0;row < N;row++) {
		for (int col = 0;col < K;col++) {
			int dot_product = 0;
			// index == col_A == row_B
			for (int index = 0;index < M;index++) {
				dot_product += A[row][index] * B[index][col];
			}
			printf("%d ", dot_product);
		}
		printf("\n");
	}

	for (int row = 0;row < N;row++) {
		free(A[row]);
	}
	free(A);

	for (int row = 0;row < M;row++) {
		free(B[row]);
	}
	free(B);
}
*/