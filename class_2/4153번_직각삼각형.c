#include <stdio.h>
#include <stdlib.h>
/*
int descending(const void* a, const void* b) {
	int v1 = *(int*)a;
	int v2 = *(int*)b;

	if (v1 < v2) {
		return 1;
	}
	else if (v1 > v2) {
		return -1;
	}
	else {
		return 0;
	}

	// return v2 - v1;

}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Descend_Sort(int* sides) {
	for (int i = 0;i < 3;i++) {
		int* max = sides + i;
		for (int j = i + 1;j < 3;j++) {
			if (*max < sides[j]) {
				max = sides + j;
			}
		}
		Swap(max, sides + i);
	}
}

int main() {

	int* sides = (int*)malloc(sizeof(int) * 3);
	for (int i = 0;i < 3;i++) {
		scanf("%d", &sides[i]);
	}
	while (sides[0] != 0) {
		//qsort(sides, 3, sizeof(int), &descending); // &¾ø¾îµµ µÊ.

		Descend_Sort(sides);

		if (sides[0] * sides[0] == sides[1] * sides[1] + sides[2] * sides[2]) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
		for (int i = 0;i < 3;i++) {
			scanf("%d", &sides[i]);
		}
	}

}
*/