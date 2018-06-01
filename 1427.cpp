#include <stdio.h>

long long N;
int C[10];

int main() {
    scanf("%lld", &N);
    while(N) {
        int m = N % 10;
        C[m]++;
        N /= 10;
    }

    for(int i = 9; i >= 0; --i) {
        if(C[i]) {
            for(int j = 0; j < C[i]; ++j) {
                printf("%d", i);
            }
        }
    }

    printf("\n");

    return 0;
}