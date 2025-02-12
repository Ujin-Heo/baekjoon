#include <stdio.h>
#include <stdlib.h>
/*
int main() {

	int N = 0;
	scanf("%d", &N);

	float* scores = (float*)malloc(sizeof(float) * N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &scores[i]);
	}

	float max = scores[0];
	for (int i = 1;i < N;i++) {
		if (max < scores[i]) {
			max = scores[i];
		}
	}

	float sum = 0;
	for (int i = 0;i < N;i++) {
		scores[i] = scores[i] / max * 100;
		sum += scores[i];
	}

	printf("%f", sum / N);

}
*/