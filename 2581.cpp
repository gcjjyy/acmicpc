#include <stdio.h>

int M, N;
int min = 20000;
int prime;
int sum;

int main() {
    scanf("%d %d", &M, &N);
    sum = 0;
    for(int i = M; i <= N; ++i) {
        prime = 0;
        for(int j = 1; j <= i; ++j) {
            if(i%j == 0) prime++;
        }

        if(prime == 2) {
            if(i < min) min = i;
            sum += i;
        }
    }

    if(sum == 0) printf("-1\n");
    else {
        printf("%d\n", sum);
        printf("%d\n", min);
    }

    return 0;
}