	#include <stdio.h>
	#include <stdlib.h>
	/*
	int main() {

		char c = 0;
		char c_before = 0;
		int count = 0;

		// ù��°�� ������ �� ī��Ʈ ����
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

	// �ٸ�Ǯ��: gets�� ���� ������� �ϳ��� ���ڿ��� ��°�� ������ �� ����.
	//char arr[1000001] = { '\0' };
	//gets(arr);