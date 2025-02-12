#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define YES 1
#define NO 0

int main() {

    int N = 0;
    scanf("%d", &N);
    
    char* ps = (char*)malloc(50);

    for (int i=0; i<N; i++) {
        char vps = YES;

        scanf("%s", ps);
        int len = strlen(ps);

        int top = 0;

        for (int i=0; i<len; i++) {

            char cur = ps[i];
            
            if (cur == '(') {
                top++;
            } else {
                if (top > 0) {
                    top--;
                } else {
                    vps = NO;
                    break;
                }
            }
        }

        if (top > 0) vps = NO;

        if (vps) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
    }

    free(ps);
}