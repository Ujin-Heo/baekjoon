#include <stdio.h>
#include <string.h>

int main() {
    char num_str[6];

    while(1) {
        scanf("%s", num_str);

        if (num_str[0] == '0') {
            break;
        }

        int palindrome = 1;
        int len = strlen(num_str);
        for (int i = 0; i < len/2; i++) {
            if (num_str[i] != num_str[len - i - 1]) {
                palindrome = 0;
                break;
            }
        }

        if (palindrome) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}