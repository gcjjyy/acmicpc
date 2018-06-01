#include <stdio.h>

int zero;
int one;

int fib(int n) {
    if(n == 1) { one++; return 1; }
    if(n == 0) { zero++; return 0; }
    
    return fib(n-1) + fib(n-2);
}

int main() {
    int T, N;
    scanf("%d", &T);
    while(T--) {
        zero = 0;
        one = 0;
        scanf("%d", &N);
        fib(N);
        printf("%d %d\n", zero, one);
    }
    return 0;
}
