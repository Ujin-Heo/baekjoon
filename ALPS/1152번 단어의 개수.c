	#include <stdio.h>
	#include <stdlib.h>
	/*
	int main() {

		char c = 0;
		char c_before = 0;
		int count = 0;

		// 첫번째가 공백일 때 카운트 방지
		scanf("%c", &c);
		c_before = c;

		while (1) {
			scanf("%c", &c);
			if (c == ' ') {
				count++;
				//printf("count: %d\n", count);
			}
			if (c == 10) {
				if (c_before != ' ') count++;
				break;
			}
			//printf("%d\n", c);
			c_before = c;
		}

		printf("%d", count);
	}
	*/

	// 다른풀이: gets를 쓰면 공백까지 하나의 문자열로 통째로 가져올 수 있음.
	//char arr[1000001] = { '\0' };
	//gets(arr);