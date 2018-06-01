#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    long long fact = 1;
    while(N) {
        fact *= N;
        N--;
    }
    printf("%lld\n", fact);
    return 0;
}
