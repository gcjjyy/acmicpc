#include <stdio.h>

#define EXCEPT 1

int T, n;
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

    int a, b;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 2; i <= n >> 1; ++i) {
            if(!eratos[i] && !eratos[n - i]) {
                a = i;
                b = n - i;
            }
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}