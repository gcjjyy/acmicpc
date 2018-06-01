#include <stdio.h>

#define EXCEPT 1

int M, N;
char eratos[1000001];

int main() {
    scanf("%d %d", &M, &N);

    eratos[0] = EXCEPT;
    eratos[1] = EXCEPT;
    for(int i = 2; i <= N / 2; ++i) {
        if(eratos[i]) continue;
        int n = i * 2;
        while(n <= N) {
            eratos[n] = EXCEPT;
            n += i;
        }
    }

    for(int i = M; i <= N; ++i) {
        if(!eratos[i]) printf("%d\n", i);
    }

    return 0;
}