#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OFFSET 4000

typedef struct {
    int count;
    int dup;
    int mode;
} MODE;

int main() {

    int N;
    scanf("%d", &N);

    int count[2*OFFSET+1] = {0,};

    int n;
    for (int i=0; i<N; i++) {
        scanf("%d", &n);
        count[n+OFFSET]++;
    }

    // mean
    int sum = 0;

    // median
    int mid_index = N / 2 + 1;
    int mid_count = 0;
    int mid_flag = 0;
    int median;

    // mode
    MODE *mode = (MODE *)malloc(sizeof(MODE));
    mode->count = mode->dup = 0;

    // range
    int min, max;
    char min_flag=0;

    for (int i=0; i<=2*OFFSET; i++) {
        // mean
        if (count[i]) sum += (i-OFFSET)*count[i];

        // median
        if (!mid_flag) {
            mid_count += count[i];
            if (mid_count >= mid_index) {
                median = i - OFFSET;
                mid_flag = 1;
            }
        }

        // mode
        if (mode->count < count[i]) {
            mode->count = count[i];
            mode->dup = 0;
            mode->mode = i-OFFSET;
        } else if (mode->count == count[i] && !mode->dup) {
            mode->dup = 1;
            mode->mode = i-OFFSET;
        }

        // range
        if (count[i]) {
            if (!min_flag) {
                min_flag = 1;
                min = i - OFFSET;
            }
            max = i - OFFSET;
        }
    }

    int mean = round((double)sum / N);

    printf("%d\n", mean);
    printf("%d\n", median);
    printf("%d\n", mode->mode);
    printf("%d\n", max-min);

    free(mode);

    return 0;
}
