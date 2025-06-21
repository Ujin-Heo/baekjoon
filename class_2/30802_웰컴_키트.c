#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);

    int t_ppl[6];
    for (int i = 0; i < 6; i++) {
        scanf("%d", &t_ppl[i]);
    }

    int T, P;
    scanf("%d %d", &T, &P);

    int t_sets[6] = {0, };
    int t_sum = 0;
    for (int i = 0; i < 6; i++) {
        t_sets[i] = (t_ppl[i] + T - 1) / T; // ceiling division of integer
        t_sum += t_sets[i];
    }

    int p_set = N / P;
    int p_single = N % P;

    printf("%d\n", t_sum);
    printf("%d %d", p_set, p_single);

    return 0;
}
