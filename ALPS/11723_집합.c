#include <stdio.h>
#include <string.h>


void Add(int* bits, int x) {
    bits[x-1] = 1;
}

void Remove(int* bits, int x) {
    bits[x-1] = 0;
}

int Check(int* bits, int x) {
    return bits[x-1] == 1;
}

void Toggle(int* bits, int x) {
    if (bits[x-1] == 0) {
        bits[x-1] = 1;
    } else {
        bits[x-1] = 0;
    }
}

void All(int* bits) {
    for (int i = 0; i < 20; i++) {
        bits[i] = 1;
    }
}

void Empty(int* bits) {
    for (int i = 0; i < 20; i++) {
        bits[i] = 0;
    }
}

int main() {

    int M = 0;
    scanf("%d", &M);

    int bits[20] = {0, };

    char buffer[10] = {0, };
    for (int i = 0; i < M; i++) {
        scanf("%s", buffer);
        if (strcmp(buffer, "add") == 0) {
            int x = 0;
            scanf("%d", &x);
            Add(bits, x);
        } else if (strcmp(buffer, "remove") == 0) {
            int x = 0;
            scanf("%d", &x);
            Remove(bits, x);
        } else if (strcmp(buffer, "check") == 0) {
            int x = 0;
            scanf("%d", &x);
            printf("%d\n", Check(bits, x));
        } else if (strcmp(buffer, "toggle") == 0) {
            int x = 0;
            scanf("%d", &x);
            Toggle(bits, x);
        } else if (strcmp(buffer, "all") == 0) {
            All(bits);
        } else if (strcmp(buffer, "empty") == 0) {
            Empty(bits);
        }
    }

    return 0;
}
