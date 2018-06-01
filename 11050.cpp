#include <stdio.h>

long long factorial(int n) {
    long long ret = 1;
    while(n) {
        ret *= n;
        n--;
    }
    return ret;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    printf("%lld\n", (factorial(N) / (factorial(K) * (factorial(N-K)))));
    return 0;
}
