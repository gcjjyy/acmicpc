#include <stdio.h>

int A, B, C;
int count[10];

int main() {
    scanf("%d %d %d", &A, &B, &C);

    int N = A*B*C;
    while(N > 0) {
        count[N%10]++;
        N /= 10;
    }

    for(int i = 0; i <= 9; ++i) printf("%d\n", count[i]);

    return 0;
}