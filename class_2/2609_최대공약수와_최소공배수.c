#include <stdio.h>
#include <stdlib.h>


int find_common_divisor(int n, int m) {
    int d = 2;
    int smaller = n <= m ? n : m;
    int found = 0;

    while (d <= smaller) {
        if (n % d == 0 && m % d == 0) {
            found = 1;
            break;
        };
        d++; // smaller 이하의 소수만 확인해야 효율적이긴 함. 시간 제한 넉넉해서 1씩 증가하게 구현해도 통과는 됨.
    }

    if (!found) {
        d = 1;
    }

    return d;
}

int main() {

    int N = 0, M = 0;
    scanf("%d %d", &N, &M);

    int gcd = 1, lcm = 0;

    int n = N, m = M;

    int d = 1;
    d = find_common_divisor(N, M);   
    while (d >= 2) {
        n /= d;
        m /= d;
        gcd *= d;
        // printf("d: %d, n: %d, m: %d\n", d, n, m);

        d = find_common_divisor(n, m);
    }
    lcm = gcd * n * m;

    printf("%d\n%d\n", gcd, lcm);

    return 0;  
}