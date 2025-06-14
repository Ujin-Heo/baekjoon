#include <stdio.h>
#include <string.h>

int main() {

    char word[101] = {0,};
    scanf("%s", word);

    char c = 'a';
    for (int i = 0; i < 26; i++) {
        int len = strlen(word);
        int index = -1;
        for (int i = 0; i < len; i++) {
            if (word[i] == c) {
                index = i;
                break;
            }
        }
        printf("%d ", index);
        c++;
    }

    return 0;
}