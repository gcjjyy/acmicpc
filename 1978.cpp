#include <stdio.h>

int N, A;
int count = 0;
int prime;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A);

        prime = 0;
        for(int j = 1; j <= A; ++j) {
            if(A%j == 0) prime++;
        }

        if(prime == 2) count++;
    }

    printf("%d\n", count);

    return 0;
}