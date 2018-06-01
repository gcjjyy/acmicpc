#include <stdio.h>
#define MOD 10000000000

int main() {
    int N;
    scanf("%d", &N);
    long long fact = 1;
    int count = 0;
    while(N) {
        fact *= N;
        fact %= MOD;
        N--;
        if(fact % 10 == 0) {
            count++;
            fact /= 10;
        }
    }
    printf("%d\n", count);
    return 0;
}
