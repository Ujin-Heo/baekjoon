#include <stdio.h>

//3: 111, 12, 21, 3 -> 4

int get_num_of_ways(int N) {
    int n;

    if (N==1) return 1;
    if (N==2) return 2;
    if (N==3) return 3;

    

    return n;
}

int main() {

    int T;
    scanf("%d", &T);

    int N;
    for (int i=0; i<T; i++) {
        scanf("%d", &N);
        printf("%d\n", get_num_of_ways(N));
    }


    return 0;
}