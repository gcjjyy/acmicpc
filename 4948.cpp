#include <stdio.h>

#define EXCEPT 1

int N;
char eratos[500000];

int main() {
    eratos[0] = EXCEPT;
    eratos[1] = EXCEPT;
    for(int i = 2; i <= 250000; ++i) {
        if(eratos[i]) continue;
        int n = i * 2;
        while(n < 500000) {
            eratos[n] = EXCEPT;
            n += i;
        }
    }

    while(true) {
        scanf("%d", &N);
        if(N == 0) break;
        int count = 0;
        for(int i = N + 1; i <= (N << 1); ++i) {
            if(!eratos[i]) count++;
        }

        printf("%d\n", count);
    }

    return 0;
}