#include <stdio.h>

int A[15][15];

int main() {
    int T, k, n;

    for(int i = 0; i <= 14; ++i) {
        A[0][i] = i;
    }
    for(int i = 0; i < 14; ++i) {
        for(int j = 1; j <= 14; ++j) {
            for(int k = j; k <= 14; ++k) {
                A[i + 1][k] += A[i][j];
            }
        }
    }

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &k, &n);
        printf("%d\n", A[k][n]);
    }
    return 0;
}